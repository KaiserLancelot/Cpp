//
// Created by kaiser on 19-4-11.
//

#include "weather_info.h"

QString WeatherInfo::GetCityName() const { return city_name_; }

void WeatherInfo::SetCityName(const QString& city_name) {
  city_name_ = city_name;
}

QDateTime WeatherInfo::GetDateTime() const { return date_time_; }

void WeatherInfo::SetDateTime(const QDateTime& date_time) {
  date_time_ = date_time;
}

double WeatherInfo::GetTemperature() const { return temperature_; }

void WeatherInfo::SetTemperature(double temperature) {
  temperature_ = temperature;
}

double WeatherInfo::GetHumidity() const { return humidity_; }

void WeatherInfo::SetHumidity(double humidity) { humidity_ = humidity; }

double WeatherInfo::GetPressure() const { return pressure_; }

void WeatherInfo::SetPressure(double pressure) { pressure_ = pressure; }

QString WeatherInfo::GetDesc() const { return desc_; }

void WeatherInfo::SetDesc(const QString& desc) { desc_ = desc; }

QString WeatherInfo::GetIcon() const { return icon_; }

void WeatherInfo::SetIcon(const QString& icon) { icon_ = icon; }
