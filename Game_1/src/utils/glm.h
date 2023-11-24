#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static float to_radians(float degrees)
{
	return degrees * M_PI / 180.0f;
}