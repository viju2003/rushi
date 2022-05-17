#include<iostream>
#include<fstream>
using namespace std;
class student
{
 int rollno;
 char name[50];
 char division;
 char addr[50];
public:
 void setData()
 {
 cout << "\nEnter Roll NO : ";
 cin >> rollno;
 cout << "Enter name : ";
 cin>>name;
 cout<<"Enter the address of the student : ";
 cin>>addr;
 cout<<"Enter division : ";
 cin>>division;
 }
 void showData()
 {
 cout << "\n*Student Roll No : " << rollno;
 cout << "\n*Student Name : " << name;
 cout<<"\n*Address: "<<addr;
 cout<<"\n*Division: "<<division;
 }
 int retAdmno()
 {
 cout<<endl;
 return rollno; //unique for each student
 }
};
void write_record()
{
 ofstream outFile;
 outFile.open("student.dat", ios::binary | ios::app);
 student obj;
 obj.setData();
 outFile.write((char*)&obj, sizeof(obj));
 outFile.close();
}
void display()
{
	ifstream inFile;
 inFile.open("student.dat", ios::binary);
 student obj;
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 obj.showData();
 }
 inFile.close();
}
void search(int n)
{
 ifstream inFile;
 inFile.open("student.dat", ios::binary);
 int flag=0;
 student obj;
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 if(obj.retAdmno() == n) 
 {
 obj.showData();
 flag=1;
 break;
 }
 }
 if(flag==0)
 cout<<"\n\n Record Not Found";
 inFile.close();
}
void delete_record(int n)
{
 student obj;
 ifstream inFile;
 inFile.open("student.dat", ios::binary);
 ofstream outFile;
 outFile.open("temp.dat", ios::out | ios::binary);
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 if(obj.retAdmno() != n)
 {
 outFile.write((char*)&obj, sizeof(obj));
 }
 }
 inFile.close();
 outFile.close();
 remove("student.dat");
 rename("temp.dat", "student.dat");
}
int main()
{
int ch;
do{
 cout<<"\n\n\n*********File operations********** \n1.Write\n2.Display\n3.Search\n4.Delete";
 cout<<"\nEnter your choice : ";
 cin>>ch;
 switch(ch){
 case 1: cout<<"Enter number of records : ";
 int n;
 cin>>n; 
 for(int i = 0; i <n; i++)
 write_record();
 break;
 case 2:
 	cout << "\nList of records";
 display();
 break;
 case 3:
 cout<<"Enter Student Roll No : ";
 int s;
 
 cin>>s;
 search(s);
break;
 case 4:
 cout<<"Enter no to be deleted : ";
 int d;
 cin>>d;
 delete_record(d);
 cout << "\nRecord Deleted";
 break;
 case 5:
 return 0;
 }
}while(ch!=5);
}
