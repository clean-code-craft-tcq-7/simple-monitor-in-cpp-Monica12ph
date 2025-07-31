#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool isTemperatureNormal(float temperature);
bool isPulseRateNormal(float pulseRate);
bool isSpo2Normal(float spo2);
bool areAllVitalsNormal(float temperature, float pulseRate, float spo2);
int vitalsOk(float temperature, float pulseRate, float spo2);


bool isTemperatureNormal(float temperature) {
  return temperature >= 95 && temperature <= 102;
}

bool isPulseRateNormal(float pulseRate) {
  return pulseRate >= 60 && pulseRate <= 100;
}

bool isSpo2Normal(float spo2) {
  return spo2 >= 90;
}

void showAlertAnimation() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

void displayAlert(const char* message) {
  cout << message << "\n";
  showAlertAnimation();
}


bool areAllVitalsNormal(float temperature, float pulseRate, float spo2) {
  return isTemperatureNormal(temperature) &&
         isPulseRateNormal(pulseRate) &&
         isSpo2Normal(spo2);
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (areAllVitalsNormal(temperature, pulseRate, spo2)) {
    return 1;
  }

  // At this point, we know at least one vital is abnormal
  if (!isTemperatureNormal(temperature)) {
    displayAlert("Temperature is critical!");
  } else if (!isPulseRateNormal(pulseRate)) {
    displayAlert("Pulse Rate is critical!");
  } else {
    displayAlert("Oxygen Saturation critical!");
  }
  return 0;
}