//my_string.cpp file
#include "my_string.h"

// constructor with no input
my_string::my_string(){
  ptr = nullptr;
  sz = 0;
  cap = 0;
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

// constructor with size n as an argument
my_string::my_string(int n){
	sz = 0;
	cap = n;
	ptr = new char[cap];
}

// copy constructor
my_string::my_string(my_string& input_string){
	ptr = new char[input_string.size()];
	for(int i = 0; i < input_string.size(); i++){
		ptr[i] = input_string[i];
	}
	sz = input_string.size();
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

// resizes string to accomodate more characters
void my_string::resize(int size){
	if(ptr == NULL){
		sz = 0;
		cap = size;
		ptr = new char[sz];
		return;
	}
	else{
		delete[] ptr;
		sz = 0;
		cap = size;
		ptr = new char[sz];
		return;
	}
}

// inputs characters to a string
void my_string::input(char* input, int size){
	for(int i = 0; i < size; i++){
		ptr[i] = input[i];
	}
	return;
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

// assignment operator
my_string& my_string::operator=(my_string& rhs) {
  if(&rhs == this){ //check if the strings are equivilent so as not to copy the same thing
    return *this;
  }
  delete[] ptr; //delete old data
  sz = rhs.size();
  cap = rhs.size();
  ptr = new char[rhs.size()];
  for(int i = 0; i < rhs.size(); i++){
    ptr[i] = rhs[i];
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
istream& operator>>(istream& is, my_string& str){
  char input[256];
  int index = 0;
  cin.getline(input, 256, '\n');
  while(input[index] != '\0'){
    str += input[index];
    index++;
  }
   return is;


 }
