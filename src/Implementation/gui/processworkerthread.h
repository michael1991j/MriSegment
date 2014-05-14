#ifndef PROCESSWORKERTHREAD_H
#define PROCESSWORKERTHREAD_H
#include <QThread>
#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
#include <LabeledResults.h>
#include <QThread>
#include <RunAll.h>
#include <RunAllPCLscripts.h>

class Processworkerthread: public QThread
{
    Q_OBJECT

public:
    Processworkerthread(int id, MRIOpenCVSettings * settings, vector<MRICommon *> * Imagesets,vector<LabeledResults *> * results  );
    MRIOpenCVSettings * settings;
    vector<MRICommon *> * Imagesets;
    vector<LabeledResults *> * results;
    int id;
    void run();
signals:
void updatestatusid(int id , int value);
};

#endif // PROCESSWORKERTHREAD_H
