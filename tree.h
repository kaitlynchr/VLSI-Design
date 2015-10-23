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
void assignValues (char *value, double *width, double *height, node *pointer, int size);
void checkTosee(node *pointer);
void createTree(node *pointer, int& size, char *tree);
double areaFunct(double *right, double *left, node *pointer, int &rightsize, int &leftsize);
void readin(vector<char>& value, vector<double>& width, vector<double>& height);
