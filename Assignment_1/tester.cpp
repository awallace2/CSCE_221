//unit tester for assignment 1
#include "my_string.h"

int main(){

  my_string name("Anders");

  cout << name[2] << endl;

  name += 'W';
  name += 'a';
  name += 'l';

  cout << endl;
  cout << name << endl;
  cout << name.size();

}
