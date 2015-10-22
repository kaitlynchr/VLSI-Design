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
