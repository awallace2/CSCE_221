//unit tester for assignment 1
#include "my_string.h"

int main(){

  my_string name("Anders");
  my_string last_name("Wallace");
  my_string test("Something");
  my_string test2;

  name += ' ';
  name += last_name;
  
  cout << name.size() << endl;
  
  cin >> test2;
  
  cout << endl;

  test = test2;

  cout << endl;
  cout << name << endl;
  cout << test << endl;
  //cout << test[0] << endl;
  //cout << test[13] << endl;
  cout << test.size();

}
