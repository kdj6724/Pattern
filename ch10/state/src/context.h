#ifndef CONTEXT_H_
#define CONTEXT_H_
#include <memory>
#include "state.h"

class State;
class GumballMachine : 
    public std::enable_shared_from_this<GumballMachine> {
protected:
  std::shared_ptr<State> soldOutState_;
  std::shared_ptr<State> noQuarterState_;
  std::shared_ptr<State> hasQuarterState_;
  std::shared_ptr<State> soldState_;
  std::shared_ptr<State> state_;
  int count_ = 0;
public:
  virtual void Init(int numberGumballs);
  virtual void InsertQuarter();
  virtual void EjectQuarter();
  virtual void TurnCrank();
  virtual void SetState(std::shared_ptr<State> state);
  virtual void ReleaseBall();
  virtual int GetCount();
  virtual std::shared_ptr<State> GetSoldOutState();
  virtual std::shared_ptr<State> GetNoQuarterState();
  virtual std::shared_ptr<State> GetHasQuarterState();
  virtual std::shared_ptr<State> GetSoldState();
  virtual std::shared_ptr<State> GetCurrentState();
};
#endif  //  CONTEXT_H_
