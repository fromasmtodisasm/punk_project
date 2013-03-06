#include "gpu_state.h"

namespace GPU
{
	CoreState::CoreState()
	{
		m_depth_test = true;
		m_blending = false;
		m_line_smooth = true;
		m_multisample = true;
		m_polygon_smooth = true;
		m_wireframe = false;
		m_enable_shadows = false;
		m_enable_lighting = true;
		m_line_width = 1;
		m_point_size = 1;
	}

	CoreState::~CoreState()
	{
		//	do not delete pointers, because they are owned by someone else
	}

	CoreState* CoreState::Clone()
	{
		return new CoreState(*this);
	}
}
