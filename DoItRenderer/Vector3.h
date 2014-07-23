#ifndef __VECTOR3_H__
#define	__VECTOR3_H__

namespace DIR
{
	class Vector3
	{
	public:
		inline Vector3(): x(0.0), y(0.0), z(0.0)
		{
		}

	public:
		float x, y, z;
	};
}
#endif