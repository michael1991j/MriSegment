#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QPainterPath>
class Record
{
public:
    Record();
    QString Filename;
    int index;
    QPainterPath path;
    int Z;


};

#endif // RECORD_H
