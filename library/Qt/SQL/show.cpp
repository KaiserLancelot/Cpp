//
// Created by kaiser on 19-4-10.
//

#include <cstdlib>

#include <QApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QWidget widget;
  widget.resize(1200, 1000);

  auto db{QSqlDatabase::addDatabase("QMYSQL")};
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("524321");
  db.setDatabaseName("example");

  if (!db.open()) {
    QMessageBox::critical(&widget, "Error", "Can not connect this database");
    return EXIT_FAILURE;
  } else {
    auto model{new QSqlTableModel{&widget}};
    model->setTable("student");
    // AscendingOrder -- 升序
    model->setSort(0, Qt::AscendingOrder);
    // Horizontal -- 横
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "name");
    model->setHeaderData(2, Qt::Horizontal, "dept_name");
    model->setHeaderData(3, Qt::Horizontal, "tot_cred");
    model->select();

    auto view{new QTableView{&widget}};
    view->setModel(model);
    // 单行选择(如果是多行选择的话效果和按 CTRL 选择效果一样)
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    // 按行选择
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 每列宽度适配其内容
    view->resizeColumnsToContents();
    // 禁用编辑功能
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置表头的最后一列是拉伸的, 也就是会占用所有剩余可用空间
    view->horizontalHeader()->setStretchLastSection(true);

    view->resize(widget.size());

    widget.show();
  }

  return QApplication::exec();
}
