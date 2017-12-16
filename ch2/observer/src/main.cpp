#include <iostream>
#include <memory>
#include "weather_data.h"
#include "display.h"

int main(void) {
  std::shared_ptr<WeatherData> weatherData(new WeatherData());
  std::shared_ptr<Observer> currendDisplay
      (new CurrentConditionsDisplay(weatherData));
  std::shared_ptr<Observer> statisticsDisplay
      (new StatisticsDisplay(weatherData));
  std::shared_ptr<Observer> forecastDisplay
      (new ForecastDisplay(weatherData));

  currendDisplay->Attach();
  statisticsDisplay->Attach();
  forecastDisplay->Attach();

  std::cout << std::endl;
  weatherData->SetMeasurements(80, 65, 30.4f);
  std::cout << std::endl;
  weatherData->SetMeasurements(82, 70, 28.4f);
  std::cout << std::endl;
  statisticsDisplay->Detach();
  weatherData->SetMeasurements(78, 43, 11.4f);

  currendDisplay->Attach();
  forecastDisplay->Attach();
  return 0;
}
