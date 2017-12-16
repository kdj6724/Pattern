#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_
#include <iostream>
class FlyBehavior {
public:
  virtual void Fly() = 0;
};
class FlyWithWings : public FlyBehavior {
public:
  virtual void Fly() {
    std::cout << "I am flying" << std::endl;
  }
};

class FlyNoWay : public FlyBehavior {
public:
  virtual void Fly() {
    std::cout << "I can not fly" << std::endl;
  }
};

class FlyRocketPowered : public FlyBehavior {
public:
  virtual void Fly() {
    std::cout << "I am flying with a rocket" << std::endl;
  }
};

class QuackBehavior {
public:
  virtual void Quack() = 0;
};
class MuteQuack : public QuackBehavior {
  virtual void Quack() {
    std::cout << "<< Silence >>" << std::endl;
  }
};

class Squeak : public QuackBehavior {
  virtual void Quack() {
    std::cout << "Squeak" << std::endl;
  }
};
#endif  // BEHAVIOR_H_
