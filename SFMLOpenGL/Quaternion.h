#pragma once
#include  <cstring>
#include <iostream>
#include "vector3.h"
const float PI = 3.14159265359f;

class Quaternion
{
public:
	float x, y, z, w;
	
	Quaternion();
			
			Quaternion(float _w, float _x, float _y, float _z);
			

			 Quaternion(float _w, vector3 v);
			
			std::string ToString();

			vector3 Rotate(vector3 pt, int _angle);
			

			 float  getModulus(); 
			
			 Quaternion Normalise();
			
			Quaternion Conjugate();
			

			void FromAxisAngle(vector3 axis, float angleRadian);
			
			Quaternion Multiply(Quaternion _q);
			

			Quaternion Copy();
		
			//                  -1
			// V'=q*V*q     ,

			//friend vector3 Rotate(vector3 pt, int _angle);
			

			// Multiplying q1 with q2 is meaning of doing q2 firstly then q1
			 Quaternion operator +(Quaternion q2);
			

			Quaternion operator -(Quaternion q1);
			

			
			
			

			Quaternion operator *(float s);
			
			friend  Quaternion operator *(Quaternion q1, float s);
			
			Quaternion operator *(int s);
			
			friend 	  Quaternion operator *(float s, Quaternion q1);
			
			friend  Quaternion operator *(float s, Quaternion q1);
			
			friend  Quaternion operator *(int s, Quaternion q1);
		
			

			friend  Quaternion operator *(Quaternion q1, Quaternion q2);
			
	

};

