#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>
class Vector2D
{
public:
	Vector2D(float x, float y): m_x(x), m_y(y) {}
	float getX(); 
	float getY(); 

	void setX(float x);
	void setY(float y);

	float length();

	//Addition
	Vector2D operator+(const Vector2D& v2) const;
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x; 
		v1.m_y += v2.m_y; 
		return v1; 
	}
	//Multiplication
	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);

	//Subtraction
	Vector2D operator-(const Vector2D& v2) const;
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1; 
	}

	//Division
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);

	void normalize();

private:
	float m_y;
	float m_x;
};
#endif //Vector2D_h