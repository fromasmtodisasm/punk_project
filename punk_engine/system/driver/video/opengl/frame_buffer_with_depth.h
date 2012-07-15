/*
File: FrameBufferWithDepth.h
Author: Abramau Mikalai
Description: Calss for rendering to texture.
Simply now i don't know what for
frame buffer object can be used else
*/

#ifndef _H_PUNK_FRAME_BUFFER_OBJECT_WITH_DEPTH
#define _H_PUNK_FRAME_BUFFER_OBJECT_WITH_DEPTH

#include "gl/gl3.h"
#include "frame_buffer.h"

namespace OpenGL
{
	class MODULE_OPENGL FrameBufferWithDepth : public FrameBuffer
	{		
	public:
		FrameBufferWithDepth();
		virtual ~FrameBufferWithDepth();
		virtual void Init(GLint width, GLint height);
	};
}

#endif	//_H_FRAME_BUFFER_OBJECT_WITH_DEPTH
