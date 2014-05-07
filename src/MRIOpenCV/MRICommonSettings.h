/*
 * MRICommonSettings.h
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#ifndef MRICommonSETTINGS_H_
#define MRICommonSETTINGS_H_
#include <pugixml.hpp>

#include <iostream>
class MRICommonSettings {
public:
	MRICommonSettings();
	virtual ~MRICommonSettings();
	void LoadSettings(char * Filelocation);
	double GetSettings(char * section , char * field , double defaultvalue);
	int GetSettings(char * section , char * field , int defaultvalue);
	char * GetSettings(char * section , char * field , char * defaultvalue);
private:
	pugi::xml_document doc;
};

#endif /* MRICommonSETTINGS_H_ */
