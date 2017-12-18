#include <iostream>
#include "state.h"
#include "context.h"

NoQuarterState::NoQuarterState(std::shared_ptr<GumballMachine>
    gumballMachine) {
  gumballMachine_ = gumballMachine;
}
void NoQuarterState::InsertQuarter() {
  std::cout << "You inserted a quarter" << std::endl;
  gumballMachine_->SetState(
      gumballMachine_->GetHasQuarterState());
}
void NoQuarterState::EjectQuarter() {
  std::cout << "You have not insrted a quarter" 
      << std::endl;
}
void NoQuarterState::TurnCrank() {
  std::cout << "You turned, but there is no quarter" 
      << std::endl;
}
void NoQuarterState::Dispense() {
  std::cout << "You need to pay first" << std::endl;
}

HasQuarterState::HasQuarterState(std::shared_ptr<GumballMachine>
    gumballMachine) {
  gumballMachine_ = gumballMachine;
}
void HasQuarterState::InsertQuarter() {
  std::cout << "You can not insert another quarter" 
      << std::endl;
}
void HasQuarterState::EjectQuarter() {
  std::cout << "Quarter returned" << std::endl;
  gumballMachine_->SetState(
      gumballMachine_->GetNoQuarterState());
}
void HasQuarterState::TurnCrank() {
  std::cout << "You turned..." << std::endl;
  gumballMachine_->SetState(
      gumballMachine_->GetSoldState());
}
void HasQuarterState::Dispense() {
  std::cout << "No gumball dispensed" << std::endl;
}

SoldState::SoldState(std::shared_ptr<GumballMachine> gumballMachine) {
  gumballMachine_ = gumballMachine;
}
void SoldState::InsertQuarter() {
  std::cout << "Please wait, we are already giving you "
      << "a gumball" << std::endl;
}
void SoldState::EjectQuarter() {
  std::cout << "Sorry, you already turned the crank" 
      << std::endl;
}
void SoldState::TurnCrank() {
  std::cout << "Turning twice does not get you "
      << "another gumball!" << std::endl;
}
void SoldState::Dispense() {
  gumballMachine_->ReleaseBall();
  if (gumballMachine_->GetCount() > 0) {
    gumballMachine_->SetState(
        gumballMachine_->GetNoQuarterState());
  } else {
    std::cout << "Oops, out of gumballs!" << std::endl;
    gumballMachine_->SetState(
        gumballMachine_->GetSoldOutState());
  }
}

SoldOutState::SoldOutState(std::shared_ptr<GumballMachine>
    gumballMachine) {
  gumballMachine_ = gumballMachine;
}
void SoldOutState::InsertQuarter() {
  std::cout << "Sold out" << std::endl;
}
void SoldOutState::EjectQuarter() {
  std::cout << "Sold out" << std::endl;
}
void SoldOutState::TurnCrank() {
  std::cout << "Sold out" << std::endl;
}
void SoldOutState::Dispense() {
  std::cout << "Sold out" << std::endl;
}

