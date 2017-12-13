#include <memory>
#include <iostream>
#include "duck.h"
#include "hunter.h"
#include "behavior.h"

int main(void) {
  std::shared_ptr<Duck> mallard(new MallardDuck());
  mallard->PerformQuack();
  mallard->PerformFly();

  std::cout << "change behavior" << std::endl;
  std::shared_ptr<FlyBehavior> fb(new FlyRocketPowered());
  mallard->SetFlyBehavior(fb);
  mallard->PerformFly();

  std::shared_ptr<Hunter> hunter(new Hunter());
  hunter->Display();
  hunter->FakeQuack();

  return 0;
}
