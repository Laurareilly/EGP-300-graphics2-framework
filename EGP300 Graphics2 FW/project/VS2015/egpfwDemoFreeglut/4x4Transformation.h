/*
4x4 Homogeneous Transformation Matrix by Laura Reilly

Certificate of Authenticity

I certify that this work is entirely my own.The assessor of this project may
reproduce this project and provide copies to other academic staff, and / or
communicate a copy of this project to a plagiarism - checking service, which
may retain a copy of the project on its database.
*/

#ifndef TRANSFORMATION4X4_H
#define TRANSFORMATION4X4_H

#ifdef __cplusplus
extern "C"
{
#endif	// __cplusplus

	struct Transform4x4
	{
		float matrixElements[4][4];
	};

	struct Transform4x4 inverse4x4(struct Transform4x4* inputMat);
	struct Vector3 multiply3DVector4x4(struct Vector3* inputVector, struct Transform4x4* inputMatrix);
	struct Transform4x4 concatenate4x4(struct Transform4x4* a, struct Transform4x4* b);
	struct Mat3x3 getRotationFromTransformation(struct Transform4x4* inputMat);

	void makeIdentity4x4(struct Transform4x4* matrix);

	void makeTransformFromRotation(struct Mat3x3* inputMat, float x, float y, float z);
	void makeTransformFromTranslation(struct Transform4x4* inputMat, float x, float y, float z);
	void makeTransformFromUniformScale(struct Transform4x4* inputMat, float scale);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif

