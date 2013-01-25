#ifndef _H_PUNK_OPENGL_SHADER_POLICY
#define _H_PUNK_OPENGL_SHADER_POLICY

#include <iostream>
#include "../render/render_state.h"
#include "../../system/smart_pointers/proxy.h"
#include "dummy_render_context_policy.h"
#include "shaders/shaders.h"
#include "../extensions.h"
#include "../../math/mat4.h"
#include "../../math/vec4.h"
#include "../../system/poolable.h"
#include "../../virtual/data/data.h"
#include "../../virtual/skinning/skinning.h"
#include "../../virtual/terrain/module.h"

namespace OpenGL
{
	struct NoShader {};

	template<class VertexShader, class FragmentShader, class GeometryShader> class RenderContextPolicy;


	/**********************************************************************************************/
	/*			POSITION TEXTURE 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderTransformTextured3D, FragmentShaderSolidTextured, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uProjViewWorld;
		unsigned uDiffuseColor;
		unsigned uDiffuseMap;
		unsigned uTextureMatrix;

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderTransformTextured3D);
			m_fragment_shader.reset(new FragmentShaderSolidTextured);
			Init();
		}

		virtual ~RenderContextPolicy()
		{
		}

		virtual void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}
		}

		virtual void InitUniforms()
		{
			uProjViewWorld = GetUniformLocation("uProjViewWorld");
			uDiffuseColor = GetUniformLocation("uDiffuseColor");
			uDiffuseMap = GetUniformLocation("uDiffuseMap");
			uTextureMatrix = GetUniformLocation("uTextureMatrix");
		}

		virtual void BindParameters(const CoreState& params)
		{									
			const Math::mat4 proj_view_world = params.m_projection * params.m_view * params.m_local;
			SetUniformMatrix4f(uProjViewWorld, &(proj_view_world[0]));
			SetUniformVector4f(uDiffuseColor, &(params.m_diffuse_color[0]));
			SetUniformInt(uDiffuseMap, params.m_diffuse_slot_0);
			SetUniformMatrix2f(uTextureMatrix, &params.m_texture_matrix[0]);
		}
		
		virtual Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE;
		}

		virtual void Begin()
		{
			/*
				Begin();
				BindParameters()
				***
				render();
				***
				BindParameters()
				render();
				End();
			*/

