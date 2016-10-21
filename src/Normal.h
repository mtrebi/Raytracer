#ifndef __NORMAL__
#define __NORMAL__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Matrix.h"
#include "Vector3D.h"
#include "Point3D.h"

class Normal {	
	public:
	
		double	x, y, z;
				
	public:
	
		Normal(void);										// default constructor
		Normal(double a);									// constructor
		Normal(double _x, double _y, double _z);			// constructor
		Normal(const Normal& n); 							// copy constructor
		Normal(const Vector3D& v);							// constructs a normal from a vector
		
		~Normal(void);										// destructor

		Normal& 											// assignment operator
		operator= (const Normal& rhs); 	
		
		Normal& 											// assignment of a vector to a normal
		operator= (const Vector3D& rhs);
		
		Normal& 											// assignment of a point to a normal
		operator= (const Point3D& rhs);
		
		Normal 												// unary minus
		operator- (void) const;	
		
		Normal 												// addition
		operator+ (const Normal& n) const;
		
		Normal& 											// compound addition
		operator+= (const Normal& n);
		
		double
		operator* (const Vector3D& v) const;				// dot product with a vector on the right
		
		Normal 												// multiplication by a double on the right
		operator* (const double a) const;
				
		void 												// convert normal to a unit normal
		normalize(void); 									 		
};



// inlined member functions

// ----------------------------------------------------------------------- operator-
// unary minus

inline Normal 											
Normal::operator- (void) const {
	return (Normal(-x, -y, -z));
}


// ----------------------------------------------------------------------- operator+
// addition of two normals

inline Normal 											
Normal::operator+ (const Normal& n) const {
	return (Normal(x + n.x, y + n.y, z + n.z));
}


// ----------------------------------------------------------------------- addition
// compound addition of two normals

inline Normal& 
Normal::operator+= (const Normal& n) {
	x += n.x; y += n.y; z += n.z;
    return (*this);
}


// ----------------------------------------------------------------------- operator*
// dot product of a normal on the left and a vector on the right

inline double
Normal::operator* (const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
}


// ----------------------------------------------------------------------- operator*
// multiplication by a double on the right

inline Normal
Normal::operator* (const double a) const {
	return (Normal(x * a, y * a, z * a));
}



// inlined non-member functions

// ----------------------------------------------------------------------- operator*
// multiplication by a double on the left

Normal											// prototype
operator* (const double a, const Normal& n);

inline Normal
operator*(const double f, const Normal& n) {
	return (Normal(f * n.x, f * n.y,f * n.z));
}


// ----------------------------------------------------------------------- operator+
// addition of a vector on the left to return a vector 

Vector3D										// prototype
operator+ (const Vector3D& v, const Normal& n);

inline Vector3D
operator+ (const Vector3D& v, const Normal& n) {	
	return (Vector3D(v.x + n.x, v.y + n.y, v.z + n.z));
}	


// ----------------------------------------------------------------------- operator-
// subtraction of a normal from a vector to return a vector

Vector3D
operator- (const Vector3D&, const Normal& n);

inline Vector3D
operator- (const Vector3D& v, const Normal& n) {
	return (Vector3D(v.x - n.x, v.y - n.y, v.z - n.z));
}


// ----------------------------------------------------------------------- operator*
// dot product of a vector on the left and a normal on the right

double
operator* (const Vector3D& v, const Normal& n);

inline double
operator* (const Vector3D& v, const Normal& n) {
	return (v.x * n.x + v.y * n.y + v.z * n.z);     
}



// non-inlined non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a matrix on the left

Normal 												// prototype							
operator* (const Matrix& mat, const Normal& n);

#endif



