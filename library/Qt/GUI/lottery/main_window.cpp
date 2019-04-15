// l
// Created by kaiser on 19-4-15.
//

#include "main_window.h"

#include <cstdint>
#include <random>
#include <unordered_set>

#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlRecord>

MainWindow::MainWindow()
    : widget_{new QWidget{this}},
      model_{new QSqlTableModel{widget_}},
      view_{new QTableView{widget_}},
      lottery_{new QPushButton{"抽奖", widget_}} {
  resize(1600, 1200);
  setWindowTitle("抽奖系统");

  auto layout{new QHBoxLayout};
  layout->addWidget(view_);
  layout->addWidget(lottery_);
  widget_->setLayout(layout);

  setCentralWidget(widget_);

  LoadData();

  connect(lottery_, &QPushButton::clicked, this, &MainWindow::OnClickLottery);
}

void MainWindow::LoadData() {
  // TODO 数据库删除连接问题
  auto db{QSqlDatabase::database()};

  if (!db.open()) {
    QMessageBox::critical(this, "错误", "无法连接用户数据库");
    QApplication::exit(EXIT_FAILURE);
  }

  model_->setTable("person");
  model_->setHeaderData(0, Qt::Horizontal, "编号");
  model_->setHeaderData(1, Qt::Horizontal, "姓名");
  model_->select();

  view_->setModel(model_);
  view_->setSelectionMode(QAbstractItemView::SingleSelection);
  view_->setSelectionBehavior(QAbstractItemView::SelectRows);
  view_->resizeColumnsToContents();
  view_->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::OnClickLottery() {
  static std::default_random_engine e{std::random_device{}()};
  static std::uniform_int_distribution<std::int32_t> uid{
      0, model_->rowCount() - 1};
  static std::unordered_set<std::int32_t> set;

  std::int32_t num{};

  do {
    num = uid(e);
  } while (set.find(num) != std::end(set));

  set.insert(num);

  QMessageBox::information(this, "中奖号码",
                           model_->record(num).value("id").toString() + " " +
                               model_->record(num).value("name").toString());
}