			Init();
			AbstractRenderPolicy::Begin();
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			
		}		
	};

	/**********************************************************************************************/
	/*			POSITION SOLID 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderSolid, FragmentShaderSolid, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uProjViewWorld;
		unsigned uDiffuseColor;

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderSolid);
			m_fragment_shader.reset(new FragmentShaderSolid);
			Init();
		}

		virtual ~RenderContextPolicy()
		{
		}

		virtual void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}
		}

		virtual void InitUniforms()
		{
			uProjViewWorld = GetUniformLocation("uProjViewWorld");
			uDiffuseColor = GetUniformLocation("uDiffuseColor");
		}

		virtual void BindParameters(const CoreState& params)
		{			
			const Math::mat4 proj_view_world = params.m_projection * params.m_view * params.m_local;
			SetUniformMatrix4f(uProjViewWorld, &proj_view_world[0]);
			SetUniformVector4f(uDiffuseColor, &(params.m_diffuse_color[0]));
			
			glLineWidth(params.m_line_width);

			if (params.m_wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}			
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}
		}
		
		virtual Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			
		}		
	};

	/**********************************************************************************************/
	/*			BUMP MAPPING 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderBump, FragmentShaderBump, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uWorld;
		unsigned uView;
		unsigned uProj;
		unsigned uNormalMatrix;
		unsigned uLightPosition;
		unsigned uAmbient;
		unsigned uSpecular;
		unsigned uDiffuse;
		unsigned uSpecularPower;
		unsigned uDiffuseMap;
		unsigned uNormalMap;

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderBump);
			m_fragment_shader.reset(new FragmentShaderBump);
			Init();
		}

		void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}			
		}

		void InitUniforms()
		{
			uWorld = GetUniformLocation("uWorld");
			uView = GetUniformLocation("uView");
			uProj = GetUniformLocation("uProj");
			uNormalMatrix = GetUniformLocation("uNormalMatrix");
			uLightPosition = GetUniformLocation("uLightPosition");
			uAmbient = GetUniformLocation("uAmbient");
			uSpecular = GetUniformLocation("uSpecular");
			uDiffuse = GetUniformLocation("uDiffuse");
			uSpecularPower = GetUniformLocation("uSpecularPower");
			uDiffuseMap = GetUniformLocation("uDiffuseMap");
			uNormalMap = GetUniformLocation("uNormalMap");
		}

		void BindParameters(const CoreState& pparams)
		{									
			//Math::mat4 p = Math::mat4::CreatePerspectiveProjection(Math::PI / 4.0f, 4.0f / 3.0f, 0.1f, 1000.0f);
			//Math::mat4 p2 = pparams.m_camera->GetProjectionMatrix();
			//Math::mat4 v = Math::mat4::CreateTargetCameraMatrix(Math::vec3(0, 5, 5), Math::vec3(0,0,0), Math::vec3(0,1,0));
			//Math::mat4 w = Math::mat4::CreateIdentity();			
			Math::mat3 normal_matrix = (pparams.m_camera->GetViewMatrix() * pparams.m_local).Inversed().Transposed().RotationPart();
			SetUniformMatrix4f(uWorld, &pparams.m_local[0]);
			//SetUniformMatrix4f(uWorld, &w[0]);
			SetUniformMatrix4f(uView, &pparams.m_camera->GetViewMatrix()[0]);
			//SetUniformMatrix4f(uView, &v[0]);
			SetUniformMatrix4f(uProj, &pparams.m_camera->GetProjectionMatrix()[0]);
			//SetUniformMatrix4f(uProj, &p[0]);
			SetUniformMatrix3f(uNormalMatrix, &normal_matrix[0]);
			if (!pparams.m_current_light_set.empty())
				SetUniformVector3f(uLightPosition, &pparams.m_current_light_set[0]->GetPosition()[0]);
			else
			{
				Math::vec3 v(0,0,0);
				SetUniformVector3f(uLightPosition, &v[0]);
			}

			SetUniformVector4f(uAmbient, &(Math::vec4(pparams.m_current_material->GetAmbient()))[0]);
			SetUniformVector4f(uSpecular, &pparams.m_current_material->GetSpecularColor()[0]);
			SetUniformVector4f(uDiffuse, &pparams.m_current_material->GetDiffuseColor()[0]);
			SetUniformFloat(uSpecularPower, pparams.m_current_material->GetSpecularFactor());
			SetUniformInt(uDiffuseMap, pparams.m_diffuse_slot_0);
			SetUniformInt(uNormalMap, pparams.m_normal_slot);		
			if (pparams.m_wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}			
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}
		}
		
		Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE|Utility::COMPONENT_BITANGENT|Utility::COMPONENT_TANGENT|Utility::COMPONENT_NORMAL;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();

			glEnable(GL_DEPTH_TEST);
			//CHECK_GL_ERROR(L"Unable to enable depth test");
			//glDepthFunc(GL_LESS);
			//CHECK_GL_ERROR(L"Unable to set less depth function");
			//glDepthMask(GL_TRUE);
			//CHECK_GL_ERROR(L"Unable to enable depth mask");
			//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			//CHECK_GL_ERROR(L"Unable to set polygon mode");
			/*glEnable(GL_BLEND);
			CHECK_GL_ERROR(L"Unable to enable blend");
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			CHECK_GL_ERROR(L"Unable to set blend func");
			glEnable(GL_CULL_FACE);
			CHECK_GL_ERROR(L"Unable to enable cull facing");
			glCullFace(GL_FRONT);
			CHECK_GL_ERROR(L"Unable to set cull face mode");*/
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			

			//glEnable(GL_DEPTH_TEST);			
			//glDepthFunc(GL_LESS);
			//glDepthMask(GL_TRUE);
			//glEnable(GL_BLEND);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);			
		}	
	};

	/**********************************************************************************************/
	/*			GRASS RENDER 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderGrass, FragmentShaderGrass, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uProjView;
		unsigned uHeightMap;
		unsigned uPosition;
		unsigned uTime;
		unsigned uWindStrength;
		unsigned uWindDirection;
		unsigned uDiffuseColor;
		unsigned uDiffuseMap;

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderGrass);
			m_fragment_shader.reset(new FragmentShaderGrass);
			Init();
		}

		void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}
		}

		void InitUniforms()
		{
			uProjView = GetUniformLocation("uProjView");
			uHeightMap = GetUniformLocation("uHeightMap");
			uPosition = GetUniformLocation("uPosition");
			uTime = GetUniformLocation("uTime");
			uWindStrength = GetUniformLocation("uWindStrength");
			uWindDirection = GetUniformLocation("uWindDirection");
			uDiffuseColor = GetUniformLocation("uDiffuseColor");
			uDiffuseMap = GetUniformLocation("uDiffuseMap");
		}

		void BindParameters(const CoreState& pparams)
		{	
			//const PolicyParameters& params = static_cast<const PolicyParameters&>(pparams);
			//SetUniformMatrix4f(uProjView, &params.m_proj_view[0]);
			//SetUniformVector4f(uDiffuseColor, &params.m_diffuse_color[0]);
			//SetUniformVector3f(uPosition, &params.m_position[0]);
			//SetUniformFloat(uTime, params.m_time);
			//SetUniformFloat(uWindStrength, params.m_wind_strength);
			//SetUniformVector3f(uWindDirection, &params.m_wind_direction[0]);
			//SetUniformInt(uDiffuseMap, 0);
			//SetUniformInt(uHeightMap, 1);	
		}
		
		Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			
		}			
	};

	/**********************************************************************************************/
	/*			GUI RENDER 2D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderGUI, FragmentShaderGUI, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uProjViewWorld;
		unsigned uDiffuseColor;
		unsigned uTextureMatrix;
		unsigned uTextColor;
		unsigned uNoDiffuseTexture;
		unsigned uDiffuseMap;
		unsigned uTextMap;

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderGUI);
			m_fragment_shader.reset(new FragmentShaderGUI);
			Init();
		}

		void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}
		}

		void InitUniforms()
		{
			uProjViewWorld = GetUniformLocation("uProjViewWorld");
			uDiffuseColor = GetUniformLocation("uDiffuseColor");
			uTextColor = GetUniformLocation("uTextColor");
			uNoDiffuseTexture = GetUniformLocation("uNoDiffuseTexture");
			uDiffuseMap = GetUniformLocation("uDiffuseMap");
			uTextMap = GetUniformLocation("uTextMap");
			uTextureMatrix = GetUniformLocation("uTextureMatrix");
		}

		void BindParameters(const CoreState& pparams)
		{									
			Math::mat4 proj_view_world = pparams.m_projection * pparams.m_view * pparams.m_local;
			SetUniformMatrix4f(uProjViewWorld, &proj_view_world[0]);
			SetUniformMatrix2f(uTextureMatrix, &pparams.m_texture_matrix[0]);
			SetUniformVector4f(uDiffuseColor, &pparams.m_diffuse_color[0]);
			SetUniformVector4f(uTextColor, &pparams.m_text_color[0]);
			SetUniformVector4f(uNoDiffuseTexture, &pparams.m_no_diffuse_texture_color[0]);
			SetUniformInt(uDiffuseMap, pparams.m_diffuse_slot_0);
			SetUniformInt(uTextMap, pparams.m_text_slot);
			if (pparams.m_wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}			
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}

			if (pparams.m_blending)
			{
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else
			{
				glDisable(GL_BLEND);
			}
		}
		
		Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			
		}		
	};

	/**********************************************************************************************/
	/*			TERRAIN RENDER 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderTerrain, FragmentShaderTerrain, NoShader> : public AbstractRenderPolicy
	{	
		unsigned uWorld;
		unsigned uView;
		unsigned uProjection;
		unsigned uProjViewWorld;
		unsigned uNormalTransform;
		unsigned ui;
		unsigned uj;
		unsigned uViewSize;
		unsigned uHeightMapUniform;
		unsigned uScale;
		unsigned uPosition;
		unsigned uLevel;
		unsigned uNormalMapUniform;
		unsigned uDiffuseMapUniform1;
		unsigned uDiffuseMapUniform2;
		unsigned uDiffuseColor;
		unsigned uLightDirection;
		unsigned uTerrainPosition;
		unsigned uSlice;
	public:

		//struct PolicyParameters : public AbstractRenderPolicyParameters, public System::Poolable<PolicyParameters>
		//{
		//	Math::mat4 m_world;
		//	Math::mat4 m_view;
		//	Math::mat4 m_proj;
		//	Math::mat4 m_proj_view_world;
		//	Math::mat3 m_normal_tranform;
		//	Math::vec4 m_diffuse_color;
		//	Math::vec2 m_position;
		//	Math::vec3 m_light_position;
		//	Math::vec3 m_light_direction;
		//	float m_vert_scale;
		//	float m_level;
		//	unsigned m_i;
		//	unsigned m_j;
		//	int m_height_map_texture;
		//	int m_diffuse_map_1_texture;
		//	int m_diffuse_map_2_texture;
		//};

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderTerrain);
			m_fragment_shader.reset(new FragmentShaderTerrain);
			Init();
		}

		void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}
		}

		void InitUniforms()
		{
			uWorld = GetUniformLocation("uWorld");
			uView = GetUniformLocation("uView");
			uProjection = GetUniformLocation("uProjection");
			uProjViewWorld = GetUniformLocation("uProjViewWorld");
			uNormalTransform = GetUniformLocation("uNormalTransform");
			ui = GetUniformLocation("ui");
			uj = GetUniformLocation("uj");
			uHeightMapUniform = GetUniformLocation("uHeightMapUniform");
			uScale = GetUniformLocation("uScale");
			uPosition = GetUniformLocation("uPosition");
			uLevel = GetUniformLocation("uLevel");
			uNormalMapUniform = GetUniformLocation("uNormalMapUniform");
			uDiffuseMapUniform1 = GetUniformLocation("uDiffuseMapUniform1");
			uDiffuseMapUniform2 = GetUniformLocation("uDiffuseMapUniform2");
			uDiffuseColor = GetUniformLocation("uDiffuseColor");
			uLightDirection = GetUniformLocation("uLightDirection");
			uViewSize = GetUniformLocation("uViewSize");
			uTerrainPosition = GetUniformLocation("uTerrainPosition");
			uSlice = GetUniformLocation("uSlice");
		}

		void BindParameters(const CoreState& pparams)
		{										
			Math::mat4 proj_view_world = pparams.m_camera->GetProjectionMatrix() * pparams.m_camera->GetViewMatrix() * pparams.m_local;
			Math::mat3 normal_matrix = (pparams.m_camera->GetViewMatrix() * pparams.m_local).Inversed().Transposed().RotationPart();

			SetUniformMatrix4f(uProjViewWorld, &proj_view_world[0]);
			SetUniformMatrix4f(uWorld, &pparams.m_local[0]);
			SetUniformMatrix4f(uView, &pparams.m_camera->GetViewMatrix()[0]);
			SetUniformMatrix4f(uProjection, &pparams.m_camera->GetProjectionMatrix()[0]);
			SetUniformMatrix3f(uNormalTransform, &normal_matrix[0]);
			SetUniformInt(uSlice, pparams.m_terrain_slices);

			if (!pparams.m_current_light_set.empty())
				SetUniformVector3f(uLightDirection, &pparams.m_current_light_set[0]->GetPosition().Normalized()[0]);
			else
			{
				Math::vec3 v(1,1,0);
				SetUniformVector3f(uLightDirection, &v.Normalized()[0]);
			}

			if (pparams.m_current_material.IsValid())
				SetUniformVector4f(uDiffuseColor, &pparams.m_current_material->GetDiffuseColor()[0]);
			else
			{
				Math::vec4 v(1,1,1,1);
				SetUniformVector4f(uDiffuseColor, &v[0]);
			}
			SetUniformVector2f(uPosition, &pparams.m_terran_position[0]);
			SetUniformInt(uHeightMapUniform, pparams.m_height_map_slot);
			SetUniformInt(uDiffuseMapUniform1, pparams.m_diffuse_slot_0);
			SetUniformInt(uDiffuseMapUniform2, pparams.m_diffuse_slot_1);
			SetUniformFloat(uLevel, float(pparams.m_terrain_level));
			SetUniformInt(ui, pparams.m_terrain_i);
			SetUniformInt(uj, pparams.m_terrain_j);
			SetUniformInt(uViewSize, pparams.m_terrain_observer->GetTerrainView()->GetViewSize());
			SetUniformFloat(uScale, pparams.m_current_terrain->GetHeightScale());			
			SetUniformVector2f(uTerrainPosition, &pparams.m_terrain_observer->GetTerrainView()->GetPosition()[0]);

			if (pparams.m_wireframe)
			{
				glLineWidth(pparams.m_line_width);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}			
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				CHECK_GL_ERROR(L"Can't change polygon mode");
			}
		}
		
		Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE|Utility::COMPONENT_NORMAL|Utility::COMPONENT_FLAG;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			
		}	
	};

	
	/**********************************************************************************************/
	/*			SKINNING 3D
	/**********************************************************************************************/
	template<> class RenderContextPolicy<VertexShaderSkinning, FragmentShaderSkinning, NoShader> : public AbstractRenderPolicy
	{	
		static const int MAX_BONES = 64;

		unsigned uWorld;
		unsigned uView;
		unsigned uProj;
		unsigned uMeshMatrix;
		unsigned uMeshMatrixInversed;
		unsigned uNormalMatrix;
		unsigned uProjViewWorld;
		unsigned uViewWorld;
		unsigned uLightPosition;
		unsigned uBones[64];
		unsigned uAmbient;
		unsigned uSpecular;
		unsigned uDiffuse;
		unsigned uSpecularPower;
		unsigned uDiffuseMap;
		unsigned uNormalMap;

	public:

		//struct PolicyParameters : public AbstractRenderPolicyParameters, public System::Poolable<PolicyParameters>
		//{
		//	Math::mat4 m_world;
		//	Math::mat4 m_view;
		//	Math::mat4 m_proj;
		//	Math::mat4 m_mesh_matrix;
		//	Math::mat4 m_mesh_matrix_inversed;
		//	Math::mat3 m_normal_matrix;
		//	Math::mat4 m_proj_view_world;
		//	Math::mat4 m_view_world;
		//	Math::vec3 m_light_position;
		//	Math::mat4 m_bone[MAX_BONES];
		//	Math::vec4 m_ambient;
		//	Math::vec4 m_specular;
		//	Math::vec4 m_diffuse;			
		//	float m_specular_power;
		//	unsigned m_diffuse_texture;
		//	unsigned m_normal_texture;
		//};

	public:

		RenderContextPolicy()
		{
			m_vertex_shader.reset(new VertexShaderSkinning);
			m_fragment_shader.reset(new FragmentShaderSkinning);
			Init();
		}

		void Init()
		{
			if (m_was_modified || !m_program)
			{
				AbstractRenderPolicy::Init();
				InitUniforms();
			}			
		}

		void InitUniforms()
		{
			uWorld = GetUniformLocation("uWorld");
			uView = GetUniformLocation("uView");
			uProj = GetUniformLocation("uProj");
			uMeshMatrix = GetUniformLocation("uMeshMatrix");
			uMeshMatrixInversed = GetUniformLocation("uMeshMatrixInversed");
			uNormalMatrix = GetUniformLocation("uNormalMatrix");
			uProjViewWorld = GetUniformLocation("uProjViewWorld");
			uViewWorld = GetUniformLocation("uViewWorld");
			uLightPosition = GetUniformLocation("uLightPosition");
			for (int i = 0; i < MAX_BONES; ++i)
			{
				char buf[128];
				sprintf_s<128>(buf, "uBones[%d]", i);
				uBones[i] = GetUniformLocation(buf);
			}
			uAmbient = GetUniformLocation("uAmbient");
			uSpecular = GetUniformLocation("uSpecular");
			uDiffuse = GetUniformLocation("uDiffuse");
			uSpecularPower = GetUniformLocation("uSpecularPower");
			uDiffuseMap = GetUniformLocation("uDiffuseMap");
			uNormalMap = GetUniformLocation("uNormalMap");
		}

		void BindParameters(const CoreState& pparams)
		{							
			Math::mat4 mesh_matrix = Math::mat4::CreateIdentity();
			Math::mat4 view_world = pparams.m_camera->GetViewMatrix() * pparams.m_local;
			Math::mat4 proj_view_world = pparams.m_camera->GetProjectionMatrix() * pparams.m_camera->GetViewMatrix() * pparams.m_local;
			Math::mat3 normal_matrix = (pparams.m_camera->GetViewMatrix() * pparams.m_local).Inversed().Transposed().RotationPart();
			SetUniformMatrix4f(uWorld, &pparams.m_armature_world[0]);			
			SetUniformMatrix4f(uView, &pparams.m_camera->GetViewMatrix()[0]);			
			SetUniformMatrix4f(uProj, &pparams.m_camera->GetProjectionMatrix()[0]);			
			SetUniformMatrix4f(uMeshMatrix, &mesh_matrix[0]);//pparams.m_mesh_matrix[0]);
			SetUniformMatrix4f(uMeshMatrixInversed, &mesh_matrix[0]);//pparams.m_mesh_matrix.Inversed()[0]);
			SetUniformMatrix3f(uNormalMatrix, &normal_matrix[0]);
			if (!pparams.m_current_light_set.empty())
				SetUniformVector3f(uLightPosition, &pparams.m_current_light_set[0]->GetPosition()[0]);
			else
			{
				Math::vec3 v(0,0,0);
				SetUniformVector3f(uLightPosition, &v[0]);
			}
			SetUniformVector4f(uAmbient, &(Math::vec4(pparams.m_current_material->GetAmbient()))[0]);
			SetUniformVector4f(uSpecular, &pparams.m_current_material->GetSpecularColor()[0]);
			SetUniformVector4f(uDiffuse, &pparams.m_current_material->GetDiffuseColor()[0]);
			SetUniformFloat(uSpecularPower, pparams.m_current_material->GetSpecularFactor());
			SetUniformInt(uDiffuseMap, pparams.m_diffuse_slot_0);
			SetUniformInt(uNormalMap, pparams.m_normal_slot);				
			SetUniformMatrix4f(uProjViewWorld, &proj_view_world[0]);
			SetUniformMatrix4f(uViewWorld, &view_world[0]);
			for (int i = 0; i < pparams.m_armature->GetBonesCount(); ++i)
			{
				const Virtual::Bone* bone = pparams.m_armature->GetBoneByIndex(i);
				Math::mat4 m;
				//out_message() << bone->GetName() << ": " << bone->GetAnimatedGlobalMatrix().ToString() << std::endl;
				//SetUniformMatrix4f(uBones[i], &(m[0]));
				//SetUniformMatrix4f(uBones[i], &(bone->GetAnimatedGlobalMatrix())[0]);
				SetUniformMatrix4f(uBones[i], &(/*pparams.m_mesh_matrix_local.Inversed() **/ bone->GetAnimatedGlobalMatrix() * pparams.m_mesh_matrix_local)[0]);
			}
		}
		
		Utility::VertexAttributes GetRequiredAttributesSet() const 
		{
			return Utility::COMPONENT_POSITION|Utility::COMPONENT_TEXTURE|Utility::COMPONENT_BITANGENT|Utility::COMPONENT_TANGENT|Utility::COMPONENT_NORMAL|Utility::COMPONENT_BONE_WEIGHT|Utility::COMPONENT_BONE_ID;
		}

		virtual void Begin()
		{
			Init();
			AbstractRenderPolicy::Begin();

			glEnable(GL_DEPTH_TEST);
			CHECK_GL_ERROR(L"Unable to enable depth test");
			glDepthFunc(GL_LESS);
			CHECK_GL_ERROR(L"Unable to set less depth function");
			glDepthMask(GL_TRUE);
			CHECK_GL_ERROR(L"Unable to enable depth mask");
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			CHECK_GL_ERROR(L"Unable to set polygon mode");
			/*glEnable(GL_BLEND);
			CHECK_GL_ERROR(L"Unable to enable blend");
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			CHECK_GL_ERROR(L"Unable to set blend func");
			glEnable(GL_CULL_FACE);
			CHECK_GL_ERROR(L"Unable to enable cull facing");
			glCullFace(GL_FRONT);
			CHECK_GL_ERROR(L"Unable to set cull face mode");*/
		}

		virtual void End()
		{
			AbstractRenderPolicy::End();			

			//glEnable(GL_DEPTH_TEST);			
			//glDepthFunc(GL_LESS);
			//glDepthMask(GL_TRUE);
			//glEnable(GL_BLEND);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);			
		}	
	};
}

#endif