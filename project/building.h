#ifndef BUILDING_H
#define BUILDING_H
#include<string>
struct Building{
	std::string name;
	double x;
	double y;
	double distance;
	int index;
	struct Building* next;
};

struct Building* make();
void inquiry(std::string name, struct Building* build,int &x,int &y);
#endif
