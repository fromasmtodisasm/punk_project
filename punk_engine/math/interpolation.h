#ifndef _H_PUNK_INTERPOLATION
#define _H_PUNK_INTERPOLATION

//#include "constants.h"

namespace Math
{
	template<typename T, typename K>
	T linear_interpolation(const T& a, const T& b, const K& value)
	{
		return a*k + (1-k)*b;
	}

	template<typename T>
	T cosine_interpolation(const T& a, const T& b, const T& value)
	{
		T t = value * PI;
		T tt = (T(1) - cosf(t)) * 0.5f;
		return a*(T(1)-tt) + b*tt;
	}

	template<typename T>
	T cubic_interpolation(const T& v0, const T& v1, const T& v2, const T& v3, const T& value)
	{
		T a = (v3-v2) - (v0 - v1);
		T b = (v0 - v1) - a;
		T c = v2 - v0;
		T d = v1;
		T x = value;

		return a*x*x*x + b*x*x + c*x + d;	//	maybe it should be optimized a little
	}

	//
	//	used for linear interpolation of quaternions
	//
	template<class T>
	T spherical_linear_interpolation(const T& q1, const T& q2, const T& t)
	{
		T theta = std::acos(q1.Dot(q2));
		return std::sin(theta*(1-t))/std::sin(theta)*q1 + std::sin(theta*t)/std::sin(theta)*q2;
	}
}

#endif