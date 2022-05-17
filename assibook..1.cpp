#include <iostream>

using namespace std;

struct node
{
char label[50];
int chcount;     //To store no. of child elements
node *child[50];    //Array of pointers to store addresses of child nodes
}*root;    // To store the address of root

class tree
{
public:
void insert();
void display();

tree()
{
root == NULL;
}
};

void tree::insert()
{
int secount;    //Section count.
root = new node();  //Root node is created
cout<<"Enter the name of book:"<<endl;
cin>>root->label;
cout<<"Enter the total number of chapters in book:"<<endl;
cin>>root->chcount;

for(int i=0;i<root->chcount;i++) //Chapters
{
root->child[i] = new node();
cout<<"Enter the name of chapters:"<<endl;
cin>>root->child[i]->label;

cout<<"Enter the number of sections:"<<endl;
cin>>root->child[i]->chcount;

for(int j=0;j<root->child[i]->chcount;j++) //Sections
{
root->child[i]->child[j] = new node();
cout<<"Enter the name of section:"<<endl;
cin>>root->child[i]->child[j]->label;

cout<<"Enter the number of sub-sections:"<<endl;
cin>>root->child[i]->child[j]->chcount;

for(int k=0; k<root->child[i]->child[j]->chcount; k++) //subsection
{
root->child[i]->child[j]->child[k]=new node;
cout<<"Enter sub-section head: ";
cin>>root->child[i]->child[j]->child[k]->label; 
}
}
}
}

void tree::display()
{
if(root != NULL)
{
cout<<"**** Hierarchy of Book ****"<<endl;
cout<<"Book Name is: "<<root->label<<endl;
for(int i=0; i<root->chcount; i++)
{
    cout<<""<<root->child[i]->label<<endl;

    for(int j=0; j<root->child[i]->chcount; j++)
    {
        cout<<" "<<root->child[i]->child[j]->label<<endl;

        for(int k=0; k<root->child[i]->child[j]->chcount; k++)
        {
            cout<<" "<<root->child[i]->child[j]->child[k]->label<<endl;
        }    
    }
}
}
}

int main()
{
tree t;
int ch;


while (1)
{
cout<<"-----------------"<<endl;
cout<<"Book Tree Creation"<<endl;
cout<<"-----------------"<<endl;
cout<<"1.Create"<<endl;
cout<<"2.Display"<<endl;
cout<<"3.Quit"<<endl;
cout<<"Enter your choice :";
cin>>ch;
switch(ch)
{
case 1:
t.insert();
case 2:
t.display();
break;

case 3:
exit(1);

default:
cout<<"Wrong choice"<<endl;
}
}
}
