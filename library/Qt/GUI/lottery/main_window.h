//
// Created by kaiser on 19-4-15.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>

class MainWindow : public QMainWindow {
 public:
  MainWindow();

 private:
  void LoadData();

  QWidget* widget_;
  QSqlTableModel* model_;
  QTableView* view_;
  QPushButton* lottery_;

 private slots:
  void OnClickLottery();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_
