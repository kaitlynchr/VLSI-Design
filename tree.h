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
void assignValues (vector<char>& value, vector<double>& width, vector<double>& height, node *pointer);
void checkTosee(node *pointer);
void createTree(node *pointer, int& size, char *tree);
double areaFunct(vector<double>& right, vector<double>& left, node *pointer);
void readin(vector<char>& value, vector<double>& width, vector<double>& height);
