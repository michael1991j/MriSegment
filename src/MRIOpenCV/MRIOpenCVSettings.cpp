/*
 * MRIOpenCVSettings.cpp
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */



#include <sstream>
#include "MRIOpenCVSettings.h"
const char* node_types[] =
{
    "null", "document", "element", "pcdata", "cdata", "comment", "pi", "declaration"
};

//[code_traverse_walker_impl
struct simple_walker: pugi::xml_tree_walker
{
	std::map< std::string , std::map<std::string ,std::string>* > * table;

	simple_walker(	std::map< std::string , std::map<std::string ,std::string>* > * table)
		{
		this->table = table;

		}

    virtual bool for_each(pugi::xml_node& node)
    {
    	std::string parentname(node.parent().name());
    	std::string nodename( node.name());
    	std::string nodevalue( node.text().as_string());

        for (int i = 0; i < depth(); ++i) std::cout << "  "; // indentation
        if(depth() == 0 )
        {
        	std::cout << "group" << node.name() << "";
        	table->insert(std::pair<string,std::map<std::string ,std::string>*>(nodename, new std::map<string,string>()));
            std::cout << node_types[node.type()] << ": name='" << node.name() << "', value='" << node.value() << "'\n";

        }
        else if(depth() == 1 )
        {
        	if(table->count(parentname))
        	(*table)[ parentname]->insert(std::pair<string,string>(nodename , nodevalue));
        	else
        	{
        		std::cout << "does not exist \n\n";

        	}
        	std::cout << "group" << node.parent().name() << "\n";
        	std::cout << "setting : " <<  node.name() <<" value " << node.text().as_string() << "\n";




        }
        //std::cout << node_types[node.type()] << ": name='" << node.name() << "', value='" << node.value() << "'\n";

        return true; // continue traversal
    }
};
//]
//! Constructor for function that pulls configuration data for MRIOpenCV from a .xml file.
MRIOpenCVSettings::MRIOpenCVSettings() {
	// TODO Auto-generated constructor stub

}

//! Destructor for function that pulls configuration data for MRIOpenCV from a .xml file.
MRIOpenCVSettings::~MRIOpenCVSettings() {
	// TODO Auto-generated destructor stub
}

//! Helper function to load the file.
/*!
 \param file Pointer to file path
 */
void MRIOpenCVSettings::LoadSettings(char * file )
{
	pugi::xml_parse_result result =  doc.load_file(file);
	if (result)
	{
		std::cout << "Configuration Was Loading \n";
		table = new map< string  , map<string ,string>* >();
	    simple_walker walker(table);
	    doc.traverse(walker);

	    for (std::map<string, map<string,string> * >::iterator it=table->begin(); it!=table->end(); ++it)
	   		    std::cout << it->first  << '\n';

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
double MRIOpenCVSettings::GetSettings(string  section , string  field , double defaultvalue)
{


	if(!table->count(section))
		{

			std::cout << "the settings for this module operation is not present using Default values\n";
			return defaultvalue;
		}
		else
		{

			if(!(*(*table)[ section]).count(field))
			{

		    std:: cout <<  "you are missing this setting attribute therefore the default values was used\n";
		    return defaultvalue;
			}
			else
			{
				std::istringstream ss((*(*table)[section])[field] );
				double n;
				ss >> n;
				return n;
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
int MRIOpenCVSettings::GetSettings(string section ,string field , int defaultvalue)
{

	if(0)
		{

			std::cout << "the settings for this module operation is not present using Default values\n";
			return defaultvalue;
		}
		else
		{

			if(0)
			{

		    std:: cout <<  "you are missing this setting attribute therefore the default values was used\n";
		    return defaultvalue;
			}
			else
			{
				std::istringstream ss(table->at(section)->at(field));
				double n;
				ss >> n;
				return n;
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
char * MRIOpenCVSettings::GetSettings(string  section , string  field , char * defaultvalue)
{
	if(0)
			{

				std::cout << "the settings for this module operation is not present using Default values\n";
				return defaultvalue;
			}
			else
			{

				if(0)
				{

			    std:: cout <<  "you are missing this setting attribute therefore the default values was used\n";
			    return defaultvalue;
				}
				else
				{
					return (char *)table->at(section)->at(field).c_str();

				}

			}

}
