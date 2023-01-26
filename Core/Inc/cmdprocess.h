//
// Created by 秦子若 on 2023/1/26.
//

#ifndef CALSRV_CMDPROCESS_H
#define CALSRV_CMDPROCESS_H

#include <QObject>
#include <QCoreApplication>


class CommandLineProcessor : public QObject {
Q_OBJECT
private:
    void Help();

    void Wait5Seconds();

    void WaitForInput();

    void DispatchCommand(const QString &command);

    void BeginNextLoop();

public:
    explicit CommandLineProcessor(QCoreApplication *parent = nullptr);

public slots:

    void startup();

    void beginNextLoop();

signals:

    void finished();
};


#endif //CALSRV_CMDPROCESS_H
