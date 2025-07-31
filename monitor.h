#pragma once

int vitalsOk(float temperature, float pulseRate, float spo2);
bool isTemperatureNormal(float temperature);
bool isPulseRateNormal(float pulseRate);
bool isSpo2Normal(float spo2);
void showAlertAnimation();
void displayAlert(const char* message);
bool checkAndAlert(bool condition, const char* message);