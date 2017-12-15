
#ifndef SUBJECT_H_
#define SUBJECT_H_
#include <memory>
#include "observer.h"

class Subject {
public:
  virtual void RegisterObserver(std::shared_ptr<Observer> op) = 0;
  virtual void RemoveObserver(std::shared_ptr<Observer> op) = 0;
  virtual void NotifyObserver() = 0;
};

#endif  //  SUBJECT_H_
