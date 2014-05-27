#ifndef DATASET_H
#define DATASET_H
#include <MRICommon.h>
#include <LabeledResults.h>

class Config_MriCommon
 {
  public :
    Config_MriCommon()
    {
       this->totran=0;
       this->tosag = 0;
       this->tocor = 0;
    }
    int id;
    MRICommon * imageset;
    int totran;
    int tocor;
    int tosag;
    QString  FilePath;
 };

class Config_Labeledcartilage
 {
  public:
    Config_Labeledcartilage()
    {
        this->id =0;
    }
    int id;
    LabeledResults * results;
    QString  PCLpath;
    QString  VTK;
 };

class Dataset
{
public:
    Dataset();
    bool  load(QString  filepath);
    bool  Savetofile(QString save);
    vector<Config_Labeledcartilage *> * Labels;
    vector<Config_MriCommon *> * Imagesets;
    QString destinationpath;
};

#endif // DATASET_H
