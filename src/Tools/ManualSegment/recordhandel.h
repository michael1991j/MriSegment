#ifndef RECORDHANDEL_H
#define RECORDHANDEL_H
#include <vector>
#include "record.h"
#include <QString>
#include <QDataStream>
class RecordHandel
{
public:
    RecordHandel();
    QVector<Record> * Records;
    QString  OutputPCDforRecord(int i);
    QString  OutputFinalPCDFile();
    void Savetofile();


};

#endif // RECORDHANDEL_H
