#include <iostream>

class People {
public:
  People(int age): age_(age) {
    std::cout << "init function called" << std::endl;
  }

  People(const People &p): age_(p.age_) {
    std::cout << "copy init function called" << std::endl;
  }

private:
  int age_;
};

int main(int argc, char *argv[]) {
  People p1(18);
  People p2(19);
  std::cout << "p1.addr: " << &p1 << std::endl;
  std::cout << "p2.addr: " << &p2 << std::endl;

  People p3(p1);
  std::cout << "p3.addr: " << &p3 << std::endl;

  p3 = p2;
  std::cout << "p3.addr: " << &p3 << std::endl;

  /*
  conclusion: 对象赋值会调用到拷贝构造函数.
  */

}
