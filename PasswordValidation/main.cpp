#include "passwordvalidator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PasswordValidator w;
    w.setWindowTitle("Password Validator");
    w.resize(400, 200);
    w.show();
    return a.exec();
}
