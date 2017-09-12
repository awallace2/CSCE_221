//unit tester for assignment 1
#include "my_string.h"

int main(){

  my_string name("Anders");
  my_string last_name("Wallace");
  my_string test("Something");

  name += ' ';
  name += last_name;

  test = name;

  cout << endl;
  cout << name << endl;
  cout << test << endl;
  cout << test.size();

}
