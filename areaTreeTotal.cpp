#include <iostream>
#include <vector>
#include <cmath>
using namespace  std;
struct node
{
        char key_value;
        double height;
        double width;
        node *left;
        node *right;
};
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
void assignValues (char *value, double *width, double *height, node *pointer, int size)
{

	if(pointer->key_value == 'H' || pointer->key_value == 'V')
	{assignValues(value, width, height, pointer->right, size);
	assignValues(value,width,height, pointer->left, size);

	}
	else
	{int i=0;
		 while(pointer->key_value !=value[i] && i<size)
		{
		i++;
		}
		if(pointer->key_value != value[i])
		{
			cout<<"Value not found.\n";
		}
		else
		{
			pointer->height=height[i];
			pointer->width=width[i];
		}

	}
	return;
}
void checkTosee(node *pointer)
{
	if(pointer->key_value == 'H' || pointer->key_value == 'V')
	{checkTosee(pointer->right);
	checkTosee(pointer->left);
	}
	else
	{
	cout<<pointer->key_value<<" "<<pointer->width<<" "<<pointer->height<<endl;
	}
return;
}
void createTree(node *pointer, int& size, char *tree)
{
//	cout<<tree[size];
	pointer->key_value=tree[size];
        if(size == 0)
        {
        return;
        }
        if  ( tree[size] != 'V' &&  tree[size] != 'H')
        {
        return;
        }
        if (tree[size] == 'V' || tree[size] == 'H' ) //checks to see if it is going to be a number or horizontal or vertical
        {
        pointer->right=new node;
        pointer->right->right= NULL;
        pointer->right->left = NULL;
        size--;
        createTree(pointer->right, size, tree); // goes to the right child for the next open spot
        }
        pointer->left=new node;
        pointer->left->left=NULL;
        pointer->left->right=NULL;
        size--;
        createTree(pointer->left, size, tree);//goes left to store the next value

return;
}
int main(){
char treeA[]={'1','2','V','3','V','4','V','5','V','6','V','7','V','8','V','9','V','a','V','b','V','c','V','d','V','e','V','f','V','g','V','i','V','j','V','k','V','l','V'};
char treeB[]={'1','2','H','3','H','4','H','5','H','6','H','7','H','8','H','9','H','a','H','b','H','c','H','d','H','e','H','f','H','g','H','i','H','j','H','k','H','l','H'};
char treeC[]={'2','1','3','5','4','6','H','7','V','H','V','a','8','V','9','H','c','V','H','g','H','i','b','d','H','k','V','H','f','e','H','V','l','H','V','j','H','V','H'};
char value[]={'1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','i','j','k','l'};
double areaNode[]={13.60, 3.69, 16.71, 1.87, 5.29, 2.06, 17.80, 4.35, 16.86, 1.96, 15.19, 11.20, 11.48, 10.61, 19.72, 19.37, 2.64, 7.22, 3.18, 10.35}; 
double ratio[]={0.52, 0.30, 0.50,  0.35, 1.15, 0.70,  0.25, 0.55,  0.75, 1.07,  0.36,  1.88,  0.51,  0.25,  0.28,  0.42, 0.56, 0.45, 0.25,  0.45};
double right[1000], width[20], height[20];
double left[1000];
int leftsize=0, rightsize=0;
double area;
char userInput='l';
while(userInput!='A' && userInput != 'B' && userInput != 'C')
{
cout<<"What tree would you like to calculate the area: A, B, or C?";
cin>>userInput;
}
	node *root=new node;
	root->right=NULL;
	root->left=NULL;
for(int w=0; w<20; w++)
{
width[w]=sqrt(areaNode[w]*ratio[w]);
height[w]=areaNode[w]/width[w]; 
}
switch (userInput)
	{	case 'A':
		{	int size = sizeof(treeA)-1;
			createTree(root, size, treeA);
			size=sizeof(treeA);
			//cout<<endl;
			assignValues(value, width, height, root,size );
	//		checkTosee(root);
		//	cout<<"peace";
			area=areaFunct(right,left, root,rightsize, leftsize);
			cout<<"AREA:"<<area;
			break;
		}
		case 'B':
		{       int size = sizeof(treeB)-1;
                        createTree(root, size, treeB);
 			size=sizeof(treeA);
                    //    cout<<endl;
                        assignValues(value, width, height, root,size );
                  //      checkTosee(root);
			area=areaFunct(right,left, root, rightsize,leftsize);
			cout<<"AREA:"<<area;
                        break;
                }
		case 'C':
		{       int size = sizeof(treeC)-1;
                        createTree(root, size, treeC);
                        size=sizeof(treeA);
                      //  cout<<endl;
                        assignValues(value, width, height, root,size );
                //        checkTosee(root);
			area=areaFunct(right,left, root, rightsize, leftsize);
			cout<<"AREA:"<<area;
			break;
		}
	}
return 0;
}


