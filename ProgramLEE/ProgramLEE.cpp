#include<iostream>

using namespace std;

class Vector2
{
public:
	int x;
	int y;

	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2 operator+(const Vector2& vector2)
	{
		Vector2 other
		(
			this->x + vector2.x,
			this->y + vector2.y
		);
		return other;
	}
	Vector2 operator-(const Vector2& vector2)
	{
		Vector2 other
		(
			this->x - vector2.x,
			this->y - vector2.y
		);
		return other;
	}

	Vector2 operator*(int value)
	{
		Vector2 other
		(
			this->x * value,
			this->y * value
		);
		return other;
	}
	Vector2 operator/(const Vector2& vector2)
	{
		Vector2 other
		(
			this->x / vector2.x, 
			this->y / vector2.y
		); 
		return other;
	}
};
	
Vector2 operator*(int value, Vector2 vector2)
{
	return vector2 * value;
}
		
int main()
{
	Vector2 vector1(10, 20);
	Vector2 vector2(5, 5);
	
	Vector2 vector3 = vector1 + vector2;
	Vector2 vector4 = vector1 - vector2;
	Vector2 vector5 = 10*vector1 ; 
	Vector2 vector6 = vector1 / vector2;
	Vector2 vector7 = vector1*12;


	cout << "vector3의 값 : (" << vector3.x <<"," << vector3.y << ")"<<endl;
	cout << "vector4의 값 : (" << vector4.x << "," << vector4.y << ")" << endl;
	cout << "vector5의 값 : (" << vector5.x << "," << vector5.y << ")" << endl;
	cout << "vector6의 값 : (" << vector6.x << "," << vector6.y << ")" << endl;
	
	cout << "vector7의 값 : (" << vector7.x << "," << vector7.y << ")" << endl;


	

	return 0;
}
	
	
	
	

	




	




	







	
	


	
		
		
		
		
		
