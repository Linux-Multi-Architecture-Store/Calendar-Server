#include <QCoreApplication>
#include <QDebug>
#include "about.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    CSabout::PrintCompilerInfo();
    return QCoreApplication::exec();
}
