#include "../system/allocator.h"
#include "../render/render.h"
#include "static_text_area.h"

namespace GUI
{
	StaticTextArea::StaticTextArea(int x, int y, int width, int height, Widget* parent) : Widget(x, y, width, height, parent),  m_textRender(Render::TextAreaRender::GetRender())
	{
		//m_color[0] = m_color[1] = m_color[2] = m_color[3] = 1.0f;
		//m_textRender->SetText(m_text.c_str());
		RenderTextToTexture();
	}

	StaticTextArea::~StaticTextArea()
	{
	}

	void StaticTextArea::Render()
	{
		if (m_isVisible)
		{			
			Render::TextAreaRender::Parameters* p = Render::TextAreaRender::Parameters::Create();
			p->m_color[0] = m_textColor[0]; p->m_color[1] = m_textColor[1]; p->m_color[2] = m_textColor[2]; p->m_color[3] = m_textColor[3];
			p->m_height = (float)m_height;
			p->m_width = (float)m_width;
			p->m_x = (float)GetX();
			p->m_y = (float)GetY();	
			p->m_texture = &m_textTexture;
			Render::RenderPipeline::GetRenderPipeline()->Add(m_textRender, (void*)p);
		}
	}
}