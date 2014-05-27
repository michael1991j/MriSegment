#include "dataset.h"
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QMapIterator>
Dataset::Dataset()
{
}

bool Dataset::load(QString filepath)
{     QFile file(filepath);

      if (!file.open(QIODevice::ReadOnly))
      {
      /* show wrror message if not able to open file */
      QMessageBox::warning(0, "cant open", "The file is in read only mode");
      }

    QXmlStreamReader xmlStream(&file);
        while(!xmlStream.atEnd())
        {
            xmlStream.readNext();
            if(xmlStream.isStartElement())
            {
                // Read the tag name.
                QString sec(xmlStream.name().toString());
                if(sec == "Label")
                {
                  Config_Labeledcartilage * tissue = new Config_Labeledcartilage();
                   QXmlStreamAttributes  attributes=  xmlStream.attributes();
                   for(int i =0; i <  attributes.size(); i++)
                   {
                       if(attributes.at(i).name() == "id")
                        tissue->id = attributes.at(i).value().toString().toInt();
                       else if(attributes.at(i).name() == "PCL")
                        tissue->PCLpath = attributes.at(i).value().toString();
                       else if(attributes.at(i).name() == "Mesh")
                        tissue->VTK = attributes.at(i).value().toString();

                   }
                   this->Labels->push_back(tissue);


                    }
            }
        }
return true;
}

bool Dataset::Savetofile(QString save)
{

     QFile file(save);

     if (!file.open(QIODevice::WriteOnly))
     {
     /* show wrror message if not able to open file */
     QMessageBox::warning(0, "Read only", "The file is in read only mode");
     }
     else
     {


         /*if file is successfully opened then create XML*/
         QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
         /* set device (here file)to streamwriter */
         xmlWriter->setDevice(&file);
         /* Writes a document start with the XML version number version. */
         xmlWriter->writeStartDocument();
         /* Writes a start element with name,
         * Subsequent calls to writeAttribute() will add attributes to this element.
          here we creating a tag <persons>*/
         xmlWriter->writeStartElement("Config");
         // ///////////mricommons//////////////
         xmlWriter->writeStartElement("MRICommon");

         // //////////////////////////
         for(int i =0; i < this->Imagesets->size(); i++)
         {
             if(this->Imagesets->at(i) !=0)
             {
             /* create tag person */
             xmlWriter->writeStartElement("Imageset");

             xmlWriter->writeAttribute("id", QString::number(this->Imagesets->at(i)->id));
             xmlWriter->writeAttribute("totran", QString::number(this->Imagesets->at(i)->totran));
             xmlWriter->writeAttribute("tosag", QString::number(this->Imagesets->at(i)->tosag));
             xmlWriter->writeAttribute("tocor",QString::number(this->Imagesets->at(i)->tocor));
             xmlWriter->writeAttribute("dirPath",this->Imagesets->at(i)->FilePath);

             /*close tag person  */
             xmlWriter->writeEndElement();
              }
         }
         // ///////////////////////////////////
             xmlWriter->writeEndElement();
         // /////////////////////////////////////
             // ///////////mricommons//////////////
             xmlWriter->writeStartElement("Labeledoutput");

             // //////////////////////////
             for(int i =0; i < this->Labels->size(); i++)
             {
                 if(this->Labels->at(i) !=0)
                 {
                 /* create tag person */
                 xmlWriter->writeStartElement("Label");

                 xmlWriter->writeAttribute("id", QString::number(this->Labels->at(i)->id));
                 xmlWriter->writeAttribute("Mesh",this->Labels->at(i)->VTK);
                 xmlWriter->writeAttribute("PCL",this->Labels->at(i)->PCLpath);

                 /*close tag person  */
                 xmlWriter->writeEndElement();
              }
                 }
             // ///////////////////////////////////
                 xmlWriter->writeEndElement();
             // /////////////////////////////////////
         /*end tag persons*/
         xmlWriter->writeEndElement();
         /*end document */
         xmlWriter->writeEndDocument();
                delete xmlWriter;
     }
}
