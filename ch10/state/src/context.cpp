#include <iostream>
#include "context.h"
#include "state.h"

void GumballMachine::Init(int numberGumballs) {
  std::cout << __LINE__ << std::endl;
  soldOutState_ = std::shared_ptr<State> 
      (new SoldOutState(shared_from_this()));
  std::cout << __LINE__ << std::endl;
  noQuarterState_ = std::shared_ptr<State> 
      (new NoQuarterState(shared_from_this()));
  hasQuarterState_ = std::shared_ptr<State> 
      (new HasQuarterState(shared_from_this()));
  soldState_ = std::shared_ptr<State> 
      (new SoldState(shared_from_this()));
  count_ = numberGumballs; 
  if (numberGumballs > 0) {
    state_ = noQuarterState_;
  }
}

void GumballMachine::InsertQuarter() {
  if (state_ != NULL)
    state_->InsertQuarter();
}
void GumballMachine::EjectQuarter() {
  if (state_ != NULL)
    state_->EjectQuarter(); 
}
void GumballMachine::TurnCrank() {
  if (state_ != NULL) {
    state_->TurnCrank();
    state_->Dispense();
  }
}
void GumballMachine::SetState(std::shared_ptr<State> state) {
  state_ = state;
}
void GumballMachine::ReleaseBall() {
  std::cout << "A gumball comes rolling out the slot..."
      << std::endl;
  if (count_ != 0) {
    count_--;
  }
}

int GumballMachine::GetCount() {
  return count_;
}

std::shared_ptr<State> GumballMachine::GetSoldOutState() {
  return soldOutState_;
}
std::shared_ptr<State> GumballMachine::GetNoQuarterState() {
  return noQuarterState_;
}
std::shared_ptr<State> GumballMachine::GetHasQuarterState() {
  return hasQuarterState_;
}
std::shared_ptr<State> GumballMachine::GetSoldState() {
  return soldState_;
}
std::shared_ptr<State> GumballMachine::GetCurrentState() {
  return state_;
}
