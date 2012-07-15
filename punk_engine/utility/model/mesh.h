#ifndef _H_PUNK_UTILITY_MESH
#define _H_PUNK_UTILITY_MESH

#include "../../math/vec3.h"
#include "../../math/bounding_box.h"
#include "texture_faces.h"
#include "vertex_bone_weight.h"
#include "vertex_index.h"

namespace Utility
{
	typedef int FaceIndex;
	typedef std::vector<Math::vec3> Vertices;
	typedef std::vector<Math::vec3> Normals;	
	typedef std::vector<Math::ivec3> Faces;
	typedef Math::BoundingBox BoundingBox;		

	struct Mesh
	{		
		Vertices m_vertices;
		Normals m_normals;
		Faces m_faces;
		VertexBoneWeights m_bone_weights;
		TextureMeshes m_tex_coords;
	};
}

#endif