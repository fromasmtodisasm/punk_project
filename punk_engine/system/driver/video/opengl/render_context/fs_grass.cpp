#include "fs_grass.h"
#include "../../../../environment.h"

namespace OpenGL
{
	FragmentShaderGrass::FragmentShaderGrass()
		: Shader(SHADER_FRAGMENT)
	{
		CookFromFile(System::Environment::Instance()->GetShaderFolder() + L"grass_330.frag");
	}
}