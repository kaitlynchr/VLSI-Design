#include  "tree.h"

double areaFunct(vector<double>& right, vector<double>& left, node *pointer)
{
	double tempArea;// holding place for area

		//base case for when tree is complete
		if(pointer->key_value != 'H' && pointer->key_value != 'V')
		{	right.clear();
			right.push_back(pointer->width); // here you store the weights to take back up and be used in the  compute area
			right.push_back(pointer->height);
			right.push_back(right[1]);
			right.push_back(right[0]);
		return 0; //goes back to h or v so it can compare there and do calculation
		}
	//stores the widths and heights of the right side
	vector<double> tempVector;
	//always start by putting the heights and width in the right
	tempArea= areaFunct(right, left, pointer->right);
	//stores the right values temporarily to protect change later down
	for( int q=0; q<right.size(); q++)
	{
		tempVector.push_back(right[q]);
	}
	tempArea=areaFunct(left, right, pointer->left); // goes left to get the height and widths, notice left and right are switched so that it really stores them in left
	right.clear();
	for(int w=0;w<tempVector.size(); w++)
	{
		right.push_back(tempVector[w]);
	}
	tempVector.clear();
	//int TempLocation=0;
	for(int i=0; i < right.size(); i=i+2) // for loop to go through the right values
	{
		for(int j=0; j< left.size();j=j+2) //for loop to go through the left values
		{
			if(pointer->key_value == 'H')//checks to see if you need to keep width or height
			{
				if(right[i]>left[j]) //stores the greater width(since heights are added )
				{
					tempVector.push_back(right[i]);
				}
				else
				{
					tempVector.push_back(left[j]);
				}
				tempVector.push_back(right[i+1]+left[j+1]);//gets the height by adding them together (left and right
			}
			else
			{
          	              	tempVector.push_back(right[i]+left[j]);//adds widths
				if(right[i+1]>left[j+1])
                                {
                                      tempVector.push_back(right[i+1]); //gets the bigger height stored
                                }
                              	else
                                {
                                     tempVector.push_back(left[j+1]);
                              	}
			}
		}}
		int r=2;
		right.clear();
		for(int l=0; l<tempVector.size(); l=l+2)
		{
			bool arrayTest=true;
			for(int p=0; p<tempVector.size(); p=p+2)
			{
				if(tempVector[p]<=tempVector[l]&& tempVector[p+1]<=tempVector[l+1]&& l!=p)
				{
				arrayTest=false;
				}//checks to see if it is one of the smallest
			}
			if(arrayTest)
				{
					right.push_back(tempVector[l]);
					right.push_back(tempVector[l+1]); //stores the smallest values in the arrays
				}
		}
		tempArea=right[0]*right[1];//calculates 1st area
		while(r<right.size())
		{	double output=right[r]*right[r+1]; //calculates the other areas and checks to see whic is the
			if(tempArea>output)
			{tempArea=output;}
			r=r+2;
		}

	return tempArea;
}
