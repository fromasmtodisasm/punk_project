#ifndef _PUNK_UTILITY_VERTEX_COMPONENT
#define _PUNK_UTILITY_VERTEX_COMPONENT

namespace Utility
{
	enum VertexComponent {
		COMPONENT_NONE = 0,
		COMPONENT_POSITION = 1, 
		COMPONENT_NORMAL = 2,
		COMPONENT_TANGENT = 4, 
		COMPONENT_BITANGENT = 8, 
		COMPONENT_TEXTURE = 16, 
		COMPONENT_BONE_ID = 32,
		COMPONENT_FLAG = 32,
		COMPONENT_BONE_WEIGHT = 64
	};

	typedef int VertexAttributes;
}

#endif	//	_PUNK_UTILITY_VERTEX_COMPONENT