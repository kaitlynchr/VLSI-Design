#include "tree.h"
#include <cstdlib>

void annealingFunc.cpp (vector<char>& Enot, vector<char>& value, vector<double>& right, vector<double>& left, node *pointer )
{
	double  ratio=0.85, lamdatf=.005, P=.99, epsilon=.001, t0=1000, t, oldCost, costNew, changeOfcost;
	int nmoves=10, iseed = 3, n=6, mt=0, uphill, reject=;
	t=t0;
	bool test=true;
	vector<char> E, Best;
	Enot=E;
	int case;
	srand(iseed);
	while((reject/mt)<.95 || (T>epsilon))
	{
		mt=uphill=reject=0;
		i=rand()%Enot.size();
		while(uphill<N || mt < 2*n)
			{
			switch (rand()%3)
				{
					case 1:{
						while(Enot[i] == 'V' || Enot[i] == 'H')
                                                { i++; if(Enot.size()== i}{i=0;}}
						if(i+1 == Enot.size()){j=i-1;test=false;)
						else{j=i+1;}
						while(Enot[j] == 'V' || Enot[j] == 'H')
                                                {if(test){if(j+1 == Enot.size()){j=i-1;test=false;}else{j++;}else{j--;}}
						tempvalue = Enot[i];
						Enot[i]=Enot[j];
						Enot[j]=tempvalue
						//swap values
						break;
						}
					case 2:{
							while(Enot[i] != 'V' && Enot[i] != 'H')
							{i++; if(i == Enot.size()){i=0;}}
							while(Enot[i] == 'V' || Enot[i] == 'H')
							{
								if(Enot[i] == 'V')
								{
									Enot[i]='H';
								}
								else
								{
									Enot[i]='V';
								}
								i++;
						}

						// nonzero length chain of operators
							break;
						}
					case 3:
						if(Enot.size()-1==i)
						{ i=0;}

						while(((Enot[i]=='V' || Enot[i] == 'H')&&(Enot[i+1]=='V' || Enot[i+1] =='H')) || ((Enot[i]!='V' && Enot[i]!='H')&&(Enot[i+1]!='V' && Enot[i+1] != 'H'))
                                                 {
					`		i++;
							if(i == Enot.size()-1)
							{i=0;}
						 }

							tempValue=Enot[i];
							Enot[i]=Enot[i+1];
							Enot[i+1]=tempValue;
							int operators=0, operands=0;
							test=true;
							for(int q=0; q<Enot.size; q++)
							{
								if(Enot[i] == 'V' || Enot[i] == 'H')
                                                        	{operands+=1;}
								else
								{operators+=1;}
								if(operators=<operands)
								{test=false;}
							}
							if(!test)
							{reject+=1;}
							break;
						}
			}
		mt=mt+1;
		createTree(root, Enot.size(), Enot);
		changeOfcost=areaFunct(right, left, node *pointer) - oldCost;
			if(changeOfcost<0 || random < )
			{
				E=newE;
			}
			if(


	}
	if(changeincost <0|| )
	return;
}
