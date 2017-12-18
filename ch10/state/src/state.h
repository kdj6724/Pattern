#ifndef STATE_H_
#define STATE_H_
#include <iostream>
#include <memory>
#include "context.h"

class State {
public:
  virtual void InsertQuarter() = 0;
  virtual void EjectQuarter() = 0;
  virtual void TurnCrank() = 0;
  virtual void Dispense() = 0;
};

class GumballMachine;
class NoQuarterState : public State {
private:
  std::shared_ptr<GumballMachine> gumballMachine_;
public:
  NoQuarterState(std::shared_ptr<GumballMachine> 
     gumballMachine);
  virtual void InsertQuarter();
  virtual void EjectQuarter();
  virtual void TurnCrank();
  virtual void Dispense();
};

class HasQuarterState : public State {
private:
  std::shared_ptr<GumballMachine> gumballMachine_;
public:
  HasQuarterState(std::shared_ptr<GumballMachine>
      gumballMachine);
  virtual void InsertQuarter();
  virtual void EjectQuarter();
  virtual void TurnCrank();
  virtual void Dispense();
};

class SoldState : public State {
private:
  std::shared_ptr<GumballMachine> gumballMachine_;
public:
  SoldState(std::shared_ptr<GumballMachine> gumballMachine);
  virtual void InsertQuarter();
  virtual void EjectQuarter();
  virtual void TurnCrank();
  virtual void Dispense();
};
class SoldOutState : public State {
private:
  std::shared_ptr<GumballMachine> gumballMachine_;
public:
  SoldOutState(std::shared_ptr<GumballMachine>
      gumballMachine);
  virtual void InsertQuarter();
  virtual void EjectQuarter();
  virtual void TurnCrank();
  virtual void Dispense();
};
#endif  // MACHINE_STATE_H_
