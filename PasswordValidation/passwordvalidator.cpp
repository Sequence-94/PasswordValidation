#include "passwordvalidator.h"
#include "./ui_passwordvalidator.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QFont>

PasswordValidator::PasswordValidator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PasswordValidator)
{
    ui->setupUi(this);
    auto *mainLayout = new QVBoxLayout(this);

    auto *titleLabel = new QLabel("Password Validator",this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(17);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);


    auto *ruleGroupBox = new QGroupBox("Select Validation Rule",this);
    auto *ruleLayout = new QVBoxLayout(ruleGroupBox);

    rule1CheckBox = new QCheckBox("Rule 1: It must consist of a minimum of five characters and no spaces are allowed.", this);
    rule2CheckBox = new QCheckBox("Rule 2: It must consist of 5 characters, where the third character can be either a digit or an alphabetic character (a-f or A-F).", this);
    rule3CheckBox = new QCheckBox("Rule 3: It must consist of a minimum of four and a maximum of six digits and the starting digit cannot be 0.", this);

    ruleLayout->addWidget(rule1CheckBox);
    ruleLayout->addWidget(rule2CheckBox);
    ruleLayout->addWidget(rule3CheckBox);
    ruleGroupBox->setLayout(ruleLayout);


    auto *inputGroupBox = new QGroupBox("Enter Password",this);
    auto *inputLayout = new QGridLayout(inputGroupBox);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Enter your password");

    validateButton = new QPushButton("Validate", this);
    resultLabel = new QLabel(this);
    resultLabel->setAlignment(Qt::AlignCenter);

    inputLayout->addWidget(new QLabel("Password:"));
    inputLayout->addWidget(passwordLineEdit);
    inputLayout->addWidget(validateButton);
    inputLayout->addWidget(resultLabel);


    inputGroupBox->setLayout(inputLayout);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(ruleGroupBox);
    mainLayout->addWidget(inputGroupBox);

    this->setLayout(mainLayout);

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
        resultLabel->setStyleSheet("QLabel { color : green; }");

    } else {
        resultLabel->setText("Password is invalid");
        resultLabel->setStyleSheet("QLabel { color : red; }");

    }

}
PasswordValidator::~PasswordValidator()
{
    delete ui;
}
