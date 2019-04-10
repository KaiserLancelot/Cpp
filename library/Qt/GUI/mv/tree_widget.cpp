//
// Created by kaiser on 19-4-10.
//

#include <QApplication>
#include <QList>
#include <QTreeWidget>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QTreeWidget tree_widget;
  tree_widget.resize(800, 600);

  tree_widget.setHeaderLabels({"Name", "Number"});

  // 设定列数
  // tree_widget.setColumnCount(1);

  // 隐藏表头
  // tree_widget.setHeaderHidden(true);

  auto root{new QTreeWidgetItem{&tree_widget, {"Root", "0"}}};
  new QTreeWidgetItem{root, {"Leaf 1", "1"}};
  auto leaf2{new QTreeWidgetItem{root, {"Leaf 2", "2"}}};
  leaf2->setCheckState(0, Qt::Checked);

  QList<QTreeWidgetItem *> list;
  list << root;
  tree_widget.insertTopLevelItems(0, list);

  tree_widget.show();

  QApplication::exec();
}
