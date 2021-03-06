#ifndef _H_PUNK_GPU_EXCPETION
#define _H_PUNK_GPU_EXCPETION

#include "../../system/errors/module.h"

namespace GPU
{
	class PUNK_ENGINE GPUException : public System::PunkException
	{
	public:
		GPUException();
		GPUException(const System::string& msg);
	};

	class PUNK_ENGINE GPUNotImplementedException : public System::PunkException
	{
	public:
		GPUNotImplementedException() {}
		GPUNotImplementedException(const System::string& msg) : System::PunkException(msg) {}
	};
}

#endif	//	_H_PUNK_GPU_EXCPETION