#include "recordhandel.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
RecordHandel::RecordHandel()
{
    this->Records= new   QVector<Record>();
}

QString RecordHandel::OutputFinalPCDFile()
{
    QString accum="";
    int pointcount=0;

    for(int i = 0; i < this->Records->size(); i++)
    {
    Record r = this->Records->at(i);
    //accum += "\n\n#"+ r.Filename + "  "+ QString::number(r.index) + " \n";
    for( int j = 0; j < r.path.elementCount(); j++)
    {
    pointcount++;
    accum +=   QString::number(r.path.elementAt(j).x)+" "+  QString::number(r.path.elementAt(j).y)+" "+ QString::number(r.Z) +" 4.2108e+06\n";
    }
    }
    accum = "# .PCD v.7 - Point Cloud Data file format\nVERSION .7\nFIELDS x y z rgb\nSIZE 4 4 4 4\nTYPE F F F F\nCOUNT 1 1 1 1\nWIDTH "+ QString::number(pointcount)+"\nHEIGHT 1\nVIEWPOINT 0 0 0 1 0 0 0\nPOINTS "+ QString::number(pointcount)+"\nDATA ascii\n"+ accum;
    return accum;
}
