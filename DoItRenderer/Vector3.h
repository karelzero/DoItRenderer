#ifndef __VECTOR3_H__
#define	__VECTOR3_H__

#include <math.h>

namespace DIR
{
	class Vector3
	{
	public:
		inline Vector3() {}
		inline Vector3(float fx, float fy, float fz)
			: x(fx), y(fy), z(fz) {}
		inline Vector3(const Vector3& v)
			: x(v.x), y(v.y), z(v.z) {}

		inline Vector3& operator=(const Vector3& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;

			return *this;
		}

		inline Vector3 operator+(const Vector3& v) const
		{
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		inline Vector3 operator-(const Vector3& v) const
		{
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		inline Vector3 operator-() const
		{
			return Vector3(-x, -y, -z);
		}

		inline Vector3 operator*(float f) const
		{
			return Vector3(x*f, y*f, z*f);
		}

		inline float operator*(const Vector3& v) const
		{
			return x*v.x + y*v.y + z*v.z;
		}

		inline Vector3 operator/(float f) const
		{
			float fInv = 1.0f / f;
			return Vector3(x*fInv, y*fInv, z*fInv);
		}

		inline Vector3& operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		inline Vector3& operator-=(const Vector3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		
		inline Vector3& operator*=(float f)
		{
			x *= f;
			y *= f;
			z *= f;
			return *this;
		}

		inline Vector3& operator/=(float f)
		{
			float fInv = 1.0f / f;
			x *= fInv;
			y *= fInv;
			z *= fInv;
			return *this;
		}

		inline bool operator==(const Vector3& v) const
		{
			return (x == v.x && y == v.y && z == v.z);
		}

		inline bool operator!=(const Vector3& v) const
		{
			return (x != v.x || y != v.y || z != v.z);
		}

		inline void normalize() 
		{
			float len = length(*this);
			if (len > 0.0f)
			{
				float lenInv = 1.0f / len;
				x *= lenInv;
				y *= lenInv;
				z *= lenInv;
			}
		}

		inline void zero()
		{
			x = y = z = 0.0f;
		}
	public:
		float x, y, z;
		const static Vector3 ZERO;
	};

	inline float length(const Vector3& v)
	{
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
	{
		return Vector3(a.y*b.z - a.z*b.y,
			a.z*b.x - a.x*b.z,
			a.x*b.y - a.y*b.z);
	}

	inline Vector3 operator*(float f, const Vector3& v)
	{
		return Vector3(f*v.x, f*v.y, f*v.z);
	}

	inline float distance(const Vector3& a, const Vector3& b)
	{
		return length(a - b);
	}
}
#endif