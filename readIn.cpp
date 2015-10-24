#include "tree.h"
#include <fstream>
#include <sstream>
#include <string>
void readin(vector<char>& value, vector<double>& width, vector<double>& height){
	char testValue;
	double areaNode;
	double ratio;
	ifstream myfile;
	myfile.open("input.txt"); //file in in paranthesis
	string mystring;
	while (getline(myfile,mystring))
	{
	if(mystring.size()<5)
		continue;
		istringstream buffer(mystring);
		buffer>>testValue>>areaNode>>ratio;
		value.push_back(testValue);
		width.push_back(areaNode);
		height.push_back(ratio);

	}
	myfile.close();
        for(int w=0; w<height.size(); w++)
        {
		areaNode=width[w];
          	width[w]=sqrt(areaNode*height[w]);
		height[w]=areaNode/width[w];

        }
return;
}

