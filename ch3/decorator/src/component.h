#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <string>
class Beverage {
protected:
  std::string description_ = "Unknown Beverage";
public:
  virtual std::string GetDescription() {
    return description_;
  }
  virtual double Cost() = 0;
};

class Esspresso : public Beverage {
public:
  Esspresso() {
    description_ = "Espresso";
  }
  virtual double Cost() {
    return 1.99;
  }
};

class HouseBlend : public Beverage {
public:
  HouseBlend() {
    description_ = "House Blend Coffee";
  }
  virtual double Cost() {
    return 0.89;
  }
};

class DarkRoast : public Beverage {
public:
  DarkRoast() {
    description_ = "Dark Roast Coffee";
  }
  virtual double Cost() {
    return 0.99;
  }
};

class Decaf : public Beverage {
public:
  Decaf() {
    description_ = "Decaf Coffee";
  }
  virtual double Cost() {
    return 1.05;
  }
};
#endif  // COMPONENT_H_

