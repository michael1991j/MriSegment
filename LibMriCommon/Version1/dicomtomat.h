#ifndef DICOMTOMAT_H
#define DICOMTOMAT_H
#include <QRunnable>
#include <cv.h>
#include <highgui.h>
#include <string>
#include <vector>
#include <qstringlist.h>
#include "../../Libary/library/imebra/include/imebra.h"
#include <sstream>
#include <string>
#ifdef PUNTOEXE_WINDOWS
#include <process.h>

#else
#include <spawn.h>
#include <sys/wait.h>
#endif
#include <memory>
#include <list>
using namespace std;
using namespace cv;
using namespace puntoexe;
using namespace puntoexe::imebra;
using namespace cv;
using namespace std;

class DicomtoMat : public QRunnable
{
public:
    DicomtoMat(int index, string file ,vector<Mat> * dest );
    vector<Mat> * sagtical;
    int index;
    string file;
    void run();

};

#endif // DICOMTOMAT_H
