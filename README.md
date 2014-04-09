MriSegment
==========

MRI segmentation

Set up Instructions 


mkdir ./Proto ./Build ./RawData ./Src  ./ThirdParty

./Proto -  synbolic link to the  project drop box 
./Build -  Build directory
./RawData  Source of all the raw data
./Src   contain all source code
./ThirdParty  Contain Required Third party lIbares that do not exist natively in this libary 


cd  ./Src
	Go into  the source Directory
git clone   https://github.com/michael1991j/MriSegment.git
	Get clone of the source code 
 
cd ../ThirdParty
 
Install thirdparty libaries 

hg clone https://bitbucket.org/binarno/imebra
get the latest libaries


Install the pcl Libaries 

sudo add-apt-repository ppa:v-launchpad-jochen-sprickerhof-de/pcl
sudo apt-get update
sudo apt-get install libpcl-all



 svn checkout http://googletest.googlecode.com/svn/trunk/ googletest-read-only 

For testing 

Build the  all suite

cd ../Build 

cmake ../Src/MriSegment/

make 


Make install 






 
