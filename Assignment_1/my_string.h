//my_string.h
#ifndef MY_STRING
#define MY_STRING
#include <iostream>
#include <stdexcept>

using namespace std;

class my_string {
public:
  my_string();
  my_string(char* cstring);
  const int size(void) { return ptr[index]; }


private:
  char* ptr; //pointer to the dynamic array of type char
  int sz; //number of characters in the string
  int cap; //length in bytes of the allocated memory pointed to by ptr




};

char operator[](int i);
ostream& operator<<(ostream& os, const my_string& string);

#endif
