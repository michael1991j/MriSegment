/*
 * Transformation.cpp
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#include "MRITransformation.h"

  SagitaltoTransversal::SagitaltoTransversal( vector<MRISlice *>  * input , vector<MRISlice *>  * output, int id)
  {
    this->id = id;
    this->input = input;
    this->output = output;
  }

 void  SagitaltoTransversal::run()
  {
   int  xmax= this->input->at(0)->Slice.cols;
   int  ymax=this->input->at(0)->Slice.rows;

     for(int i = 0; i < this->input->size(); i++)
     {

         for(int x = 0; x < xmax; x++)
         {
             this->output->at(this->id)->Slice.at<unsigned short>(i,x) = this->input->at(i)->Slice.at<unsigned short>(this->id,x);
         // printf("measurement:%d\n",  this->transversal->at(y).at<int>(x,i)  );
         //fflush(stdout);

         }


     }

  }


 SagitaltoCorronal::SagitaltoCorronal( vector<MRISlice *>  * input , vector<MRISlice *>  * output, int id)
 {
   this->id = id;
   this->input = input;
   this->output = output;
 }

void  SagitaltoCorronal::run()
 {
  int  xmax= this->input->at(0)->Slice.cols;
  int  ymax=this->input->at(0)->Slice.rows;

    for(int i = 0; i < this->input->size(); i++)
    {

        for(int y = 0; y < ymax; y++)
        {
            this->output->at(id)->Slice.at<unsigned short>(y,i) = this->input->at(i)->Slice.at<unsigned short>(y,id);
        // printf("measurement:%d\n",  this->transversal->at(y).at<int>(x,i)  );

        }

  }

 }
