
#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <iostream>
#include <memory>
#include "subject.h"
#include "weather_data.h"
#include "observer.h"

class DisplayElement {
public:
  virtual void Display() = 0;
};

class CurrentConditionsDisplay : public Observer,
    public DisplayElement,
    public std::enable_shared_from_this<Observer> {
private:
  float temperature_;
  float humidity_;
  std::shared_ptr<Subject> weatherData_;
public:
  CurrentConditionsDisplay(std::shared_ptr<Subject> weather) {
    weatherData_ = weather;
  }
  void Attach() {
    weatherData_->RegisterObserver(shared_from_this());
  }
  void Detach() {
    weatherData_->RemoveObserver(shared_from_this());
  }
  void Update(float temperature, float humidity, 
      float pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    Display();
  }
  void Display() {
    std::cout << "CurrentConditionsDisplay" << std::endl;
    std::cout << "temperature : " << temperature_ << std::endl;
    std::cout << "humidity : " << humidity_ << std::endl;
  }
};

class StatisticsDisplay : public Observer, 
    public DisplayElement,
    public std::enable_shared_from_this<Observer> {
private:
  float temperature_;
  float humidity_;

  std::shared_ptr<Subject> weatherData_;
public:
  StatisticsDisplay(std::shared_ptr<Subject> weather) {
    weatherData_ = weather;
  }
  void Attach() {
    weatherData_->RegisterObserver(shared_from_this());
  }
  void Detach() {
    weatherData_->RemoveObserver(shared_from_this());
  }
  void Update(float temperature, float humidity, 
      float pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    Display();
  }
  void Display() {
    std::cout << "StatisticsDisplay" << std::endl;
    std::cout << "temperature : " << temperature_ << std::endl;
    std::cout << "humidity : " << humidity_ << std::endl;
  }
};

class ForecastDisplay : public Observer, 
    public DisplayElement,
    public std::enable_shared_from_this<Observer> {
private:
  float temperature_;
  float humidity_;

  std::shared_ptr<Subject> weatherData_;
public:
  ForecastDisplay(std::shared_ptr<Subject> weather) {
    weatherData_ = weather;
  }
  void Attach() {
    weatherData_->RegisterObserver(shared_from_this());
  }
  void Detach() {
    weatherData_->RemoveObserver(shared_from_this());
  }
  void Update(float temperature, float humidity, 
      float pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    Display();
  }
  void Display() {
    std::cout << "ForecastDisplay" << std::endl;
    std::cout << "temperature : " << temperature_ << std::endl;
    std::cout << "humidity : " << humidity_ << std::endl;
  }
};
#endif  //  DISPLAY_H_
