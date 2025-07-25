#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;




void alert_Animation() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}
void display_Alert(char* message)
{
  cout << message << "\n";
  alert_Animation();
}

bool within_Normal_Range(float value, float min, float max) {
  return value >= min && value <= max;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (!within_Normal_Range(temperature, 95, 102)) {
    display_Alert("Temperature is out of range!");
    return 0;
  } else if (!within_Normal_Range(pulseRate, 60, 100)) {
    display_Alert("Pulse Rate is out of range!");
    return 0;
  } else if (spo2 < 90) {
    display_Alert("Oxygen Saturation is out of range!");
    return 0;
  }
  return 1;
}

    