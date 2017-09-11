//my_string.cpp file
#include "my_string.h"

// constructor with no input
my_string::my_string(){
  char* ptr = nullptr;
  int sz = 0;
  int cap = 0;
}

// destructor
my_string::~my_string() {
  delete[] ptr;
}

//consructor with cstring input
my_string::my_string(char* cstring){
    int index = 0;
    sz = 0;
    while(cstring[index] != '\0'){
      index += 1;
      sz += 1;
    }
    ptr = new char[sz];
    for(int i = 0; i < sz; i++){
      ptr[i] = cstring[i];
    }
    cap = sz;
}

// empty check
bool my_string::empty() {
  if(sz == 0){
    return true;
  }
  else {
    return false;
  }
}

// at() member function with bounds checking
char my_string::at(int i){
  if(i >= sz){
    throw out_of_range("Index out of range");
  }
  else {
    return *(ptr + i);
  }
}

// output operator
char my_string::operator[](int i) {
  return *(ptr + i);
}


// appending a character operator
my_string& my_string::operator+=(const char input){
  if(sz == cap){
    cap = 2 * cap;
    char* tempPtr = new char[cap];
    for(int i = 0; i < sz; i++) {
      tempPtr[i] = ptr[i];
    }
    sz = sz + 1;
    delete[] ptr;
    ptr = tempPtr;
    ptr[sz - 1] = input;
  }
  else {
    ptr[sz] = input;
    sz = sz + 1;
  }

  return *this;
}

// appending a string operator
my_string& my_string::operator+=(my_string& rhs){
  int i = 0;
  if(sz + rhs.size() > cap){
    cap = (2 * cap) + rhs.size();
    char* tempPtr = new char[cap];
    for(i = 0; i < sz; i++){
      tempPtr[i] = ptr[i];
    }
    for(i = 0; i < rhs.size(); i++){
      tempPtr[sz + i] = rhs[i];
    }
    delete[] ptr;
    ptr = tempPtr;
    sz = sz + rhs.size();
  }
  else{
    for(i = 0; i < rhs.size(); i++){
      ptr[sz + i] = rhs[i];
    }
    sz = sz + rhs.size();
  }

  return *this;
}


// overloaded output operator
ostream& operator<<(ostream& os, my_string string){
    for(int i = 0; i < string.size(); i++){
      os << string[i];
    }

    return os;
}

// overloaded input operator
// istream& operator>>(istream& is, my_string string){
//   int count = 0;
//   while(is){
//     count++;
//   }
//
// }
