#ifndef WIZARDDATACONFIG_H
#define WIZARDDATACONFIG_H
#include <QString>

class WizarddataConfig
{
public:
    WizarddataConfig();
    int state;
    QString * cube_fat_directory;
    QString * cube_water_directory;
    QString * gre_water_directory;

};

#endif // WIZARDDATACONFIG_H
