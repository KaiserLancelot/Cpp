//
// Created by kaiser on 19-4-11.
//

#include "net_worker.h"

#include <QNetworkRequest>

NetWorker* NetWorker::Instance() {
  static NetWorker net_worker;
  return &net_worker;
}

QNetworkReply* NetWorker::Get(const QString& url) const {
  return manager_->get(QNetworkRequest{url});
}

NetWorker::NetWorker() : manager_{new QNetworkAccessManager{this}} {
  connect(manager_, &QNetworkAccessManager::finished, this,
          &NetWorker::Finished);
}
