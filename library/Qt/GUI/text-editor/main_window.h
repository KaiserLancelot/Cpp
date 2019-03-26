//
// Created by kaiser on 19-3-26.
//

#ifndef CPP_STUDY_MAIN_WINDOW_H
#define CPP_STUDY_MAIN_WINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QString>

class MainWindow : public QMainWindow {
 public:
  MainWindow();
  void CreateAction();
  void CreateConnect();
  void CreateMenu();
  void CreateToolBar();

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  QAction *new_action_;
  QAction *open_action_;
  QAction *save_action_;
  QAction *save_as_action_;

  QAction *paste_action_;
  QAction *copy_action_;
  QAction *cut_action_;

  QAction *exit_action_;
  QAction *about_action_;
  QAction *about_qt_action_;

  // 用于编辑和显示纯文本
  // 与 QTextEdit 非常相似, 但针对纯文本处理进行了优化
  QPlainTextEdit *text_edit_;

  QString file_path_;

  bool IsSaved();
  void LoadFile();
  void SaveFile();

 private slots:
  void New();
  void Open();
  void Save();
  void SaveAs();
  void About();
  void DocumentWasModified();
};

#endif  // CPP_STUDY_MAIN_WINDOW_H
