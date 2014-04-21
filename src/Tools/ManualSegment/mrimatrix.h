#ifndef MRIMATRIX_H
#define MRIMATRIX_H

#include <QObject>

class MriMatrix : public QObject
{
    Q_OBJECT
public:
    explicit MriMatrix(QObject *parent = 0);
    void loadDir();
    int totalImage;
signals:
    
public slots:
    
};

#endif // MRIMATRIX_H
