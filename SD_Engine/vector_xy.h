#pragma once

class VectorXY {
public:
	float x;
	float y;

	VectorXY();
	VectorXY(float x, float y);

	VectorXY& operator=(VectorXY &vxy) {
		this->x = vxy.x;
		this->y = vxy.y;
		return *this;
	}

	VectorXY operator+(VectorXY &vxy) {
		return VectorXY(this->x + vxy.x, this->y + vxy.y);
	}

	VectorXY operator-(VectorXY &vxy) {
		return VectorXY(this->x - vxy.x, this->y - vxy.y);
	}

	VectorXY& operator+=(VectorXY &vxy) {
		this->x += vxy.x;
		this->y += vxy.y;
		return *this;
	}

	VectorXY& operator-=(VectorXY &vxy) {
		this->x -= vxy.x;
		this->y -= vxy.y;
		return *this;
	}

	VectorXY operator+(float c) {
		return VectorXY(this->x + c, this->y + c);
	}
	VectorXY operator-(float c) {
		return VectorXY(this->x - c, this->y - c);
	}
	VectorXY operator*(float c) {
		return VectorXY(this->x * c, this->y * c);
	}
	VectorXY operator/(float c) {
		return VectorXY(this->x / c, this->y / c);
	}

	VectorXY& operator+=(float c) {
		this->x += c;
		this->y += c;
		return *this;
	}

	VectorXY& operator-=(float c) {
		this->x -= c;
		this->y -= c;
		return *this;
	}

	VectorXY& operator*=(float c) {
		this->x *= c;
		this->y *= c;
		return *this;
	}

	VectorXY& operator/=(float c) {
		this->x /= c;
		this->y /= c;
		return *this;
	}
};