#include "passwordvalidator.h"
#include "./ui_passwordvalidator.h"
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

PasswordValidator::PasswordValidator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PasswordValidator)
{
    ui->setupUi(this);
    auto *layout = new QVBoxLayout(this);

    rule1CheckBox = new QCheckBox("Rule 1: It must consist of a minimum of five characters and no spaces are allowed.", this);
    rule2CheckBox = new QCheckBox("Rule 2: It must consist of 5 characters, where the third character can be either a digit or an alphabetic character (a-f or A-F).", this);
    rule3CheckBox = new QCheckBox("Rule 3: It must consist of a minimum of four and a maximum of six digits and the starting digit cannot be 0.", this);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Enter your password");

    validateButton = new QPushButton("Validate", this);
    resultLabel = new QLabel(this);

    layout->addWidget(rule1CheckBox);
    layout->addWidget(rule2CheckBox);
    layout->addWidget(rule3CheckBox);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(validateButton);
    layout->addWidget(resultLabel);

    connect(validateButton, &QPushButton::clicked, this, &PasswordValidator::validatePassword);
}

bool PasswordValidator::validateRule1(const QString &password) {
    return password.length() >= 5 && !password.contains(' ');
}

bool PasswordValidator::validateRule2(const QString &password)
{
    if(password.length() !=5){
        return false;
    }
    QChar thirdChar = password[2];
    return (thirdChar.isDigit()||(thirdChar.isLetter()&& thirdChar.toLower()>='a'&& thirdChar.toLower() <= 'f'));
}

bool PasswordValidator::validateRule3(const QString &password)
{
    if (password.length() < 4 || password.length() > 6) return false;
    if (password[0] == '0') return false;
    return password.toInt();
}

void PasswordValidator::validatePassword()
{
    QString password = passwordLineEdit->text();
    bool isValid = false;

    if (rule1CheckBox->isChecked()) {
        isValid = validateRule1(password);
    } else if (rule2CheckBox->isChecked()) {
        isValid = validateRule2(password);
    } else if (rule3CheckBox->isChecked()) {
        isValid = validateRule3(password);
    }

    if (isValid) {
        resultLabel->setText("Password is valid");
    } else {
        resultLabel->setText("Password is invalid");
    }

}
PasswordValidator::~PasswordValidator()
{
    delete ui;
}
