/*
 * DicomLoader.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "DicomLoader.h"

cv::Mat * ConvertToFormat_RGB888(gdcm::Image const & gimage, char *buffer, QImage* &imageQt)
{
  const unsigned int* dimension = gimage.GetDimensions();

  unsigned int dimX = dimension[0];
  unsigned int dimY = dimension[1];
  cout << "size:"<< dimX<< "size:"<< dimY;
  gimage.GetBuffer(buffer);

  // Let's start with the easy case:
  if( gimage.GetPhotometricInterpretation() == gdcm::PhotometricInterpretation::RGB )
    {
    if( gimage.GetPixelFormat() != gdcm::PixelFormat::UINT8 )
      {
      return  new cv::Mat();
      }
    unsigned char *ubuffer = (unsigned char*)buffer;
    // QImage::Format_RGB888    13      The image is stored using a 24-bit RGB format (8-8-8).
    imageQt = new QImage((unsigned char *)ubuffer, dimX, dimY, 3*dimX, QImage::Format_RGB888);
    }
  else if( gimage.GetPhotometricInterpretation() == gdcm::PhotometricInterpretation::MONOCHROME2 )
    {
    if( gimage.GetPixelFormat() == gdcm::PixelFormat::UINT8 )
      {
      // We need to copy each individual 8bits into R / G and B:
      unsigned char *ubuffer = new unsigned char[dimX*dimY*3];
      unsigned char *pubuffer = ubuffer;
      for(unsigned int i = 0; i < dimX*dimY; i++)
        {
        *pubuffer++ = *buffer;
        *pubuffer++ = *buffer;
        *pubuffer++ = *buffer++;
        }

      imageQt = new QImage(ubuffer, dimX, dimY, QImage::Format_RGB888);
      }
    else if( gimage.GetPixelFormat() == gdcm::PixelFormat::INT16 )
      {
      // We need to copy each individual 16bits into R / G and B (truncate value)
        unsigned short *buffer16 = ( unsigned short*)buffer;
        unsigned short *ubuffer = new  unsigned short[dimX*dimY*3];
        unsigned  short *pubuffer = ubuffer;

      cv::Mat  * img = new cv::Mat(512,512 ,CV_16UC1);

                                              for(int y = 0; y <  512; y++)
                                              {

                                                  for(int x = 0; x < 512; x++ )
                                                  {

                                                      img->at<unsigned short >(y,x ) =buffer16[y*512+ x];


                                                  }
                                              }

 return img;

      imageQt = new QImage((unsigned char *)ubuffer, dimX, dimY, QImage::Format_RGB16);
      }
    else
      {
      std::cerr << "Pixel Format is: " << gimage.GetPixelFormat() << std::endl;
      return new cv::Mat();
      }
    }
  else
    {
    std::cerr << "Unhandled PhotometricInterpretation: " << gimage.GetPhotometricInterpretation() << std::endl;
    return  new cv::Mat();
    }

  return  new cv::Mat();
}



DicomLoader::DicomLoader(string Loc , int Index , std::vector<MRISlice *> * Targetlist)
{
  this->File = Loc;
  this->Index = Index;
  this->Targetlist = Targetlist;

}
cv::Mat qimage_to_mat_cpy(QImage img, int format)
{
  return cv::Mat(img.height(), img.width(),
             format, img.bits(), img.bytesPerLine());
}
DicomLoader::~DicomLoader()
{
  // TODO Auto-generated destructor stub
}

void DicomLoader::run()
{
  gdcm::ImageReader ir;
    ir.SetFileName( this->File.c_str() );
    if(!ir.Read())
      {
      cout << "Read failed" ;

      }

    std::cout<<"Getting image from ImageReader..."<< this->File.c_str() <<std::endl;

    const gdcm::Image &gimage = ir.GetImage();
    std::vector<char> vbuffer;
    vbuffer.resize( gimage.GetBufferLength() );
    char *buffer = &vbuffer[0];

    QImage *imageQt = NULL;


    cv::Mat * mat =  ConvertToFormat_RGB888( gimage, buffer, imageQt );
    this->Targetlist->at(Index) = new MRISlice(*mat, this->Index);

}
