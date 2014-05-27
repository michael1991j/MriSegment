/*
 * MRIOpenCVSettings.h
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#ifndef MRIOPENCVSETTINGS_H_
#define MRIOPENCVSETTINGS_H_
#include <pugixml.hpp>
#include <map>
#include <iostream>
#include <string>
using namespace std;
class MRIOpenCVSettings {
public:
	MRIOpenCVSettings();
	virtual ~MRIOpenCVSettings();
	void LoadSettings(char * Filelocation);
	double GetSettings(std::string section , std::string field , double defaultvalue);
	int GetSettings(std::string section , std::string field , int defaultvalue);
	char * GetSettings(std::string section , std::string field , char * defaultvalue);
private:
	pugi::xml_document doc;
	std::map< std::string, std::map<std::string ,std::string>* >  * table;
};

#endif /* MRIOPENCVSETTINGS_H_ */
