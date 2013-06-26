#ifndef _H_PUNK_OPENGL_VERTEX_SHADER_BUMP
#define _H_PUNK_OPENGL_VERTEX_SHADER_BUMP

#include "../shader.h"

namespace GPU
{
	namespace OpenGL
	{
        class VsBumpMapping : public Shader
		{
		public:
            VsBumpMapping();

            virtual void InitUniforms() override;
            virtual void BindParameters(const CoreState& params) override;
            virtual int64_t GetRequiredAttributesSet() const override;

        private:
            unsigned uWorld;
            unsigned uView;
            unsigned uProj;
            unsigned uNormalMatrix;
            unsigned uLightPosition;
            unsigned uTextureMatrix;
		};
	}
}

#endif
