#include "math_error.h"

namespace Math
{
	MathError::MathError() : m_w_what(0)
	{
	}

	MathError::MathError(const wchar_t* message) : m_w_what(message) {}

	MathError::~MathError()
	{
	}

	const wchar_t * MathError::w_what() const
	{
		return m_w_what;
	}
	}