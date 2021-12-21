#pragma once
#include<math.h>
class vector2D
{
public:

	vector2D(float x = 0, float y = 0) : m_x{x} , m_y{y}
	{
	}
	vector2D(const vector2D& v) : m_x(v.m_x), m_y(v.m_y) {}


	//set getter method to acces cetor location for operations
	float get_x() { return m_x; }
	float get_y() { return m_y; }

	void set_x(float x) { m_x = x; }
	void set_y(float y) { m_y = y; }


	vector2D& operator=(const vector2D& v)
	{
		if (this == &v)
		{
			return *this;
		}

		m_x = v.m_x;
		m_y = v.m_y;

		return *this;
	}

	vector2D& operator+=(const vector2D& v1)
	{
		m_x += v1.m_x;
		m_y += v1.m_y;

		return (*this);
	}

	

	friend vector2D& operator+(vector2D& v1, const vector2D& v2)
	{
		return (v1 += v2);
	}


	vector2D& operator-=(const vector2D v1)
	{
		m_x -= v1.m_x;
		m_y -= v1.m_y;

		return *this;
	}

	friend vector2D operator-(vector2D& v1, const vector2D& v2)
	{
		return (v1 -= v2);
	}

	vector2D& operator-(float x)
	{
		m_x -= x;
		m_y -= x;

		return *this;
	}

	vector2D& operator*=(float n)
	{
		m_x *= n;
		m_y *= n;

		return *this;
	}

	vector2D operator*(float scalar)
	{
		return vector2D(m_x * scalar, m_y * scalar);
	}
	

	vector2D& operator/=(float n)
	{
		m_x /= n;
		m_y /= n;

		return *this;
	}
	
	vector2D operator/(float scalar)
	{
		return vector2D(m_x / scalar, m_y / scalar);
	}
private:

	//vector cordinate in space
	float m_x;
	float m_y;
};

