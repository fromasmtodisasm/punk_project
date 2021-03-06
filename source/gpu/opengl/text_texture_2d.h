#ifndef PUNK_TEXT_TEXTURE2D_H
#define PUNK_TEXT_TEXTURE2D_H

#include "../config.h"
#include "texture2d.h"

namespace OpenGL
{
	class PUNK_ENGINE TextTexture2D : public Texture2D
	{
		System::string m_text;
	public:
		const System::string& GetText() const;
		void RenderText(const System::string& value, int font_size = 8, const System::string font_name = L"Courier New");
	};
}

#endif