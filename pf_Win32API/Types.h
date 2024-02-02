#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;


struct Pos
{
	Pos() {}
	Pos(float x, float y) : x(x), y(y) {}
	Pos(POINT pt) : x((float)pt.x), y((float)pt.y) { }

	Pos operator+(const Pos& other)
	{
		Pos ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Pos operator-(const Pos& other)
	{
		Pos ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	Pos operator*(float value)
	{
		Pos ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const Pos& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const Pos& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=(float ratio)
	{
		x *= ratio;
		y *= ratio;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	void Normalize()
	{
		float length = Length();
		if (length < 0.00000000001f)
			return;

		x /= length;
		y /= length;
	}

	float Dot(Pos other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(Pos other)
	{
		return x * other.y - y * other.x;
	}

	float x = 0;
	float y = 0;
};

struct PosInt
{
	PosInt() {}
	PosInt(int32 x, int32 y) : x(x), y(y) {}
	PosInt(POINT pt) : x((float)pt.x), y((float)pt.y) { }

	PosInt operator+(const PosInt& other)
	{
		PosInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	PosInt operator-(const PosInt& other)
	{
		PosInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	PosInt operator*(float value)
	{
		PosInt ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const PosInt& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const PosInt& other)
	{
		x -= other.x;
		y -= other.y;
	}



	float Dot(PosInt other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(PosInt other)
	{
		return x * other.y - y * other.x;
	}

	int32 x = 0;
	int32 y = 0;
};