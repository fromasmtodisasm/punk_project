#ifndef _H_PUNK_OPENGL_SHADERS
#define _H_PUNK_OPENGL_SHADERS

#include "vertex/vs_bump.h"
#include "vertex/vs_grass.h"
#include "vertex/vs_gui.h"
#include "vertex/vs_light.h"
#include "vertex/vs_particle.h"
#include "vertex/vs_skinning_bump.h"
#include "vertex/vs_skinning_depth.h"
#include "vertex/vs_terrain.h"
#include "vertex/vs_transform_3d.h"
#include "vertex/vs_transformed_textured_3d.h"
#include "vertex/vs_solid_color.h"
#include "vertex/vs_solid_vertex_color.h"
#include "vertex/vs_per_vertex_lighting_diffuse.h"
#include "vertex/vs_per_vertex_lighting_tex_diffuse.h"
#include "vertex/vs_bump_shadow_map.h"
#include "vertex/vs_per_vertex_lighting_diffuse_shadow_simple.h"
#include "vertex/vs_depth.h"
#include "vertex/vs_per_fragment_lighting_tex_diffuse.h"
#include "vertex/vs_per_fragment_lighting_diffuse.h"
#include "vertex/vs_per_fragment_lighting_diffuse_specular.h"
#include "vertex/vs_per_fragment_lighting_tex_diffuse_specular.h"
#include "vertex/vs_bump_diffuse_color.h"
#include "vertex/vs_bump_diffuse_color_specular.h"
#include "vertex/vs_bump_tex_diffuse.h"
#include "vertex/vs_bump_tex_diffuse_specular.h"

#include "fragment/fs_bump.h"
#include "fragment/fs_grass.h"
#include "fragment/fs_gui.h"
#include "fragment/fs_light.h"
#include "fragment/fs_particle.h"
#include "fragment/fs_skinning.h"
#include "fragment/fs_solid_color.h"
#include "fragment/fs_solid_textured.h"
#include "fragment/fs_terrain.h"
#include "fragment/fs_solid_vertex_color.h"
#include "fragment/fs_per_vertex_lighting_diffuse.h"
#include "fragment/fs_per_vertex_lighting_tex_diffuse.h"
#include "fragment/fs_text_solid.h"
#include "fragment/fs_depth.h"
#include "fragment/fs_bump_shadow_map.h"
#include "fragment/fs_solid_textured_2d_array.h"
#include "fragment/fs_per_fragment_lighting_tex_diffuse.h"
#include "fragment/fs_per_fragment_lighting_diffuse.h"
#include "fragment/fs_per_vertex_lighting_diffuse_shadow_simple.h"
#include "fragment/fs_per_fragment_lighting_diffuse_specular.h"
#include "fragment/fs_per_fragment_lighting_tex_diffuse_specular.h"
#include "fragment/fs_bump_diffuse_color.h"
#include "fragment/fs_bump_diffuse_color_specular.h"
#include "fragment/fs_bump_tex_diffuse.h"
#include "fragment/fs_bump_tex_diffuse_specular.h"

#endif	//	_H_PUNK_OPENGL_SHADERS
