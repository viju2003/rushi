#include <iostream>
#include <string.h>
using namespace std;

class Graph
{
    public:
    int n,f,i,city1,city2;
    int j;
    string cities[100];
    int fuel;
    int graph[100][100];

    Graph()
    {
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               graph[n][n]=0;

           }
        }
    }

    void create()
    {
        cout<<"Enter total no. of cities: ";
        cin>>n;

        for(i=0;i<n;i++)
        {
            cout<<"Enter name of city: ";
            cin>>cities[i];

        }

        cout<<"Use following numbers for the respective cities: "<<endl;
        for(i=0;i<n;i++)
        {
            cout<<cities[i]<<"="<<i<<endl;

        }

        cout<<"Enter total no. of flites available: ";
        cin>>f;

        for(i=0;i<f;i++)
        {
            cout<<"Enter the numbers of respectives cities for which flite is available:  "<<endl;
            cout<<"city1=";
            cin>>city1;
            cout<<"city2=";
            cin>>city2;

            cout<<"Enter the fuel required for respective flite(in liter): ";
            cin>>fuel;
            graph[city1][city2]=fuel;

        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
            cout << "\t" << cities[i] << "\t";
        for (int i = 0; i < n; i++)
        {
            cout << "\n"<< cities[i];
            for (int j = 0; j < n; j++)
                cout << "\t" << graph[i][j] << "\t";
            cout << endl;
        }
    }


};

int main()
{
    int choice;
    Graph obj;
    do
    {
        cout<<"\n1. Create Graph. \n2. Display Graph. \n3. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                break;

        }
    }while(choice!=3);
}
