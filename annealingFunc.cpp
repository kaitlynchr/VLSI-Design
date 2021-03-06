#include "tree.h"
//#include <math.h> //exp
#include <cstdlib>

void annealingFunc(vector<char>& Enot, vector<char>& value, vector<double>& width, vector<double>& height)
{
	double BestCost, costOfbest, ratio=0.85, lamdatf=.95, P=.99, epsilon=.001, t0=2000, t, oldCost=0, costNew=0, changeOfcost=0;
	int nmoves=10, iseed = 3, n=6, mt=12, uphill, reject, j=0, i=0, N;
	n=Enot.size();
	N= n*nmoves;
	t=t0;
	bool test=true;
	vector<char> newE ,E, Best;
	for(int r=0; r<Enot.size(); r++)
	{E.push_back(Enot[r]); Best.push_back(Enot[r]); newE.push_back(Enot[r]);}
	vector <double> right, left;
	node *root=new node;//creates a node for the base of tree
	root->right=NULL;
	root->left=NULL;
	int size=newE.size()-1;
        createTree(root,size, newE); //creates a tree to get the cost
	size=newE.size();
	assignValues(value, width, height, root);
	oldCost= areaFunct(right, left, root);
	BestCost=oldCost;
	deleteTree(root);
	srand(iseed);
	int count=0;
	while(((reject/mt)< .95) && (t>epsilon)) // checks to see if the temp is greater than epsilon, or if the reject criteria is greater than 95% to know to stop 
	{
		mt=uphill=reject=0; // intializes everything to 0
		while(uphill < N && mt < 2*N) //checks to see if uphill and temp are good
			{
		//	i=newE.size()-1;
			i=rand()%newE.size(); // gets the random number to choose which value to randomly move 
			switch (rand()%3+1) // chooses a random number from 1 to 3 to choose a case
		//	switch (3)	
			{
					case 1:{
						
						while(newE[i] == 'V' || newE[i] == 'H')// checks to make sure that the random value is an operand not an operator
                                                {
							i++; 
							if(newE.size()== i)
								{
									i=0;
								}
						}//increments it if it is an operator
						if(i+1 == newE.size())
							{
								j=i-1;	
								test=false;
							}//checks to make sure it isn't at end of the array, if so starts j decreasing
						else
							{
								j=i+1;
							} //else it starts j increasing to find the next p
						while(newE[j] == 'V' || newE[j] == 'H')// helps to fin the next opreand
                                                {
							if(test)
							{
								if(j+1 == newE.size())
								{
									j=i-1;
									test=false;
								}
								else
								{
									j++; if(i== j){j++;}
								}
							}
							else
							{	
								j--; if(i==j){j--;}
							}
						}//finds it wheter it is is before or after the value
						char tempvalue = newE[i]; //temp value
						newE[i]=newE[j]; //stores it
						newE[j]=tempvalue; // stores the other value
						//swap values
						break;//leaves case statement
						}
					case 2:{
							while(newE[i] != 'V' && newE[i] != 'H')//checks to make sure that i find an operator
							{i++; if(i == newE.size()){i=0;}} //increases if it is an operand
							j=i-1;
							while(newE[j] == 'V' || newE[j] == 'H') // keeps flipping for the line of v and h's
                                                        {
                                                                if(newE[j] == 'V') // checks if its a v and changes it to h
                                                                {
                                                                        newE[j]='H';
                                                                }
                                                                else  // else changes it to v since it was an H
                                                                {
                                                                        newE[j]='V';
                                                                }
                                                                j--;//moves along the array
                                                        }
							while(newE[i] == 'V' || newE[i] == 'H') // keeps flipping for the line of v and h's 
							{
								if(newE[i] == 'V') // checks if its a v and changes it to h
								{
									newE[i]='H';
								}
								else  // else changes it to v since it was an H
								{
									newE[i]='V';
								}
								i++;//moves along the array
							}
							break; //exits the casement
						}
					case 3:
						{
							if(newE.size()-1==i) // checks to see if it the last elment, if so it starts at the first of the array 
							{i=0;}
							//looks for an operand and operator right next to each other to perform the m3 swap
							while(((newE[i]=='V' || newE[i] == 'H')&&(newE[i+1]=='V' || newE[i+1] =='H')) || ((newE[i]!='V' && newE[i]!='H')&&(newE[i+1]!='V' && newE[i+1] != 'H')))
                                                	 {
								i++;// moves to next element to check
								if(i == newE.size()-2 || i>newE.size()-2 ) //checks to make sure we aren't on the last two values, if so starts it over at 0 
								{i=0;}
							 }
							char tempValue=newE[i];// stores the value temporarily
							newE[i]=newE[i+1];// stores the other value to swap
							newE[i+1]=tempValue; //finishes the swap
							int operators=0, operands=0;
							test=true;
							for(int q=0; q<newE.size(); q++) //balloting property 
							{
								if(newE[q] == 'V' || newE[q] == 'H')
                                                        	{operands+=1;}
								else
								{operators+=1;}
								if(operators<=operands) //checks to see that there are more operands than operators to ensure its valid
								{test=false;} //marks if its not valid
							}
							if(i>0)
							{if (newE[i-1] == newE[i])
								{test=false;} 
							}
							if(i<newE.size()-2)
							{ if(newE[i+1]==newE[i+2])
								{test=false;}
							}
							if(!test)
							{reject+=1;
							char tempValue=newE[i];// stores the value temporarily
                                                        newE[i]=newE[i+1];// stores the other value to swap
                                                        newE[i+1]=tempValue; //finishes the swap
							} // rejects it since its not proven
							break; //leaves the case statemts
						}
			} count++;
		mt=mt+1; //increases move count
		vector <double> right, left;
		node *root=new node;//creates a node for the base of tree
		root->right=NULL;
		root->left=NULL;
		int size=newE.size()-1;
		createTree(root,size, newE); //creates a tree to get the cost
		size=newE.size();
		assignValues(value, width, height, root);
		costNew= areaFunct(right, left, root); //finds the cost of the area
		deleteTree(root);
		changeOfcost=costNew - oldCost;// checks the different in cost
		double testVal= exp(-changeOfcost/t);
		double random = rand()%100+1;
		random=random/100; 
			if(changeOfcost<0 || random < testVal ) // checks to see if the change is better or if it changes randomly 
			{
				if(changeOfcost > 0) // stores E as the new e since it was accepted
				{
					for(int r=0; r<Enot.size(); r++)
                                        {E[r]=newE[r];}
					uphill+=1;
				}
				if(costNew < BestCost)
				{
		
					for(int r=0; r<Enot.size(); r++)
        				{Best[r]=newE[r];}
					BestCost=costNew;
				}
			//	uphill+=1;//increases since it was an uphill movement
			}
			else
			{
					reject+=1; //rejects it because it isn't a good move 
			}
		oldCost=costNew;
		}
		t=lamdatf*t; 
		
	}
	cout<<"Best cost:"<<BestCost;
	return;
}
