#ifndef DUCK_H_
#define DUCK_H_
#include <iostream>
#include <memory>
#include "behavior.h"

class Duck {
protected:
  std::shared_ptr<FlyBehavior> flyBehavior_;
  std::shared_ptr<QuackBehavior> quackBehavior_;
public:
  virtual void Display() = 0;
  void PerformFly() {
    flyBehavior_->Fly();
  }
  void PerformQuack() {
    quackBehavior_->Quack();
  }
  void SetFlyBehavior(std::shared_ptr<FlyBehavior> fb) {
    flyBehavior_ = fb;
  }
  void SetQuackBehavior(std::shared_ptr<QuackBehavior> qb) {
    quackBehavior_ = qb;
  }
  void Swim() {
    std::cout << "All docks float, even decoys!" << std::endl;
  }
};

class MallardDuck : public Duck {
public:
  MallardDuck() {
    std::shared_ptr<FlyBehavior> fb(new FlyWithWings());
    flyBehavior_ = fb;

    std::shared_ptr<QuackBehavior> qb(new Squeak());
    quackBehavior_ = qb;
  }
  virtual void Display() {
    std::cout << "I am a real Mallard duck" << std::endl;
  }
};

class ModelDuck : public Duck {
public:
  ModelDuck() {
    std::shared_ptr<FlyBehavior> fb(new FlyNoWay());
    flyBehavior_ = fb;

    std::shared_ptr<QuackBehavior> qb(new MuteQuack());
    quackBehavior_ = qb;
  }
  virtual void Display() {
    std::cout << "I am a model duck" << std::endl;
  }
};
#endif  // DUCK_H_
