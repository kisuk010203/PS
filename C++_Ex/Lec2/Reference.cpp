
/*
#include <iostream>
int change_val(int *p) {
  *p = 3;
  return 0;
}
int main() {
  int number = 5;
  std::cout << number << std::endl;
  change_val(&number);
  std::cout << number << std::endl;
}*/

/*
#include <iostream>

int main() {
  int a = 3;
  int& another_a = a;

  another_a = 5;
  std::cout << "a : " << a << std::endl;
  std::cout << "another_a : " << another_a << std::endl;

  return 0;
}*/

#include <iostream>

int function() {
    int a = 5;
    return a;
}

int main() {
    const int& c = function();
    std::cout << "c : " << c << std::endl;
    return 0;
}
