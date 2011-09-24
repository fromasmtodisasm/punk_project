/*
File: Texture2D.h
Author: Abramov Nickolai
Description: Contains a Texture2D class
*/

#ifndef _H_PUNK_TEXTURE_2D
#define _H_PUNK_TEXTURE_2D

#include "config.h"
#include "../../../../images/formats.h"

namespace Image
{
	class ImageFile;
}

namespace OpenGL
{
	class LIB_OPENGL Texture2D
	{

	public:
		Texture2D();
		Texture2D(const Texture2D& texture);
		Texture2D& operator = (const Texture2D& texture);
		~Texture2D();
		void Resize(int width, int height);
		void Create(int width, int height, Image::ImageFormat format, const unsigned char* data);
		void Create(const Image::ImageFile& image);
		void CopyFromCPU(int x, int y, int width, int height, Image::ImageFormat format, const unsigned char* data);
		void Fill(unsigned char byte);
		void Lock(void** ptr);
		void Unlock(void* ptr);
		void Bind() const;
		void Unbind() const;

		int GetWidth() const;
		int GetHeight() const;

		unsigned GetID() const; 

	private:
		int m_width;
		int m_height;
		int m_format;
		unsigned m_id;

		int ToInternalFormat(Image::ImageFormat format);
	};
}

#endif	// _H_Texture2D