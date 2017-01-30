/*
3x3 Matrix by Laura Reilly

Certificate of Authenticity

I certify that this work is
entirely my own.The assessor of this project may reproduce this project
and provide copies to other academic staff, and / or communicate a copy of
this project to a plagiarism - checking service, which may retain a copy of the
project on its database.
*/

#ifndef MATRIX3_H
#define MATRIX3_H


#ifdef __cplusplus
extern "C"
{
#endif	// __cplusplus


	struct Mat3x3
	{
		float matrixElements[3][3];
	};

	struct Mat3x3 transpose(struct Mat3x3* inputMatrix);
	struct Mat3x3 inverse(struct Mat3x3* inputMatrix);
	struct Mat3x3 makeIdentity(struct Mat3x3* inputMatrix);

	struct Mat3x3 makeRotX(float radians);
	struct Mat3x3 makeRotY(float radians);
	struct Mat3x3 makeRotZ(float radians);

	struct Mat3x3 makeEulerXYZ(float x, float y, float z);
	struct Mat3x3 makeEulerZYX(float x, float y, float z);

	struct Mat3x3 makeUniformScale(float scalar);

	struct Mat3x3 concatenate(struct Mat3x3* a, struct Mat3x3* b);


#ifdef __cplusplus
}
#endif	// __cplusplus

#endif
