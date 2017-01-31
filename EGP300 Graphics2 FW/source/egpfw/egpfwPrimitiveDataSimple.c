// By Dan Buckstein
// Modified by: _______________________________________________________________
#include "egpfw/egpfw/egpfwPrimitiveDataSimple.h"


#include "GL/glew.h"

#include <math.h>


//------------------------------------------------------------------------------


// draw coordinate axes using immediate mode
// **WARNING: DO NOT EVER USE IMMEDIATE MODE FOR FULL-SCALE MODELS
void egpfwDrawAxesImmediate(const float *mvp, const int mvpLoc)
{
	// for immediate rendering, load mvp matrix onto stack
	glPushMatrix();
	glLoadMatrixf(mvp);

	// if shaders are being used, mvp should be sent as a uniform
	// this is still considered immediate mode because the data 
	//	is discarded immediately after it is used
	glUniformMatrix4fv(mvpLoc, 1, 0, mvp);

	// start drawing primitives
	glBegin(GL_LINES);

	// send attributes 1-by-1
	// glVertex is used to send position and finish current vertex
	// (the last attribute values sent will be used for this vertex)
	glColor3f (1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3f (0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3f (0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	// stop drawing primitives
	glEnd();

	// remove mvp matrix from stack
	glPopMatrix();
}


// ****
// draw colored triangle using immediate mode
// position and color attributes each have 3 elements
// **WARNING: DO NOT EVER USE IMMEDIATE MODE FOR FULL-SCALE MODELS
void egpfwDrawColoredTriangleImmediate(const float *mvp, const int mvpLoc)
{
	glPushMatrix();
	glLoadMatrixf(mvp);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);

	glEnd();

	glPopMatrix();
}


// ****
// draw colored unit quad using immediate mode
// should draw quad as a TRIANGLE STRIP (quad is deprecated)
// **WARNING: DO NOT EVER USE IMMEDIATE MODE FOR FULL-SCALE MODELS
void egpfwDrawColoredUnitQuadImmediate(const float *mvp, const int mvpLoc)
{
	glPushMatrix();
	glLoadMatrixf(mvp);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0, 1.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-1.0, -1.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(1.0, 1.0);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(1.0, -1.0);

	glEnd();
	glPopMatrix();
}


// ****
// draw unit quad with texture coordinates using immediate mode
// texture coordinates have 2 elements
// should draw quad as a TRIANGLE STRIP (quad is deprecated)
// **WARNING: DO NOT EVER USE IMMEDIATE MODE FOR FULL-SCALE MODELS
void egpfwDrawTexturedUnitQuadImmediate(const float *mvp, const int mvpLoc)
{
	glPushMatrix();
	//...
	glPopMatrix();
}


//-----------------------------------------------------------------------------

// ****
// raw quad data
// data should be arranged as TRIANGLE STRIP: use at most 4 vertices!
#define quadNumVertices 4
float fwUnitQuadPositions[quadNumVertices * 3] =
{
	 -1.0, -1.0, 0.0,
	 1.0, -1.0, 0.0,
	  -1.0, 1.0, 0.0,
	  1.0, 1.0, 0.0
};

 float fwUnitQuadColors[quadNumVertices * 3] =
{
	0.0, 0.0, 0.0,
	1.0, 0.0, 1.0,
	0.0, 0.0, 0.0,
	1.0, 0.0, 1.0
};

const float fwUnitQuadTexcoords[quadNumVertices * 2] = 
{
	0.0, 0.0,
	0.0, 0.0,
	0.0, 0.0,
	0.0, 0.0
};

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// get data for quad that can be colored or textured
const float *egpfwGetUnitQuadPositions()
{
	// this function is complete!
	return fwUnitQuadPositions;
}

const float *egpfwGetUnitQuadColors()
{
	// this function is complete!
	return fwUnitQuadColors;
}

const float *egpfwGetUnitQuadTexcoords()
{
	// this function is complete!
	return fwUnitQuadTexcoords;
}

unsigned int egpfwGetUnitQuadVertexCount()
{
	// this function is complete!
	return quadNumVertices;
}




//-----------------------------------------------------------------------------

// ****
// raw disc data
// data should be arranged as TRIANGLE FAN: use at most 10ish vertices!
#define discNumVertices 100
float fwDiscPositions[discNumVertices * 3] =
{
	0.0,
};

float fwDiscColors[discNumVertices * 3] =
{
	0.0,
};

const float fwDiscTexcoords[discNumVertices * 2] =
{
	0.0,
};


const float *egpfwGetDiscPositions()
{
	float angle = ((2 * 3.14159265359) / discNumVertices);
	float curentAngle = 0;

	for (int i = 0; i < discNumVertices * 3 - 3; i += 3)
	{
		fwDiscPositions[i] = 0 + 1 * cos(curentAngle);
		fwDiscPositions[i + 1] = 0 + 1 * sin(curentAngle);
		fwDiscPositions[i + 2] = 0;
		curentAngle += angle;
	}

	return fwDiscPositions;
}

const float *egpfwGetDiscColors()
{
	for (int i = 0; i < discNumVertices * 3 - 3; i += 3)
	{
		if ((discNumVertices * 3) / 6 > i)
		{
			fwDiscColors[i] = 1;
			fwDiscColors[i + 1] = 1/((discNumVertices * 3) / 6) * i;
			fwDiscColors[i + 2] = 0;
		}
		else
		{
			fwDiscColors[i] = 1;
			fwDiscColors[i + 1] = 1;
			fwDiscColors[i + 2] = 1;

		}
	}
	// this function is complete!
	return fwDiscColors;
}

const float *egpfwGetDiscTexcoords()
{
	// this function is complete!
	return fwDiscTexcoords;
}

unsigned int egpfwGetDiscVertexCount()
{
	// this function is complete!
	return discNumVertices;
}