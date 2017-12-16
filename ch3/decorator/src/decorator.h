#ifndef DECORATOR_H_
#define DECORATOR_H_
#include <iostream>
#include <string>
#include <memory>
#include "component.h"
class CondimentDecorator : public Beverage {
public:
  virtual std::string GetDescription() = 0;
};

class Mocha : public CondimentDecorator {
private:
  std::shared_ptr<Beverage> beverage_; 
public:
  Mocha(std::shared_ptr<Beverage> beverage) {
    beverage_ = beverage;
  }
  virtual std::string GetDescription() {
    return beverage_->GetDescription() + ", Mocha";
  }
  virtual double Cost() {
    return beverage_->Cost() + 0.20;
  }
};

class SteamedMilk : public CondimentDecorator {
private:
  std::shared_ptr<Beverage> beverage_; 
public:
  SteamedMilk(std::shared_ptr<Beverage> beverage) {
    beverage_ = beverage;
  }
  virtual std::string GetDescription() {
    return beverage_->GetDescription() + ", Steamed Mili";
  }
  virtual double Cost() {
    return beverage_->Cost() + 0.10;
  }
};

class Soy : public CondimentDecorator {
private:
  std::shared_ptr<Beverage> beverage_; 
public:
  Soy(std::shared_ptr<Beverage> beverage) {
    beverage_ = beverage;
  }
  virtual std::string GetDescription() {
    return beverage_->GetDescription() + ", Soy";
  }
  virtual double Cost() {
    return beverage_->Cost() + 0.15;
  }
};

class Whip : public CondimentDecorator {
private:
  std::shared_ptr<Beverage> beverage_; 
public:
  Whip(std::shared_ptr<Beverage> beverage) {
    beverage_ = beverage;
  }
  virtual std::string GetDescription() {
    return beverage_->GetDescription() + ", Whip";
  }
  virtual double Cost() {
    return beverage_->Cost() + 0.10;
  }
};
#endif  //  DECORATOR_H_
