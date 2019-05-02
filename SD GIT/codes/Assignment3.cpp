#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i=0,j=0;
	string city[6] = {"PUNE","CHENNAI","BANGALORE","DELHI","MUMBAI","KOLKATA"};
	string sourceCity;
	string destCity;
	int adjacency[6][6]={{0,400,200,0,150,0},
							{0,0,300,1200,0,300},
							{200,0,0,1000,300,0},
							{500,0,0,0,450,400},
							{400,0,0,300,0,200},
							{600,200,0,0,0,0}};
							
	cout << "\tEnter current city" << endl;
	cin >> sourceCity;
	
	cout << "\tEnter the destination city " << endl;
	cin >> destCity;
	
	for(auto &c : sourceCity)
		c = toupper(c);
		
	for(auto &c : destCity)
		c = toupper(c);
		
	int row,col;
	for(i=0;i<=5;i++)
	{
		if(city[i]==sourceCity)
			row = i;
	}
	
	for(i=0;i<=5;i++)
	{
		if(city[j]==destCity)
			col = j;
	}
		
	
		if(!adjacency[i][j] == 0)
		{
			cout << "There is a flight between" << sourceCity << " and " << destCity << "the distance is : " << adjacency[i][j] << endl;
		}
		else if(i == j)
		{
			cout<< "\tSource and Destination cannot be same" << endl; 
		}
		
		else
		{
			cout << "\tNo flight route available" << endl;
		}
}


