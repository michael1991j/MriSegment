/*
 * MRIOpenCVSettings.h
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#ifndef MRIOPENCVSETTINGS_H_
#define MRIOPENCVSETTINGS_H_
#include <pugixml.hpp>

#include <iostream>
class MRIOpenCVSettings {
public:
	MRIOpenCVSettings();
	virtual ~MRIOpenCVSettings();
	void LoadSettings(char * Filelocation);
	double GetSettings(char * section , char * field , double defaultvalue);
	int GetSettings(char * section , char * field , int defaultvalue);
	char * GetSettings(char * section , char * field , char * defaultvalue);
private:
	pugi::xml_document doc;
};

#endif /* MRIOPENCVSETTINGS_H_ */
