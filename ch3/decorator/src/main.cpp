#include "decorator.h"
#include "component.h"
#include <memory>

int main(void) {
  std::shared_ptr<Beverage> beverage(new Esspresso());
  std::shared_ptr<Beverage> beverage2(new SteamedMilk(beverage));
  std::shared_ptr<Beverage> beverage3(new Soy(beverage2));
  std::shared_ptr<Beverage> beverage4(new Mocha(beverage3));
  std::shared_ptr<Beverage> beverage5(new Whip(beverage4));
  std::cout << beverage5->GetDescription() <<
      " $" << beverage5->Cost() << std::endl;
  return 0;
}
