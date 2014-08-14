#ifndef __VECTOR3_H__
#define	__VECTOR3_H__

namespace DIR
{
	class Vector3
	{
	public:
		inline Vector3()
		{}

		inline Vector3(float fx, float fy, float fz)
			: x(fx), y(fy), z(fz)
		{}

	public:
		float x, y, z;
	};
}
#endif