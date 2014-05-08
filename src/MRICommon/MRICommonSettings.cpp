/*
 * MRICommonSettings.cpp
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#include "MRICommonSettings.h"

//! Constructor for function that pulls configuration data for MRICommon from a .xml file.
MRICommonSettings::MRICommonSettings() {
	// TODO Auto-generated constructor stub

}

//! Destructor for function that pulls configuration data for MRICommon from a .xml file.
MRICommonSettings::~MRICommonSettings() {
	// TODO Auto-generated destructor stub
}

//! Helper function to load the file.
/*!
 \param file Pointer to file path
 */
void MRICommonSettings::LoadSettings(char * file )
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

//! Helper function to pull settings from config file.
/*!
 \param section Pointer to section name within the config file.
 \param field Pointer to field name within the config file.
 \param defaultvalue Double containing defaultvalue if no value is found in the config file.
 \return double Double containing config file value or default value.
 */
double MRICommonSettings::GetSettings(char * section , char * field , double defaultvalue)
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

		    std:: cout <<  "you are missing this setting attribute therefore the default values was used\n";
		    return defaultvalue;
			}
			else
			{
				return  doc.child(section).child(field).text().as_double();
			}

		}


}

//! Helper function to pull settings from config file.
/*!
 \param section Pointer to section name within the config file.
 \param field Pointer to field name within the config file.
 \param defaultvalue Int containing defaultvalue if no value is found in the config file.
 \return int Int containing config file value or default value.
 */
int MRICommonSettings::GetSettings(char * section , char * field , int defaultvalue)
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

//! Helper function to pull settings from config file.
/*!
 \param section Pointer to section name within the config file.
 \param field Pointer to field name within the config file.
 \param defaultvalue Pointer to defaultvalue if no value is found in the config file.
 \return char Pointer containing config file value or default value.
 */
char * MRICommonSettings::GetSettings(char * section , char * field , char * defaultvalue)
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

		    std:: cout <<  "you are missing this setting attribute therefore the default values was used\n";
		    return defaultvalue;
			}
			else
			{
				return  (char *)doc.child(section).child(field).text().as_string();
			}

		}

}
