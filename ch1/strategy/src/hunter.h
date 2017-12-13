#ifndef HUNTER_H_
#define HUNTER_H_
#include <iostream>
#include <memory>
#include "behavior.h"

class Hunter {
protected:
  std::shared_ptr<QuackBehavior> quackBehavior_;
public:
  void Display() {
    std::cout << "I am a Hunter" << std::endl;
  }
  void FakeQuack() {
    //quackBehavior_->Quack();
    std::shared_ptr<QuackBehavior> qb(new Squeak());
    qb->Quack();
  }

  void SetQuackBehavior(std::shared_ptr<QuackBehavior> qb) {
    quackBehavior_ = qb;
  }
};

#endif  // HUNTER_H_
