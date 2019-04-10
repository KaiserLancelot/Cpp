//
// Created by kaiser on 19-4-10.
//

#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QTableWidget table_widget;
  table_widget.resize(800, 600);
  table_widget.setColumnCount(3);
  table_widget.setRowCount(5);

  // Horizontal -- 横
  table_widget.setHorizontalHeaderLabels({"ID", "Name", "Age", "Sex"});

  table_widget.setItem(0, 0, new QTableWidgetItem("0001"));
  table_widget.setItem(1, 0, new QTableWidgetItem("0002"));
  table_widget.setItem(2, 0, new QTableWidgetItem("0003"));
  table_widget.setItem(3, 0, new QTableWidgetItem("0004"));
  table_widget.setItem(4, 0, new QTableWidgetItem("0005"));
  table_widget.setItem(0, 1, new QTableWidgetItem("20100112"));

  table_widget.show();

  QApplication::exec();
}
