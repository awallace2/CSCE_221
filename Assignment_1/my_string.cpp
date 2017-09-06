//my_string.cpp file
#include "my_string.h"

// overloaded output operator
my_string::my_string(){
  char* ptr = nullptr;
  int sz = 0;
  int cap = 0;
}

//consructor with cstring input
my_string::my_string(char* cstring){
    int sz = 0;
    int counter = 0;
    while(cstring[counter] != '\0'){
      counter++;
    }
    sz = counter;
    char* ptr = new char[sz];
    for(int i = 0; i < sz; i++){
      ptr[i] = cstring[i];
    }
    cap = sz;
}


//overloaded output operator
ostream& operator<<(ostream& os, const my_string& string){
    for(int i = 0; i < string.size(); i++){
      os << string[i];
    }

    return os;
}
