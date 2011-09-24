#ifndef _H_PUNK_OPENGL_RENDER_CONTEXT
#define _H_PUNK_OPENGL_RENDER_CONTEXT

#include "config.h"

class ShaderProgram;

namespace OpenGL
{
	class Texture2D;
	class LIB_OPENGL RenderContext
	{
		ShaderProgram* m_cur_program;
	public:

		void Begin(ShaderProgram* program);
		void End();

	};
}

#endif