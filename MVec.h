#ifndef MVEC_H
#define MVEC_H 

/**   @file MVec.h    
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-23-14
      @version 0.01   
      
      This MVec class represents a physics 2-dimensional vector.
      
      Various operators need to be overloaded and implemented:
      
      +  Does vector addition
      *  Extends the vector 'extend' (float) times.
      == Equal if each component differs by less than 0.01
      != Opposite of ==
**/
      
#include <iostream>

using namespace std;

class MVec{
  public:
  
  MVec();     // Initialize x=0, y=0
  MVec(float x, float y); // Sets x and y
  
  float getMagnitude() const; // Gives the magnitude of the vector
  float getX() const;         // Gets x component
  float getY() const;         // Gets y component
  
  friend MVec operator+(const MVec& v1, const MVec& v2); // Overrides + operator

  friend MVec operator*(const MVec& v1, const float num); // Overrides * operator

  friend bool operator==(const MVec& v1, const MVec& v2); // Overrides ==

  friend bool operator!=(const MVec& v1, const MVec& v2); // Overrides !=
    
  private:
  
  float y_val;
  float x_val;
  
};

ostream& operator<<(ostream& os, const MVec& v); // Overrides <<

#endif 
