#ifndef MRICOMMON_H
#define MRICOMMON_H
#include <cv.h>
#include <highgui.h>
#include <string>
#include <vector>
#include <qstringlist.h>
#include "../../Libary/library/imebra/include/imebra.h"
#include <sstream>
#ifdef PUNTOEXE_WINDOWS
#include <process.h>
#else
#include <spawn.h>
#include <sys/wait.h>
#endif
#include <memory>
#include <list>
#include <boost/archive/tmpdir.hpp>
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <QThreadPool>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include "dicomtomat.h"
using namespace boost::serialization;
using namespace boost;
BOOST_SERIALIZATION_SPLIT_FREE(cv::Mat);

using namespace puntoexe;
using namespace puntoexe::imebra;
using namespace cv;
using namespace std;
class  MriCommon {
public:
    MriCommon();
    vector<Mat> * sagtical;
    vector<Mat> * transversal;

    void LoadImages( QStringList *list);
    void ToTransversal();
    void Savemodel();
    void Loadmodel();
private:
    void processDicom(char * path);

};

#endif // MRICOMMON_H
