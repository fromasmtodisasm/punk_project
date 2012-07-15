#include "fs_bump.h"
#include "../../../../environment.h"

namespace OpenGL
{
	FragmentShaderBump::FragmentShaderBump()
		: Shader(SHADER_FRAGMENT)
	{
		CookFromFile(System::Environment::Instance()->GetShaderFolder() + L"bump_330.frag");
	}
}