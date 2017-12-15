
#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
  virtual void Update(float temperature, float humidity,
      float pressure) = 0;
  virtual void Attach() = 0;
  virtual void Detach() = 0;
};
#endif  //  OBSERVER_H_
