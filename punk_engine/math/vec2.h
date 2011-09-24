#ifndef _H_VEC2_MATH
#define _H_VEC2_MATH

#include <stdio.h>
#include "../system/string.h"
#include "vec3.h"
#include "vec4.h"

namespace Math
{
	template<class T>
	class  Vector2
	{
	public:
		static const int Size_c = 2;
		T m_v[Size_c];

		const T& X() const
		{
			return m_v[0]; 
		}

		T& X()
		{
			return m_v[0]; 
		}

		T& Y()
		{
			return m_v[1]; 
		}

		const T& Y() const
		{ 
			return m_v[1]; 
		}

		T& R()
		{
			return m_v[0]; 		
		}

		const T& R() const 
		{
			return m_v[0]; 
		}

		const T& G() const
		{
			return m_v[1]; 
		}

		T& G() 
		{
			return m_v[1]; 
		}

		Vector2<T> XY() const
		{
			return Vector2<T>(m_v[0], m_v[1]); 
		}
		
		operator T* ()
		{
			return m_v;
		}

		T& operator [] (int i)
		{
			return m_v[i];
		}

		const T& operator [] (int i) const
		{
			return m_v[i];
		}

		Vector2<T>& operator = (const Vector2<T>& vec)
		{
			memcpy_s(m_v, sizeof(m_v), vec.m_v, sizeof(m_v));
			return *this;
		}

		Vector2<T>()
		{
			memset(m_v, 0, sizeof(m_v));
		}

		Vector2<T>(T x, T y) 
		{
			m_v[0] = x; m_v[1] = y;
		}

		Vector2<T>(const Vector2<T>& vec)
		{
			memcpy_s(m_v, sizeof(m_v), vec.m_v, sizeof(m_v));
		}

		Vector2<T>(const Vector2<T>& origin, const Vector2<T>& destination)
		{
			m_v[0] = destination.m_v[0] - origin.m_v[0];
			m_v[1] = destination.m_v[1] - origin.m_v[1];
		}       

		Vector2<T>& Normalize()
		{
			T t = (T)sqrtf(float(m_v[0] * m_v[0] + m_v[1] * m_v[1]));
			m_v[0] /= t;
			m_v[1] /= t;
			return *this;
		}

		T Length()
		{
			return (T)sqrtf(float(m_v[0] * m_v[0] + m_v[1] * m_v[1]));
		}

		T SqrLength()
		{
			return m_v[0] * m_v[0] + m_v[1] * m_v[1];
		}

		Vector2<T>& Negate()
		{
			m_v[0] = -m_v[0];
			m_v[1] = -m_v[1];
			return *this;
		}

		Vector2<T>& Set(T x, T y)
		{
			m_v[0] = x;
			m_v[1] = y;
			return *this;
		}    

		Vector2<T> ComponentMult(const Vector2<T>& v)
		{
			return Vector2<T>(m_v[0]*v[0], m_v[1]*v[1]);
		}

		T Dot(const Vector2<T>& vec)
		{
			return m_v[0]*vec.m_v[0] + m_v[1]*vec.m_v[1];
		}

		Vector3<T> ToHomogeneous() const
		{
			return Vector3<T>(m_v[0], m_v[1], T(1));
		}

		Vector3<T> ToVector3() const
		{
			return Vector3<T>(m_v[0], m_v[1], T(0));
		}

		Vector4<T> ToVector4() const
		{
			return Vector4<T>(m_v[0], m_v[1], T(0), T(1));
		}

		System::string ToString() const
		{
			return System::string::Format(L"(%.3f; %.3f)", m_v[0], m_v[1]);
		}

/*		void Save(System::Buffer& buffer) const
		{
			buffer.WriteReal32(m_v[0]);
			buffer.WriteReal32(m_v[1]);
		}

		void Load(System::Buffer& buffer)
		{
			m_v[0] = buffer.ReadReal32();
			m_v[1] = buffer.ReadReal32();
		}*/
	};

	template<class T>
	static Vector2<T> operator + (const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return Vector2<T>(v1.m_v[0] + v2.m_v[0], v1.m_v[1] + v2.m_v[1]);
	}

	template<class T>
	inline Vector2<T> operator - (const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return Vector2<T>(v1.m_v[0] - v2.m_v[0], v1.m_v[1] - v2.m_v[1]);
	}

	template<class T>
	inline Vector2<T> operator *(const Vector2<T>& m_v, T d)
	{
		return Vector2<T>(m_v.m_v[0] * d, m_v.m_v[1] * d);
	}

	template<class T>
	inline Vector2<T> operator *(T d, const Vector2<T> &m_v)
	{
		return Vector2<T>(m_v.m_v[0] * d, m_v.m_v[1] * d);
	}

	template<class T>
	inline Vector2<T> operator / (const Vector2<T>& m_v, T d)
	{
		return Vector2<T>(m_v.m_v[0] / d, m_v.m_v[1] / d);
	}

	template<class T>
	inline bool operator == (const Vector2<T>& a, const Vector2<T>& b)
	{
		return a[0] == b[0] && a[1] == b[1];
	}

	template<class T>
	inline bool operator != (const Vector2<T>& a, const Vector2<T>& b)
	{
		return !(a == b);
	}

	template class LIB_MATH Vector2<float>;
	template class LIB_MATH Vector2<int>;

	typedef Vector2<float> vec2;
	typedef Vector2<int> ivec2;
}

#endif