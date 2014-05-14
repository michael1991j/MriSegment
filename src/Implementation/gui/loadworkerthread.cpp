#include "loadworkerthread.h"


LoadWorkerthread::LoadWorkerthread(MRICommon * stack, QString path , int id,bool totran, bool tocorr )
{
this->stack = stack;
this->path = path;
this->id = id;
this->tocorr = tocorr;
this->totran = totran;
}

void LoadWorkerthread::run()
{
    QStringList nameFilter("*.dcm");
    QDir directory( this->path);
    QStringList files = directory.entryList(nameFilter);
    for (int i = 0; i < files.count(); i++)
        files[i] =
                QString(
                        this->path +"/")
                        + files[i];

    stack->LoadImages(&files);
    emit updatestatusid(id, 40);
    if(this->tocorr)
    stack->Data->ToCorronial();
    emit updatestatusid(id, 70);
    if(this->totran)
    stack->Data->ToTransversal();
    emit updatestatusid(id, 100);

}
