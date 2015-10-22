double areaFunct(double *right, double *left, node *pointer, int &rightsize, int &leftsize)
{
	double tempArea;// holding place for area

		//base case for when tree is complete
		if(pointer->key_value != 'H' && pointer->key_value != 'V')
		{
			right[0]=pointer->width; // here you store the weights to take back up and be used in the  compute area
			right[1]=pointer->height;
			right[2]=right[1];
			right[3]=right[0];
			rightsize=4;
		return 0; //goes back to h or v so it can compare there and do calculation
		}
	//stores the widths and heights of the right  ???
	//double TempRight[200];
	double tempArray[10000];
	//always start by putting the heights and width in the right
	int tempRight=0;
	tempArea= areaFunct(right, left, pointer->right, rightsize, leftsize);
	//
	for( int q=0; q<rightsize; q++)
	{
	tempArray[q]=right[q];
	tempRight=rightsize;
	}
	tempArea=areaFunct(left, right, pointer->left, leftsize, rightsize); // goes left to get the height and widths, notice left and right are switched so that it really stores them in left
	for(int w=0;w<tempRight; w++)
	{
		right[w]=tempArray[w];
		rightsize=tempRight;
	}
	//double tempArray[200];
	int TempLocation=0;
	for(int i=0; i < rightsize; i=i+2) // for loop to go through the right values
	{
		for(int j=0; j< leftsize;j=j+2) //for loop to go through the left values
		{
			if(pointer->key_value == 'H')//checks to see if you need to keep width or height
			{
				if(right[i]>left[j]) //stores the greater width(since heights are added )
				{
					tempArray[TempLocation]=right[i];
				}
				else
				{
					tempArray[TempLocation]=left[j];
				}
				tempArray[TempLocation+1]=right[i+1]+left[j+1];//gets the height by adding them together (left and right
			}
			else
			{
          	              	tempArray[TempLocation]=right[i]+left[j];//adds widths
				if(right[i+1]>left[j+1])
                                {
                                      tempArray[TempLocation+1]=right[i+1]; //gets the bigger height stored
                                }
                              	else
                                {
                                   tempArray[TempLocation+1]=left[j+1];
                              	}
			}
			TempLocation=TempLocation+2;
		}}
		int r=2;
		rightsize=0;
		for(int l=0; l<TempLocation; l=l+2)
		{
			bool arrayTest=true;
			for(int p=0; p<TempLocation; p=p+2)
			{
				if(tempArray[p]<=tempArray[l]&& tempArray[p+1]<=tempArray[l+1]&& l!=p)
				{
				arrayTest=false;
				}
			}
			if(arrayTest)
				{
					right[rightsize]=tempArray[l];
					right[rightsize+1]=tempArray[l+1];

					rightsize+=2;
				}
		}
		tempArea=right[0]*right[1];//calculates 1st area
		while(r<rightsize)
		{	double output=right[r]*right[r+1]; //calculates the other areas and checks to see whic is the 
			if(tempArea>output)
			{tempArea=output;}
			//cout<<output<<endl;
			r=r+2;

		}

	return tempArea;
}
