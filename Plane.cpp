/*----------------------------------------------------------
* COSC363  Ray Tracer
*
*  The Plane class
*  This is a subclass of Object, and hence implements the
*  methods intersect() and normal().
-------------------------------------------------------------*/

#include "Plane.h"
#include "Vector.h"
#include <math.h>

//Function to test if an input point is within the quad.
bool Plane::isInside(Vector q)
{
	Vector n = normal(q);
	Vector ua = b-a,  ub = c-b, uc = d-c, ud = a-d;
	Vector va = q-a,  vb = q-b, vc = q-c, vd = q-d;
	
	Vector uaXva = ua.cross(va);
	Vector ubXvb = ub.cross(vb);
	Vector ucXvc = uc.cross(vc);
	Vector udXvd = ud.cross(vd);

	return uaXva.dot(n) >= 0 && ubXvb.dot(n) >= 0 && ucXvc.dot(n) >= 0 && udXvd.dot(n) >= 0;
}

//Function to compute the paramter t at the point of intersection.
float Plane::intersect(Vector pos, Vector dir)
{
	Vector n = normal(pos);
	Vector vdif = a-pos;
	float vdotn = dir.dot(n);
	if(fabs(vdotn) < 1.e-4) return -1;
    float t = vdif.dot(n)/vdotn;
	if(fabs(t) < 0.0001) return -1;
	Vector q = pos + dir*t;
	if(isInside(q)) return t;
    else return -1;
}

// Function to compute the unit normal vector
// Remember to output a normalised vector!
Vector Plane::normal(Vector pos)
{

	Vector ba = b - a;
	Vector ca = c - a;
	Vector n = ba.cross(ca);
	n.normalise();
	return n;
}



