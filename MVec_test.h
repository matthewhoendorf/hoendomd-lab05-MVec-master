/*
  MVec_test.h
  Unit tests for Lab5, operator overloading.
  Implement MVec to make these pass!
  
*/

#include "MVec.h"
#include <stdexcept>
#include <sstream>

#include <cxxtest/TestSuite.h>

class MVecTest : public CxxTest::TestSuite {
public:
  void testDefault() {
    MVec a;
    TS_ASSERT_DELTA(a.getX(), 0.0, 0.01);
    TS_ASSERT_DELTA(a.getY(), 0.0, 0.01);
  }

  void testGets0() {
    MVec a(5,0);
    TS_ASSERT_DELTA(a.getX(), 5.0, 0.01);
    TS_ASSERT_DELTA(a.getY(), 0.0, 0.01);
  }
  
  void testGet1() {
    MVec a(0, 5);
    TS_ASSERT_DELTA(a.getX(), 0, 0.01);
    TS_ASSERT_DELTA(a.getY(), 5, 0.01);
  }
  
  void testGet2() {
    MVec a(5, 5);
    TS_ASSERT_DELTA(a.getX(), 5, 0.01);
    TS_ASSERT_DELTA(a.getY(), 5, 0.01);
  }
  
  void testMag1() {
    MVec a(5,0);
    TS_ASSERT_DELTA(a.getMagnitude(), 5, 0.01);
  }
  
  void testMag2() {
    MVec a(3, 4);
    TS_ASSERT_DELTA(a.getMagnitude(), 5, 0.01);
  }
  
  void testAdd1() {
    MVec a(5,0);
    MVec b(5,0);
    MVec c = a + b;
    TS_ASSERT_DELTA(c.getMagnitude(), 10, 0.01);
  }
  
  void testAdd2() {
    MVec a(5,0);
    MVec b(0,5);
    MVec c = a + b;
    TS_ASSERT_DELTA(c.getMagnitude(), sqrt(5*5 + 5*5), 0.01);
  }
  
  void testAdd3() {
    MVec a(5,0);
    MVec b(-5,0);
    MVec c = a + b;
    TS_ASSERT_DELTA(c.getMagnitude(), 0, 0.01);
  }
  
  void testAdd4() {
    MVec a(5,0);
    MVec b(-5,0);
    MVec c = a + b + a;
    TS_ASSERT_DELTA(c.getMagnitude(), 5, 0.01);
  }
  
  void testAdd5() {
    MVec a(1.1,0);
    MVec c(0,0);
    for(int i = 0; i < 10; i++){
      c = c + a;
    }
    TS_ASSERT_DELTA(c.getMagnitude(), 11.0, 0.01);
  }
  
  void testAdd6() {
    MVec a;
    MVec b(-5,0);
    MVec c = a + b;
    TS_ASSERT_DELTA(c.getMagnitude(), 5, 0.01);
  }
  
  void testAdd7() {
    MVec a(5,0);
    MVec b;
    MVec c = a + b;
    TS_ASSERT_DELTA(c.getMagnitude(), 5, 0.01);
  }
  
  void testCompare1() {
    MVec a(5,0);
    MVec b(-5,0);
    TS_ASSERT(a != b);
  }
  
  void testCompare2() {
    MVec a(5,0);
    MVec b(5,0);
    TS_ASSERT(a == b);
  }
  
  void testCompare3() {
    MVec a(5,0);
    MVec b(5.011,0);
    TS_ASSERT(a != b);
  }
  
  void testCompare4() {
    MVec a(5.00, 0);
    MVec b(5.009, 0);
    TS_ASSERT(a == b);
  }
  
  void testMultiply1() {
    MVec a(5.00,0);
    MVec b = a * 5.0;
    TS_ASSERT_DELTA(b.getMagnitude(), 25, 0.01);
  }
  
  void testMultiply2() {
    MVec a(5.00,0);
    MVec b = a * -5.0;
    TS_ASSERT_DELTA(b.getMagnitude(), 25, 0.01);
  }
  
  void testStream0() {
    MVec a;
    stringstream out;
    out << a;
    TS_ASSERT_EQUALS(out.str(), "x: 0 y: 0");
  }
  
  void testStream1() {
    MVec a(5.00,0);
    stringstream out;
    out << a;
    TS_ASSERT_EQUALS(out.str(), "x: 5 y: 0");
  }
  
  void testStream2() {
    MVec a(5.00,5.00);
    stringstream out;
    out << a;
    TS_ASSERT_EQUALS(out.str(), "x: 5 y: 5");
  }
  
  void testStream3() {
    MVec a(0.00,5.00);
    stringstream out;
    out << a;
    TS_ASSERT_EQUALS(out.str(), "x: 0 y: 5");
  }
  
  void testStream4() {
    MVec a(0.00,5.00);
    MVec b(5.00, 0.00);
    MVec c = a + b;
    stringstream out;
    out << c;
    TS_ASSERT_EQUALS(out.str(), "x: 5 y: 5");
  }
  
  void testStream5() {
    MVec a(0.00,5.00);
    MVec b(5.00, 0.00);
    MVec c = a + b;
    stringstream out;
    out << c << " " << c;
    TS_ASSERT_EQUALS(out.str(), "x: 5 y: 5 x: 5 y: 5");
  }


};
