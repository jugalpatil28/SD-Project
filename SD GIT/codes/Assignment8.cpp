#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

class Student
{
	private : 
		char name[20];
		int rollNo;
		char div;
		char address[20];
	
	public :
		Student()
		{
			strcpy(name,"");
			strcpy(address,"");
			rollNo= 0;
			div = 0;
		}
		Student(int rollNo,char name[20],char div,char address[20])
		{
			strcpy(this->name,name);
			this->rollNo=rollNo;
			this->div = div;
			strcpy(this->address,address);
		}
		
		int getRollNo()
		{
			return rollNo;
		}	
		
		void displayRecord()
		{
			cout << endl;
			cout << "NAME :- "<< name << endl;
			cout << "ROLL NO :- " << rollNo << endl;
			cout << "DIV :- " << div << endl;
			cout << "ADDRESS :- " << address << endl;
		}
};

class FileOperations
{
	private :
		fstream file;
	public : 
		FileOperations(char* filename)
		{
			file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
		}
		
		void insertRecord(int rollNo,char name[20],char div,char address[20])
		{
			Student s1(rollNo,name,div,address);
			file.seekp(0,ios::end);
			file.write((char*)&s1,sizeof(Student));
			file.clear();
		}
		
		void displayAll()
		{
			Student s1;
			file.seekg(0,ios::beg);
			while(file.read((char*)&s1,sizeof(Student)))
			{
				s1.displayRecord();
			}
			file.clear();
		}
		
		void displayRecord(int rollNo)
		{
			Student s1;
			file.seekg(0,ios::beg);
			bool flag = false;
			
			while(file.read((char*)&s1,sizeof(Student)))
			{
				if(s1.getRollNo() == rollNo)
				{
					s1.displayRecord();
					flag = true;
					break;
				}
			}
			if(flag == false)
			{
				cout << "\tRecord of Roll Number " << rollNo << " is not present" << endl;
			
			}
			file.clear();
		}
		
		void deleteRecord(int rollNo)
		{
			ofstream outfile("new.data",ios::binary);
			file.seekg(0,ios::beg);
			bool flag = false;
			Student s1;
			
			while(file.read((char*)&s1,sizeof(Student)))
			{
				if(s1.getRollNo() == rollNo)
				{
					flag = true;
					continue;
				}
				outfile.write((char *)&s1, sizeof(Student));
			}
			if(!flag)
			{
				cout << "\tRecord of Roll Number " << rollNo << " is not present" << endl;
			}
			
			file.close();
			outfile.close();
			remove("student.data");
			
			rename("new.data","student.data");
			
			file.open("student.data",ios::in|ios::out|ios::ate|ios::binary);
		}
		
		~FileOperations()
		{
			file.close();
			cout << "\tFile Closed" << endl;
		}
		
};

int main()
{
	char ch = 'y';
	int choice;
	ofstream newFile("student.data" , ios::app|ios::binary);
	newFile.close();
	
	FileOperations file((char*)"student.data");
	int rollNo;
	char div;
	char name[20],address[20];
	while(ch == 'y')
	{
		cout << "\tMENU"<< endl;
		cout << "\t1.Add" << endl;
		cout << "\t2.Display all" << endl;
		cout << "\t3.Display RollNo" << endl;
		cout << "\t4.Delete RollNo" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "\tEnter the RollNo" << endl;
				cin >> rollNo;
				cin.ignore();
				cout << "\tEnter the name" << endl;
				cin >> name;
				cin.ignore();
				cout << "\tEnter the address" <<endl;
				cin >> address;
				cin.ignore();
				cout << "\tEnter the division" << endl;
				cin >> div;
				file.insertRecord(rollNo,name,div,address);
				cout << "\tRecord Inserted" << endl;
				break;
			case 2:
				cout<<endl<<setw(5)<<"ROLL"<<setw(20)<<"NAME"<<setw(5)<<"YEAR"<<setw(5)<<"DIV"<<setw(10)<<"CITY";
               	file.displayAll();
				break;
			case 3:
				cout<<"Enter Roll Number";
               	cin>>rollNo;
                file.displayRecord(rollNo);
				break;
			case 4:
				cout<<"Enter rollNo";
               	cin>>rollNo;
               	file.deleteRecord(rollNo);
               	break;
            case 5:
            	break;
			default:
				cout << "\tINVALID CHOICE" << endl;
		}
		cout << "\tDo you wish to continue" << endl;
		cout << "\tenter y if yes" << endl;
		cin >> ch;
	}
}

