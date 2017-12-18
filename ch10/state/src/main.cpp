#include <iostream>
#include "context.h"

int main(void) {
  std::shared_ptr<GumballMachine> 
      gumballMachine(new GumballMachine);
  gumballMachine->Init(5);

  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();
  gumballMachine->InsertQuarter();
  gumballMachine->TurnCrank();

  return 0;
}
