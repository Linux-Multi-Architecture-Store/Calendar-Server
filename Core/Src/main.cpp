#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "about.h"
#include "cmdprocess.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Calendar Server");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION_NUMBER);
    auto cmd_processor=new CommandLineProcessor(&a);

    QObject::connect(cmd_processor, SIGNAL(finished()), &a, SLOT(quit()));

    QTimer::singleShot(0, cmd_processor, SLOT(startup()));
    return QCoreApplication::exec();
}
