#ifndef LINE_H
#define LINE_H

#include "../config.h"
#include "vec3.h"
#include "relations.h"

namespace Math
{
	class PUNK_ENGINE Line3D
	{
		vec3 m_origin;
		vec3 m_destination;
		vec3 m_direction;
	public:       

		Line3D();
		Line3D(const vec3& org, const vec3& dir);
		const vec3 PointAt(float t) const;		
		
		const vec3& GetDirection() const { return m_direction; }
		const vec3& GetOrigin() const { return m_origin; }
		const vec3& GetDestination() const { return m_destination; }

		void SetOrigin(const vec3& origin);
		void SetDestination(const vec3& destination);
		float SegmentLength() const;

		Line3D& SetOriginDirection(const vec3& org, const vec3& dir);
		Line3D& SetOriginDestination(const vec3& org, const vec3& dst);
	};
}
#endif // LINE_H
