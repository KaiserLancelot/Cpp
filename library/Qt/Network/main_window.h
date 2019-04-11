//
// Created by kaiser on 19-4-11.
//

#ifndef CPP_STUDY_LIBRARY_QT_NETWORK_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_QT_NETWORK_MAIN_WINDOW_H_

#include <QHash>
#include <QMainWindow>
#include <QString>

#include "net_worker.h"

enum class ReplyType { kWeather, kIcon };

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow();
  void FetchWeather(const QString &city_name);
  void FetchIcon(const QString &icon_name);

 private:
  NetWorker *net_worker_{NetWorker::Instance()};
  QHash<QNetworkReply *, ReplyType> reply_;
};

#endif  // CPP_STUDY_LIBRARY_QT_NETWORK_MAIN_WINDOW_H_
