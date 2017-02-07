/*
3x3 Matrix by Laura Reilly

Certificate of Authenticity

I certify that this work is entirely my own.The assessor of this project may 
reproduce this project and provide copies to other academic staff, and / or 
communicate a copy of this project to a plagiarism - checking service, which 
may retain a copy of the project on its database.
*/

#ifndef MATRIX3_H
#define MATRIX3_H

#ifdef __cplusplus
extern "C"
{
#endif	// __cplusplus

#include "Vector3.h"

	struct Mat3x3
	{
		float matrixElements[3][3];
	};

	struct Mat3x3 transpose(struct Mat3x3* inputMatrix); 
	struct Mat3x3 inverse(struct Mat3x3* inputMatrix);   
	void makeIdentity(struct Mat3x3* inputMatrix);		 

	struct Mat3x3 makeRotX(float radians);               
	struct Mat3x3 makeRotY(float radians);               
	struct Mat3x3 makeRotZ(float radians);               

	struct Vector3 makeEulerXYZ(struct Vector3* inputVector, float x, float y, float z);
	struct Vector3 makeEulerZYX(struct Vector3* inputVector, float x, float y, float z);
	struct Vector3 multiply3DVector(struct Vector3* inputVector, struct Mat3x3* inputMatrix);

	struct Mat3x3 makeUniformScale(float scale); 

	struct Mat3x3 concatenate(struct Mat3x3* a, struct Mat3x3* b); 

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif
