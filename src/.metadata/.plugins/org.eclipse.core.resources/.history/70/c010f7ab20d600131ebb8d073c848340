/*
 * MRIOpenCVSettings.cpp
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#include "MRIOpenCVSettings.h"

MRIOpenCVSettings::MRIOpenCVSettings() {
	// TODO Auto-generated constructor stub

}

MRIOpenCVSettings::~MRIOpenCVSettings() {
	// TODO Auto-generated destructor stub
}

void MRIOpenCVSettings::LoadSettings(char * file )
{
	pugi::xml_parse_result result =  doc.load_file(file);
	if (result)
	{
		std::cout << "Configuration Was Loading \n";
	}
	else
	{
		std::cout << "there was an error when loading your configuration filed\n";
	}
}

double MRIOpenCVSettings::GetSettings(char * section , char * field , double defaultvalue)
{
	if(doc.child(section).empty())
		{

			std::cout << "the settings for this module operation is not present using Default values\n";
			return defaultvalue;
		}
		else
		{
			if(doc.child(section).child(field).empty())
			{

		    std:: cout <<  "you are missing this setting attribute therfore the defaul values was used\n";
		    return defaultvalue;
			}
			else
			{
				return  doc.child(section).child(field).text().as_double();
			}

		}


}

int MRIOpenCVSettings::GetSettings(char * section , char * field , int defaultvalue)
{
	if(doc.child(section).empty())
		{

			std::cout << "the settings for this module operation is not present using Default values\n";
			return defaultvalue;
		}
		else
		{
			if(doc.child(section).child(field).empty())
			{

		    std:: cout <<  "you are missing this setting attribute therfore the defaul values was used\n";
		    return defaultvalue;
			}
			else
			{
				return  doc.child(section).child(field).text().as_int();
			}

		}

}

char * MRIOpenCVSettings::GetSettings(char * section , char * field , char * defaultvalue)
{
	if(doc.child(section).empty())
		{

			std::cout << "the settings for this module operation is not present using Default values\n";
			return defaultvalue;
		}
		else
		{
			if(doc.child(section).child(field).empty())
			{

		    std:: cout <<  "you are missing this setting attribute therfore the defaul values was used\n";
		    return defaultvalue;
			}
			else
			{
				return  (char *)doc.child(section).child(field).text().as_string();
			}

		}

}
