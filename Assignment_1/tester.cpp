//unit tester for assignment 1
#include "my_string.h"

int main(){

  my_string name("Anders");
  my_string last_name("Wallace");

  cout << name[2] << endl;

  name += ' ';
  name += last_name;

  cout << endl;
  cout << name << endl;
  cout << name.size();

}
