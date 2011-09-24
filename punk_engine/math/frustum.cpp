#include "frustum.h"
#include "math.h"

namespace Math
{
	Frustum::Frustum()
	{
		m_fov = PI/4.0f;
		m_zfar = 100.0f;
		m_znear = 0.1f;
		m_aspect = 4.0f / 3.0f;

		m_position = vec3(0,0,-5);
		m_target = vec3(0,0,0);
		m_up = vec3(0,1,0);
		m_direction = vec3(0,0,1);

		m_type = CAMERA_FREE;

		UpdateMatrix();
	}

	void Frustum::CalculatePlanes()
	{
		float tang = tanf(m_fov / 2.0f);
		m_near_height = m_znear * tang;
		m_near_width = m_near_height * m_aspect;
		m_far_height = m_zfar * tang;
		m_far_width = m_far_height * m_aspect;	

		mat4 m = m_view_matrix;//.Inversed();

		vec3 x = m.GetColumn(0).XYZ().Normalized();
		vec3 y = m.GetColumn(1).XYZ().Normalized();
		vec3 z = m.GetColumn(2).XYZ().Normalized();
		vec3 p = m.TranslationPart();

		vec3 near_center = p - z * m_znear;
		vec3 far_center = p - z * m_zfar;

		vec3 near_top_left = near_center + y * m_near_height - x * m_near_width;
		vec3 near_top_right = near_center + y * m_near_height + x * m_near_width;
		vec3 near_bottom_left = near_center - y * m_near_height - x * m_near_width;
		vec3 near_bottom_right = near_center - y * m_near_height + x * m_near_width;

		vec3 far_top_left = far_center + y * m_far_height - x * m_far_width;
		vec3 far_top_right = far_center + y * m_far_height + x * m_far_width;
		vec3 far_bottom_left = far_center - y * m_far_height - x * m_far_width;
		vec3 far_bottom_right = far_center - y * m_far_height + x * m_far_width;

		m_planes[PLANE_TOP].MakeFromPoints(near_top_right, near_top_left, far_top_left);
		m_planes[PLANE_BOTTOM].MakeFromPoints(near_bottom_left, near_bottom_right, far_bottom_right);
		m_planes[PLANE_LEFT].MakeFromPoints(near_top_left, near_bottom_left, far_bottom_left);
		m_planes[PLANE_RIGHT].MakeFromPoints(near_bottom_right, near_top_right, far_top_right);
		m_planes[PLANE_NEAR].MakeFromPoints(near_top_left, near_top_right, near_bottom_right);
		m_planes[PLANE_FAR].MakeFromPoints(far_top_right, far_top_left, far_bottom_left);
	}

	void Frustum::SetPosition(const vec3& position)
	{
		m_position = position;

		UpdateMatrix();
	}

	Frustum::Classification Frustum::BoxInFrustum(const BoundingBox& bbox) const
	{
		int in, out;
		Classification result = INSIDE;

		const vec3* point = bbox.TransformedPoints();

		for (int i = 0; i < 6; i++)
		{
			in = 0; out = 0;
			for (int j = 0; j < 8; j++)
			{
				if (m_planes[i].Distance(point[j]) < 0)
					out++;
				else
					in++;
			}

			if (!in)
				return OUTSIDE;
			else if (out)
				result = INTERSECT;
		}
		return result;
	}

	void Frustum::UpdateMatrix()
	{
		if (m_type == CAMERA_TARGET)
			m_view_matrix = mat4::CreateTargetCameraMatrix(m_position, m_target, m_up);
		else if (m_type == CAMERA_FREE)
			m_view_matrix = mat4::CreateTargetCameraMatrix(m_position, m_position + m_direction, m_up);
		else
			throw MathError(L"Unknown frustum type in update matrix");

		m_projection_matrix = mat4::CreatePerspectiveProjection(m_fov, m_aspect, m_znear, m_zfar);
		m_projection_view_matrix =  m_projection_matrix*m_view_matrix;

		CalculatePlanes();
	}

	void Frustum::SetPositionAndDirection(const vec3& pos, const vec3& dir, const vec3& up)
	{
		m_position = pos;
		m_direction = dir;
		m_up = up;
		m_type = CAMERA_FREE;

		UpdateMatrix();
	}

	void Frustum::SetPositionAndTarget(const vec3& pos, const vec3& target, const vec3& up)
	{
		m_position = pos;
		m_target = target;
		m_up = up;
		m_type = CAMERA_TARGET;

		UpdateMatrix();
	}

	void Frustum::SetProperties(float fov, float aspect, float znear, float zfar)
	{
		m_fov = fov;
		m_aspect = aspect;
		m_znear = znear;
		m_zfar = zfar;

		UpdateMatrix();
	}

	const mat4& Frustum::GetProjectionMatrix() const
	{
		return m_projection_matrix;
	}

	const mat4& Frustum::GetViewMatrix() const
	{
		return m_view_matrix;
	}

	const mat4& Frustum::GetViewProjectionMatrix() const
	{
		return m_projection_view_matrix;
	}

	const vec3& Frustum::GetPosition() const
	{
		return m_position;
	}
}