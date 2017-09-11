//my_string.h
#ifndef MY_STRING
#define MY_STRING
#include <iostream>
#include <stdexcept>

using namespace std;

class my_string {
public:
  my_string();
  ~my_string();
  my_string(char* cstring);
  int size() { return sz; }
  int capacity() { return cap; }
  bool empty();
  char at(int i);
  char operator[](int i);
  my_string& operator+=(const char a);
  my_string& operator+=(my_string& rhs);


private:
  char* ptr; //pointer to the dynamic array of type char
  int sz; //number of characters in the string
  int cap; //length in bytes of the allocated memory pointed to by ptr





};

ostream& operator<<(ostream& os, my_string string);
istream& operator>>(ifstream& is, my_string string);

#endif
