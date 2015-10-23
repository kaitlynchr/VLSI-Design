#include "tree.h"
#include <fstream>
#include <sstream>
#include <string>
void readin(vector <char> *value, vector <double> *width, vector <double> *height){
	//char value[100];
	//vector <char>  testValue;
	//vector <double> testWidth, testHeight;
	char testValue; 
	double areaNode;
	double ratio;
	ifstream myfile;
	myfile.open("input.txt"); //file in in paranthesis
	int i=0;
	string mystring;
	while (getline(myfile,mystring))
	{
	if(mystring.size()<5)
		continue;
		istringstream buffer(mystring);
		buffer>>testvalue>>areaNode>>ratio;
		value.push_back('V');
		value.push_back(value);
		width.push_back(areaNode);
		height.push_back(ratio);

	}
	myfile.close();
        for(int w=0; w<height.size(); w++)
        {
                width[w]=sqrt(width[w]*height[w]);
                height[w]=height[w]/width[w];
        }
	for ( int l=0; l<testWidth.size(); l++)
	{
		cout<<value[2*l]<<" "<<value[2*l+1]<<" "<<width[l]<<" " <<height[l]<<endl;
	}
	value.erase(value.end()-2);
	for(int q=0; q<value.size(); q++)
	{
	cout<<value[q]<<" ";
	}
return;
}

