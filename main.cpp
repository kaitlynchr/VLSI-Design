#include "tree.h"

int main(){
//	char treeA[]={'1','2','V','3','V','4','V','5','V','6','V','7','V','8','V','9','V','a','V','b','V','c','V','d','V','e','V','f','V','g','V','i','V','j','V','k','V','l','V'};
//	char treeB[]={'1','2','H','3','H','4','H','5','H','6','H','7','H','8','H','9','H','a','H','b','H','c','H','d','H','e','H','f','H','g','H','i','H','j','H','k','H','l','H'};
//	char treeC[]={'2','1','3','5','4','6','H','7','V','H','V','a','8','V','9','H','c','V','H','g','H','i','b','d','H','k','V','H','f','e','H','V','l','H','V','j','H','V','H'};
	//char value[]={'1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','i','j','k','l'};
	//double areaNode[]={13.60, 3.69, 16.71, 1.87, 5.29, 2.06, 17.80, 4.35, 16.86, 1.96, 15.19, 11.20, 11.48, 10.61, 19.72, 19.37, 2.64, 7.22, 3.18, 10.35}; 
	//double ratio[]={0.52, 0.30, 0.50,  0.35, 1.15, 0.70,  0.25, 0.55,  0.75, 1.07,  0.36,  1.88,  0.51,  0.25,  0.28,  0.42, 0.56, 0.45, 0.25,  0.45};
	vector <double> right, left;
	vector <double> width, height;
	vector <char> value;
	int leftsize=0, rightsize=0;
	double area;
	readin(value, width, height);// reads in values from files
	node *root=new node;//creates a node for the base of tree
	root->right=NULL;
	root->left=NULL;
	createTree(root, size, treeA);
	size=sizeof(treeA);
	assignValues(value, width, height, root);
	area=areaFunct(right,left, root);
	cout<<"AREA of A:"<<area;
	size = sizeof(treeB)-1;
	createTree(root, size, treeB);
	size=sizeof(treeB);
	assignValues(value, width, height, root );
	area=areaFunct(right,left, root);
	cout<<"AREA of B:"<<area;
	size = sizeof(treeC)-1;
	createTree(root, size, treeC);
	size=sizeof(treeC);
	assignValues(value, width, height, root);
	area=areaFunct(right,left, root);
	cout<<"AREA of C:"<<area; 
	return 0;
}


