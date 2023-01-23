#include "Collision.h"
#define _USE_MATH_DEFINES
#include <math.h>


bool Collision(int positionX1, int positionY1, int radius1, int positionX2, int positionY2, int radius2) {

	float A = positionX1 - positionX2;
	float B = positionY1 - positionY2;
	float Dis = sqrtf(A * A + B * B);
	if (Dis <= radius1 + radius2) {
		return true;
	}
	return false;
}