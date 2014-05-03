/*
 * RegPeriphs.h
 *
 *  Created on: May 2, 2014
 *	Author: Warren Woolsey
 *
 */

#ifndef REGPERIPHS_H_
#define REGPERIPHS_H_

// Struct containing a point cloud and it's corresponding string name
struct PCD
{
  PointCloud::Ptr cloud;
  std::string f_name;

  PCD() : cloud (new PointCloud) {};
};

// Struct that returns the lexigraphically prioritized pcd
struct PCDComparator
{
  bool operator () (const PCD& p1, const PCD& p2)
  {
    return (p1.f_name < p2.f_name);
  }
};

class RegPeriphs {
public:
	RegPeriphs();
	virtual ~RegPeriphs();
	virtual .. add methods
};

#endif /* REGPERIPHS_H_ */
