
#ifndef WEATHER_DATA_H_
#define WEATHER_DATA_H_

#include <iostream>
#include <list>
#include <memory>
#include "observer.h"
#include "subject.h"

class WeatherData : public Subject {
private:
  std::list<std::shared_ptr<Observer>> list_;
  float temperatures_;
  float humidity_;
  float pressure_;
public:
  virtual void RegisterObserver(std::shared_ptr<Observer> op) {
    list_.push_back(op);
  }
  virtual void RemoveObserver(std::shared_ptr<Observer> op) {
    list_.remove(op);
  }
  virtual void NotifyObserver() {
    for (auto it : list_) {
      it->Update(temperatures_, humidity_, pressure_);
    }
  }
  void MeasurementsChanged() {
    NotifyObserver();
  }
  void SetMeasurements(float temperature, float humidity, 
      float pressure) {
    temperatures_ = temperature;
    humidity_ = humidity;
    pressure_ = pressure;
    MeasurementsChanged();
  }
};
#endif  // WEATHER_DATA_H_
