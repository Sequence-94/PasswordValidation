/********************************************************************************
** Form generated from reading UI file 'passwordvalidator.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDVALIDATOR_H
#define UI_PASSWORDVALIDATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordValidator
{
public:

    void setupUi(QWidget *PasswordValidator)
    {
        if (PasswordValidator->objectName().isEmpty())
            PasswordValidator->setObjectName("PasswordValidator");
        PasswordValidator->resize(800, 600);

        retranslateUi(PasswordValidator);

        QMetaObject::connectSlotsByName(PasswordValidator);
    } // setupUi

    void retranslateUi(QWidget *PasswordValidator)
    {
        PasswordValidator->setWindowTitle(QCoreApplication::translate("PasswordValidator", "PasswordValidator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordValidator: public Ui_PasswordValidator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDVALIDATOR_H
