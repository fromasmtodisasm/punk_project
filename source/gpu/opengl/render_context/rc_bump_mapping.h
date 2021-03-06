#ifndef _H_PUNK_OPENGL_RENDER_CONTEXT_BUMP_MAPPING
#define _H_PUNK_OPENGL_RENDER_CONTEXT_BUMP_MAPPING

#include "gl_render_context.h"
#include "shaders/vertex/vs_bump.h"
#include "shaders/fragment/fs_bump.h"

namespace GPU
{
	namespace OpenGL
	{
		/**********************************************************************************************/
		/*			BUMP MAPPING 3D
		/**********************************************************************************************/
		template<> class RenderContextPolicy<VertexShaderBump, FragmentShaderBump, NoShader> : public OpenGLRenderContext
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
					OpenGLRenderContext::Init();
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
				if (!pparams.m_lights.empty())
					SetUniformVector3f(uLightPosition, &pparams.m_lights[0]->GetPosition()[0]);
				else
				{
					Math::vec3 v(0,0,0);
					SetUniformVector3f(uLightPosition, &v[0]);
				}

				if (pparams.m_material)
				{
					SetUniformVector4f(uAmbient, &(Math::vec4(pparams.m_material->GetAmbient()))[0]);
					SetUniformVector4f(uSpecular, &pparams.m_material->GetSpecularColor()[0]);
					SetUniformVector4f(uDiffuse, &pparams.m_material->GetDiffuseColor()[0]);
					SetUniformFloat(uSpecularPower, pparams.m_material->GetSpecularFactor());
					SetUniformInt(uDiffuseMap, pparams.m_diffuse_slot_0);
					SetUniformInt(uNormalMap, pparams.m_normal_slot);		
				}

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

			VertexAttributes GetRequiredAttributesSet() const 
			{
				return COMPONENT_POSITION|COMPONENT_TEXTURE|COMPONENT_BITANGENT|COMPONENT_TANGENT|COMPONENT_NORMAL;
			}

			virtual void Begin()
			{
				Init();
				OpenGLRenderContext::Begin();

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
				OpenGLRenderContext::End();			

				//glEnable(GL_DEPTH_TEST);			
				//glDepthFunc(GL_LESS);
				//glDepthMask(GL_TRUE);
				//glEnable(GL_BLEND);
				//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);			
			}	
		};
	}
}

#endif