#include "tree.h"
#include <math.h> //exp
#include <cstdlib>

void annealingFunc(vector<char>& Enot, vector<char>& value, vector<double>& width, vector<double>& height)
{
	double  ratio=0.85, lamdatf=.005, P=.99, epsilon=.001, t0=2000, t, oldCost=0, costNew=0, changeOfcost=0;
	int nmoves=10, iseed = 3, n=6, mt=0, uphill, reject=;
	t=t0;
	bool test=true;
	vector<char> E, Best;
	Enot=E, Best=E;
	srand(iseed);
	while((reject/mt)<.95 || (T>epsilon)) // checks to see if the temp is greater than epsilon, or if the reject criteria is greater than 95% to know to stop 
	{
		mt=uphill=reject=0; // intializes everything to 0
		i=rand()%Enot.size(); // gets the random number to choose which value to randomly move 
		while(uphill < N || mt < 2*n) //checks to see if uphill and temp are good
			{
			switch (rand()%3+1) // chooses a random number from 1 to 3 to choose a case
				{
					case 1:{
						while(Enot[i] == 'V' || Enot[i] == 'H')// checks to make sure that the random value is an operand not an operator
                                                {i++; if(Enot.size()== i}{i=0;}}//increments it if it is an operator
						if(i+1 == Enot.size()){j=i-1;test=false;)//checks to make sure it isn't at end of the array, if so starts j decreasing
						else{j=i+1;} //else it starts j increasing to find the next p
						while(Enot[j] == 'V' || Enot[j] == 'H')// helps to fin the next opreand
                                                {if(test){if(j+1 == Enot.size()){j=i-1;test=false;}else{j++;}else{j--;}}//finds it wheter it is is before or after the value
						tempvalue = Enot[i]; //temp value
						Enot[i]=Enot[j]; //stores it
						Enot[j]=tempvalue // stores the other value
						//swap values
						break;b//leaves case statement
						}
					case 2:{
							while(Enot[i] != 'V' && Enot[i] != 'H')//checks to make sure that i find an operator
							{i++; if(i == Enot.size()){i=0;}} //increases if it is an operand
							while(Enot[i] == 'V' || Enot[i] == 'H') // keeps flipping for the line of v and h's 
							{
								if(Enot[i] == 'V') // checks if its a v and changes it to h
								{
									Enot[i]='H';
								}
								else  // else changes it to v since it was an H
								{
									Enot[i]='V';
								}
								i++;//moves along the array
							}
							break; //exits the casement
						}
					case 3:
						{
							if(Enot.size()-1==i) // checks to see if it the last elment, if so it starts at the first of the array 
							{i=0;}
							//looks for an operand and operator right next to each other to perform the m3 swap
							while(((Enot[i]=='V' || Enot[i] == 'H')&&(Enot[i+1]=='V' || Enot[i+1] =='H')) || ((Enot[i]!='V' && Enot[i]!='H')&&(Enot[i+1]!='V' && Enot[i+1] != 'H'))
                                                	 {
					`			i++;// moves to next element to check
								if(i == Enot.size()-2) //checks to make sure we aren't on the last two values, if so starts it over at 0 
								{i=0;}
							 }
							tempValue=Enot[i];// stores the value temporarily
							Enot[i]=Enot[i+1];// stores the other value to swap
							Enot[i+1]=tempValue; //finishes the swap
							int operators=0, operands=0;
							test=true;
							for(int q=0; q<Enot.size; q++) //balloting property 
							{
								if(Enot[i] == 'V' || Enot[i] == 'H')
                                                        	{operands+=1;}
								else
								{operators+=1;}
								if(operators=<operands) //checks to see that there are more operands than operators to ensure its valid
								{test=false;} //marks if its not valid
							}
							if(!test)
							{reject+=1;} // rejects it since its not proven
							break; //leaves the case statemts
						}
			}
		mt=mt+1; //increases move count
		vector <double> right, left;
		node *root=new node;//creates a node for the base of tree
		root->right=NULL;
		root->left=NULL;
		createTree(root, Enot.size(), Enot); //creates a tree to get the cost
		size=Polish.size()-1;
		//createTree(root, size , Polish);
		//size=sizeof(treeA);
		size=Enot.size();
		assignValues(value, width, height, root);
	//	checkTosee (root); 
		newCost= areaFunc(right, left, root); //finds the cost of the area
		changeOfcost=newCost - oldCost;// checks the different in cost
			if(changeOfcost<0 || random < exp(-changeOfcost/T ) // checks to see if the change is better or if it changes randomly 
			{
				if(changeOfcost < 0) // stores E as the new e since it was accepted
				{
					E=newE;
				}
				if(cost(E) < costOfbest)6
				{
					Best=E;
				}
				uphill+=1//increases since it was an uphill movement
			}
			else
			{
					reject+=1; //rejects it because it isn't a good move 
			}
		}
	}
	return;
}
