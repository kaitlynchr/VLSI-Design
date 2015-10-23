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
		value.push_back('V');
		value.push_back(testValue);
		width.push_back(areaNode);
		height.push_back(ratio);

	}
	myfile.close();
        for(int w=0; w<height.size(); w++)
        {
                width[w]=sqrt(width[w]*height[w]);
                height[w]=height[w]/width[w];
        }
	
	value.erase(value.end()-2);
return;
}

