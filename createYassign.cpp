#include "tree.h"

void assignValues (vector<char>& value, vector<double>& width, vector<double>& height, node *pointer)
{

	if(pointer->key_value == 'H' || pointer->key_value == 'V')//checks to make sure it isn't a leaf
	{assignValues(value, width, height, pointer->right); // goes right to find the leaf
	assignValues(value,width,height, pointer->left); //goes left to find the leaf
	}
	else
	{int i=0;
		 while(pointer->key_value !=value[i] && i<value.size()) // looks for the key value to find which values to store
		{
		i++;
		}
		if(pointer->key_value != value[i])
		{
			cout<<"Value not found.\n";
		}
		else
		{
			pointer->height=height[i]; //stores widths and heights
			pointer->width=width[i];

		}

	}
	return;
}
void checkTosee(node *pointer)
{
	if(pointer->key_value == 'H' || pointer->key_value == 'V')//goes through the tree and prints the values to verify working correctly 
	{checkTosee(pointer->right);
	checkTosee(pointer->left);
	}
	else
	{
	cout<<pointer->key_value<<" "<<pointer->width<<" "<<pointer->height<<endl;
	}
return;
}
void createTree(node *pointer, int& size, vector<char>& tree)
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
void deleteTree(node *pointer)
{
	
    	if(pointer->left!=NULL)
	{deleteTree(pointer->left);}
	if( pointer->right!=NULL )
    	{deleteTree(pointer->right);} 
	delete pointer; 
return;
}
