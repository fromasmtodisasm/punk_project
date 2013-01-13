#ifndef _H_PUNK_OPENGL_QUAD
#define _H_PUNK_OPENGL_QUAD

#include "vertex_array_object.h"

namespace OpenGL
{
	class PUNK_ENGINE QuadObject : public VertexArrayObject2<GL_TRIANGLES, Utility::COMPONENT_POSITION|Utility::COMPONENT_NORMAL|Utility::COMPONENT_TEXTURE>
	{
		enum { PrimitiveType = GL_TRIANGLES };
		enum { VertexType = Utility::COMPONENT_POSITION|Utility::COMPONENT_NORMAL|Utility::COMPONENT_TEXTURE };
	public:
		QuadObject();
		void Cook(float width, float height);

		static QuadObject* Instance();
		static void Destroy();

	private:
		static std::auto_ptr<QuadObject> m_instance;
	};
}

#endif