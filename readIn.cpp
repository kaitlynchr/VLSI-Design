#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	char value[100];
	double width[100];
	double height[100];
	char temp;
	ifstream myfile;
	myfile.open("input.txt"); //file in in paranthesis
	int i=0;
	string mystring;
	while (getline(myfile,mystring))
	{
	if(mystring.size()<5)
		continue;
		istringstream buffer(mystring);
		buffer>>value[i]>>width[i]>>height[i];
		cout<<value[i]<<" "<<width[i]<<" "<<height[i]<<endl;
		i++;

	}
	myfile.close();
return 0;
}

