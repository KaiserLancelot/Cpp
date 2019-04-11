//
// Created by kaiser on 19-4-11.
//

#ifndef CPP_STUDY_LIBRARY_QT_NETWORK_NET_WORKER_H_
#define CPP_STUDY_LIBRARY_QT_NETWORK_NET_WORKER_H_

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QString>

class NetWorker : public QObject {
  Q_OBJECT
 public:
  NetWorker(const NetWorker&) = delete;
  NetWorker(NetWorker&&) = delete;
  NetWorker& operator=(const NetWorker&) = delete;
  NetWorker& operator=(NetWorker&&) = delete;

  static NetWorker* Instance();
  QNetworkReply* Get(const QString& url) const;

 signals:
  void Finished(QNetworkReply*);

 private:
  NetWorker();
  // 它默认是异步的, 网络访问并不会阻塞 GUI 界面
  QNetworkAccessManager* manager_;
};

#endif  // CPP_STUDY_LIBRARY_QT_NETWORK_NET_WORKER_H_
