#include "vs_grass.h"
#include "../../../../environment.h"

namespace OpenGL
{
	VertexShaderGrass::VertexShaderGrass()
		: Shader(SHADER_VERTEX)
	{
		CookFromFile(System::Environment::Instance()->GetShaderFolder() + L"grass_330.vert");
	}
}
