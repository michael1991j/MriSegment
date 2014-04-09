#include "dicomtomat.h"

DicomtoMat::DicomtoMat(int index, string file, vector<Mat> * dest)
{
    this->sagtical = dest;
    this->file = file;
    this->index = index;

}

void DicomtoMat::run()
{
    try
    {


        // Separate the extension from the file name
            std::string outputFileName = this->file;
        std::string extension;
        size_t dotPos(outputFileName.rfind('.'));
        if(dotPos != outputFileName.npos)
        {
            extension = outputFileName.substr(dotPos);
            outputFileName.erase(dotPos);
        }
        else
        {
            extension = ".jpg";
        }

                ptr<dataSet> loadedDataSet;

                try
                {

                    // Open the file containing the dicom dataset
                    ptr<puntoexe::stream> inputStream(new puntoexe::stream);
                    inputStream->openFile(this->file, std::ios_base::in);

                    // Connect a stream reader to the dicom stream. Several stream reader
                    //  can share the same stream
                    ptr<puntoexe::streamReader> reader(new streamReader(inputStream));

                    // Get a codec factory and let it use the right codec to create a dataset
                    //  from the input stream
                    ptr<codecs::codecFactory> codecsFactory(codecs::codecFactory::getCodecFactory());
                    loadedDataSet = codecsFactory->load(reader, 2048);


                    // Get the first image. We use it in case there isn't any presentation VOI/LUT
                    //  and we have to calculate the optimal one
                    ptr<image> dataSetImage(loadedDataSet->getImage(0));
                    imbxUint32 width, height;
                    dataSetImage->getSize(&width, &height);


                    // Build the transforms chain
                    ptr<transforms::transformsChain> chain(new transforms::transformsChain);

                    ptr<transforms::modalityVOILUT> modalityVOILUT(new transforms::modalityVOILUT(loadedDataSet));
                    chain->addTransform(modalityVOILUT);

                    ptr<transforms::colorTransforms::colorTransformsFactory> colorFactory(transforms::colorTransforms::colorTransformsFactory::getColorTransformsFactory());
                    if(colorFactory->isMonochrome(dataSetImage->getColorSpace()))
                    {
                        // Convert to MONOCHROME2 if a modality transform is not present
                        ////////////////////////////////////////////////////////////////
                        if(modalityVOILUT->isEmpty())
                        {
                            ptr<transforms::colorTransforms::colorTransform> monochromeColorTransform(colorFactory->getTransform(dataSetImage->getColorSpace(), L"MONOCHROME2"));
                            if(monochromeColorTransform != 0)
                            {
                                chain->addTransform(monochromeColorTransform);
                            }
                        }

                        ptr<transforms::VOILUT> presentationVOILUT(new transforms::VOILUT(loadedDataSet));
                        imbxUint32 firstVOILUTID(presentationVOILUT->getVOILUTId(0));
                        if(firstVOILUTID != 0)
                        {
                            presentationVOILUT->setVOILUT(firstVOILUTID);
                        }
                        else
                        {
                            // Run the transform on the first image
                            ///////////////////////////////////////
                            ptr<image> temporaryImage = chain->allocateOutputImage(dataSetImage, width, height);
                            chain->runTransform(dataSetImage, 0, 0, width, height, temporaryImage, 0, 0);

                            // Now find the optimal VOILUT
                            //////////////////////////////
                            presentationVOILUT->applyOptimalVOI(temporaryImage, 0, 0, width, height);
                        }
                        chain->addTransform(presentationVOILUT);
                    }

                    std::wstring initialColorSpace;
                    if(chain->isEmpty())
                    {
                        initialColorSpace = dataSetImage->getColorSpace();
                    }
                    else
                    {
                        ptr<image> startImage(chain->allocateOutputImage(dataSetImage, 1, 1));
                        initialColorSpace = startImage->getColorSpace();
                    }

                    // Color transform to YCrCb
                    ptr<transforms::colorTransforms::colorTransform> colorTransform(colorFactory->getTransform(initialColorSpace, L"MONOCHROME2"));
                    if(colorTransform != 0)
                    {
                        chain->addTransform((colorTransform));
                    }

                    ptr<image> finalImage(new image);
                    finalImage->create(width, height, image::depthU16, L"MONOCHROME2",7);

                    // Scan through the frames
                    for(imbxUint32 frameNumber(0); ; ++frameNumber)
                    {
                        if(frameNumber != 0)
                        {
                            dataSetImage = loadedDataSet->getImage(frameNumber);
                        }


                        if(chain->isEmpty() && dataSetImage->getDepth() != finalImage->getDepth() && dataSetImage->getHighBit() != finalImage->getHighBit())
                        {
                            chain->addTransform(new transforms::transformHighBit);
                        }

                        if(!chain->isEmpty())
                        {
                            chain->runTransform(dataSetImage, 0, 0, width, height, finalImage, 0, 0);
                        }
                        else
                        {
                            finalImage = dataSetImage;
                        }

                                imbxUint32  row;
                                imbxUint32  pchannelsize;

                                imbxUint32  pchannelnumber;
                                        ptr< handlers::dataHandlerNumericBase> handel(finalImage->getDataHandler(false,&row ,&pchannelsize , &pchannelnumber));
                                        ptr< puntoexe::memory>  mem(handel->getMemory());
                                        Mat  img(row/pchannelnumber,handel->getSize()/row ,CV_16U);

                                        cout  <<  "row " <<  row <<  "channel " << pchannelnumber;
                                        for(int y = 0; y <  1024; y=y+2)
                                        {

                                            for(int x = 0; x < 1024; x=x+2 )
                                            {

                                                img.at<unsigned char >(y/2,x/2 ) =mem->data()[y*1024+ x];


                                            }
                                        }

                            /*
                                        // Open a stream for the jpeg
                        const std::wstring jpegTransferSyntax(L"1.2.840.10008.1.2.4.50");
                        std::ostringstream jpegFileName;
                        jpegFileName << outputFileName;

                        jpegFileName << extension;
                        ptr<puntoexe::memory>  mem(new puntoexe::memory(100000));
                        ptr<puntoexe::memoryStream> jpegStream( new  puntoexe::memoryStream( mem));
                        //jpegStream->openFile(jpegFileName.str(), std::ios_base::out | std::ios_base::trunc);
                        ptr<puntoexe::streamWriter> jpegWriter(new streamWriter(jpegStream));
                        ptr<codecs::codec> outputCodec(codecsFactory->getCodec(jpegTransferSyntax));

                        // Write the jpeg image to the stream
                        outputCodec->setImage(jpegWriter, finalImage, jpegTransferSyntax, codecs::codec::veryHigh,
                                "OB", 8, false, false, false, false);
                        cout << mem->size();
                        */
                                        this->sagtical->at(this->index) =img;
                    }

        }
        catch(dataSetImageDoesntExist&)
        {
            // Ignore this exception. It is thrown when we reach the
            //  end of the images list
            exceptionsManager::getMessage();
        }
    }
    catch(...)
    {
        std::wcout << exceptionsManager::getMessage();
    }


}
