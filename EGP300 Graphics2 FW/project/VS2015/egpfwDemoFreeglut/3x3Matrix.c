#include "3x3Matrix.h"



struct Mat3x3 transpose(struct Mat3x3* inputMatrix)
{
	//make a new matrix
	//for loop through num rows
	//for loop through num cols
	//new matrix values [i][j] = input matrix [i][j]
	//return new matrix
}

struct Mat3x3 inverse(struct Mat3x3* inputMatrix)
{

}

struct Mat3x3 makeIdentity(struct Mat3x3* inputMatrix)
{
	//make a new matrix 
	//for loop through num rows
	//for loop through num cols
	//zero out the matrix values [i][j]

	//[0][0] = 1.0
	//[1][1] = 1.0
	//[2][2] = 1.0

	//return the matrix
}

struct Mat3x3 makeRotX(float radians)
{

}

struct Mat3x3 makeRotY(float radians)
{

}

struct Mat3x3 makeRotZ(float radians)
{

}

struct Mat3x3 makeEulerXYZ(float x, float y, float z)
{

}

struct Mat3x3 makeEulerZYX(float x, float y, float z)
{

}

struct Mat3x3 makeUniformScale(float scalar)
{

}

struct Mat3x3 concatenate(struct Mat3x3* a, struct Mat3x3* b)
{

}

//transpose
//inverse
//make rotation x
//make rotation y
//make rotation z
//make rotation euler xyz
//make rotation euler zyx
//make uniform scale
//make identity
//concatenate (matrix multiplication)
//multiply 3D vector
