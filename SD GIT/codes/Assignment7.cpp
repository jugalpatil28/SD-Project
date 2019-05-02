#include<iostream>
using namespace std;

const int size = 10;
int HashTable[size] = {0};

void addElement()
{
	int key,hash;
	bool isPlaced = false ;
	cout << "\tEnter the value to be inserted" << endl;
	cin >> key;
	
	hash = key%size ;
	if(HashTable[hash] == 0)
	{
		HashTable[hash] = key;
		isPlaced = true;
		return;
	}
	else if(HashTable[hash]!=0)
	{
		hash = 7 - (key%7);
		if(HashTable[hash]==0)
		{
			HashTable[hash] = key;
			isPlaced = true;
			return;
		}
		else
		{
			for(int i =0;i<10;i++)
			{
				hash = ((key%size) + i*(7 - (key%7)))%size;
				if(HashTable[hash]==0)
				{
					HashTable[hash] = key;
					isPlaced = true;
					return;
				}
			}
		}
	}
	else
	{
		if(!isPlaced)
		{
			cout << "\tArray is full" << endl;
		}
	}
	
	
}

void display()
{
	for(int i =0 ;i<10;i++)
	{
		cout << " " << HashTable[i];
	}
}

int main()
{
	int choice;
	char ch='y';
	int HashTable[size]={0};
	while(ch == 'y')
	{
		cout << "\tMENU"<< endl;
		cout << "\t1.Insert A Element" << endl;
		cout << "\t2.Display HashTable" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				addElement();
				break;
			case 2:
				display();
				break;
			default:
				cout << "\tINVALID CHOICE" << endl;
		}
		cout << "\tDo you wish to continue" << endl;
		cout << "\tenter y if yes" << endl;
		cin >> ch;
	}
	
}
