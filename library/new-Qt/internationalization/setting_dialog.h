//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_SETTING_DIALOG_H_
#define CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_SETTING_DIALOG_H_

#include <QComboBox>
#include <QDialog>
#include <QEvent>
#include <QLabel>
#include <QMetaType>

enum class Language { kChinese, kEnglish };

// 这个宏用来注册一个类(含默认构造 默认析构 拷贝构造函数)
// 为 QMetaType 类型, 注册后的类型可以作为 QVariant 的自定义类型
// 这个应该放在类或者结构体定义之后
// 并且在命名空间之外
// 继承自 QObject 的指针类型是自动注册的
Q_DECLARE_METATYPE(Language)

class SettingDialog : public QDialog {
  Q_OBJECT
 public:
  explicit SettingDialog(QWidget *parent = nullptr);

 protected:
  void changeEvent(QEvent *event) override;

 private:
  void TranslateUi();

  QLabel *label_;
  QLabel *language_label_;
  QComboBox *language_combo_box_;

 public:
 signals:
  void SwitchLanguage(Language language);

 private slots:
  void OnIndexChanged();
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_INTERNATIONALIZATION_SETTING_DIALOG_H_
