#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void delay(int seconds) {
  sleep_for(std::chrono::seconds(seconds));
}

void (*delaypointer)(int) = delay;

void delayfunction(void (*delayfunc)(int))
{
  delaypointer = delayfunc;
}


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
   delaypointer(1);
    cout << "\r *" << flush;
   delaypointer(1);
  }
}

void displayAlert(const char* message) {
  cout << message << "\n";
  showAlertAnimation();
}

bool checkAndAlert(bool condition, const char* message) {
  if (!condition) {
    displayAlert(message);
    return false;
  }
  return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return checkAndAlert(isTemperatureNormal(temperature), "Temperature is critical!") &&
         checkAndAlert(isPulseRateNormal(pulseRate), "Pulse Rate is critical!") &&
         checkAndAlert(isSpo2Normal(spo2), "Oxygen Saturation critical!");
}
