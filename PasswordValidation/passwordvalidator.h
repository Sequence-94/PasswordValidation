#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QWidget>

class QCheckBox;
class QLineEdit;
class QPushButton;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui {
class PasswordValidator;
}
QT_END_NAMESPACE

class PasswordValidator : public QWidget
{
    Q_OBJECT

public:
    PasswordValidator(QWidget *parent = nullptr);
    ~PasswordValidator();

private slots:
    void validatePassword();

private:
    Ui::PasswordValidator *ui;

    bool validateRule1(const QString &password);
    bool validateRule2(const QString &password);
    bool validateRule3(const QString &password);

    QCheckBox *rule1CheckBox;
    QCheckBox *rule2CheckBox;
    QCheckBox *rule3CheckBox;
    QLineEdit *passwordLineEdit;
    QPushButton *validateButton;
    QLabel *resultLabel;

};
#endif // PASSWORDVALIDATOR_H
