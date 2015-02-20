/**   @file MVec.cpp    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-23-14
      @version 0.01   
      
      This MVec class represents a physics 2-dimensional vector.
      
      Various operators need to be implemented or overloaded.
      See MVec.cpp for details.
      
**/
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <stdio.h>

#include "MVec.h"

using namespace std;

/* ---------- Constructors ---------- */

// Default Constructor
MVec::MVec(){
  x_val = 0;
  y_val = 0;
}

// Constructor sets given x and y values
MVec::MVec(float x, float y){
  x_val = x;
  y_val = y;
}

/* ---------- Member Functions ---------- */
  
// Gets magnitude of vector 
float MVec::getMagnitude() const{
  float mag = sqrt((x_val*x_val)+(y_val*y_val));
  return mag;
}

// Gets y comp. of vector
float MVec::getX() const{
  return x_val;
}

// Gets x comp. of vector
float MVec::getY() const{
  return y_val;
}

/* ---------- Operator Overloading ---------- */

MVec operator+(const MVec& v1, const MVec& v2){
  float new_x = v1.getX() + v2.getX();
  float new_y = v1.getY() + v2.getY();
  return MVec(new_x, new_y);
}

MVec operator*(const MVec& v1, const float num){
  float new_x = v1.getX() * num;
  float new_y = v1.getY() * num;
  return MVec(new_x, new_y);
}

bool operator==(const MVec& v1, const MVec& v2){
  if(fabs(v1.getX() - v2.getX()) <= 0.01){
    if(fabs(v1.getY() - v2.getY()) <= 0.01){
      return 1;
    }
  }
  return 0;
}

bool operator!=(const MVec& v1, const MVec& v2){
  return !(v1==v2);
}

ostream& operator<<(ostream& os, const MVec& vec){
  os << "x: " << vec.getX() << " " << "y: " << vec.getY();
  return os;
}
  
