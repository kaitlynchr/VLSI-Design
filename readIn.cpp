#include "tree.h"
#include <fstream>
#include <sstream>
#include <string>
void readin(char *value, double *width, double *height){
	//char value[100];
	vector <char>  testValue;
	vector <double> testWidth, testHeight;
	double areaNode[100];
	double ratio[100];
	ifstream myfile;
	myfile.open("input.txt"); //file in in paranthesis
	int i=0;
	string mystring;
	while (getline(myfile,mystring))
	{
	if(mystring.size()<5)
		continue;
		istringstream buffer(mystring);
		buffer>>value[i]>>areaNode[i]>>ratio[i];
		testValue.push_back('V');
		testValue.push_back(value[i]);
		//cout<<value[i]<<" "<<areaNode[i]<<" "<<ratio[i]<<endl;
		//value[i+1]='V';
		//i=i+2;
		i++;

	}
	myfile.close();
        for(int w=0; w<20; w++)
        {
                width[w]=sqrt(areaNode[w]*ratio[w]);
                height[w]=areaNode[w]/width[w];
		testWidth.push_back(width[w]);
		testHeight.push_back(height[w]);
        }
	for ( int l=0; l<testWidth.size(); l++)
	{
		cout<<testValue[2*l]<<" "<<testValue[2*l+1]<<" "<<testWidth[l]<<" " <<testHeight[l]<<endl;
	}
return;
}

