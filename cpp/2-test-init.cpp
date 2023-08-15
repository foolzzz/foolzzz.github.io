#include <iostream>


class CA {

public:
  CA():x(666) {
    std::cout << "1111  " << x << std::endl;
    x = 999;
    std::cout << "2222  " << x << std::endl;
  }


public:
  int x;
};


int main() {
  CA a;

  std::cout << a.x << std::endl;
}
