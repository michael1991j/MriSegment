#ifndef LOADWORKERTHREAD_H
#define LOADWORKERTHREAD_H
#include <MRICommon.h>
#include <QThread>
#include <QDir>
#include <QString>
#include <QObject>
class LoadWorkerthread: public QThread
{ Q_OBJECT

public:
    LoadWorkerthread(MRICommon * stack, QString path , int id , bool totran, bool tocorr  );
    QString path;
    MRICommon * stack;
    int  id;
    void run();
    bool totran;
    bool tocorr;
signals:
void updatestatusid(int id , int value);
};

#endif // LOADWORKERTHREAD_H
