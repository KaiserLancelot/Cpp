//
// Created by kaiser on 19-4-15.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>
#include <QTimer>
#include <QWidget>

class MainWindow : public QMainWindow {
 public:
  MainWindow();
  ~MainWindow() override;

 private:
  void LoadData();

  QWidget* widget_;
  QSqlTableModel* model_;
  QTableView* view_;
  QLabel* lottery_num_;
  QPushButton* lottery_;

  QTimer* timer_;

 private slots:
  void OnClickLottery();
  void ChangeLotteryNumLabel();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_MAIN_WINDOW_H_
