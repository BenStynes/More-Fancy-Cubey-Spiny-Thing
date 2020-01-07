#include "Quaternion.h"

float Quaternion::getModulus()
{
	return  sqrtf(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::Normalise()
{
	float m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = sqrt(m);
		return  Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return  Quaternion(1, 0, 0, 0);
	}
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(w, -x, -y, -z);

}

void Quaternion::FromAxisAngle(vector3 axis, float angleRadian)
{
	float m = axis.Length();
	if (m > 0.0001)
	{
		float ca = cos(angleRadian / 2);
		float sa = sin(angleRadian / 2);
		x = axis.getX() / m * sa;
		y = axis.getY() / m * sa;
		z = axis.getZ() / m * sa;
		w = ca;
	}
	else
	{
		w = 1; x = 0; y = 0; z = 0;
	}
}

Quaternion Quaternion::Multiply(Quaternion _q)
{
	float nw = _q.w * w - _q.x * x - _q.y * y - _q.z * z;
	float nx = _q.w * x + _q.x * w + _q.y * z - _q.z * y;
	float ny = _q.w * y + _q.y * w + _q.z * x - _q.x * z;
	float nz = _q.w * z + _q.z * w + _q.x * y - _q.y * x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Copy()
{
	return  Quaternion(x, y, z, w);
}





Quaternion Quaternion::operator+(Quaternion q2)
{
	return  Quaternion(w + q2.w, x + q2.x, y + q2.y, z + q2.z);

}

Quaternion Quaternion::operator-(Quaternion q1)
{
	return  Quaternion(-q1.w, -q1.x, -q1.y, -q1.z);

}

Quaternion Quaternion::operator*(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion Quaternion::operator*(int s)
{
	return  Quaternion(w * s, x * s, y * s, z * s);

}



	

	Quaternion::Quaternion()
	{
		w = 0; x = 0; y = 0; z = 0;
	}

	Quaternion::Quaternion(float _w, float _x, float _y, float _z)
	{
		w = _w; x = _x; y = _y; z = _z;

	}

	Quaternion::Quaternion(float _w, vector3 v)
	{
		w = _w; x = v.getX(); y = v.getY(); z = v.getZ();

	}

	std::string Quaternion::ToString()
	{
		return "(" + std::to_string(w) + "," + std::to_string(x) + "i," + std::to_string(y) + "j," + std::to_string(z) + "k)";
	}

	


	Quaternion Normalise()
	{
		return Quaternion();
	}

vector3  Quaternion::Rotate(vector3 pt, int _angle)
	{
		Quaternion axis;
		Quaternion rotate;
		axis =  Normalise() ;
		float angleRad = PI / 180 * _angle;
		rotate = Quaternion(cos(angleRad / 2.0f), sin(angleRad / 2.0f) * axis.x, sin(angleRad / 2) * axis.y, sin(angleRad / 2) * axis.z);
		Quaternion conjugate = rotate.Conjugate();
		Quaternion qNode = Quaternion(0, pt.getX(), pt.getY(), pt.getZ());
		qNode = rotate * qNode * conjugate;
		return  vector3(qNode.x, qNode.y, qNode.z);
	}
	

	Quaternion operator*(Quaternion q1, float s)
	{
		return  Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);

	}

	Quaternion operator*(float s, Quaternion q1)
	{
		return  Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);

	}

	Quaternion operator*(int s, Quaternion q1)
	{
		return  Quaternion(q1.w * s, q1.x * s, q1.y * s, q1.z * s);

	}

	Quaternion operator*(Quaternion q1, Quaternion q2)
	{
		float nw = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
		float nx = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
		float ny = q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z;
		float nz = q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x;
		return Quaternion(nw, nx, ny, nz);
	}
