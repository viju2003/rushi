# include<iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *ln, *rn;
};

class Tree
{
public:

    //Node* root;     //root is a ptr and it is of node type
    Node* createTree(int key)  //this fun return ptr of type node
    {
        Node* root=new Node();
        root->key= key;
        root->ln=NULL;
        root->rn=NULL;
        return root;

    }

    void insertNode(int key, Node* root)
    {
        Node* newNode=new Node();
        newNode->key=key;
        if(root->key>key)
        {
            if(root->ln==NULL)
            {
                root->ln=newNode;
            }
            else
            {
                insertNode(key, root->ln);
            }
        }

        if(root->key<key)
        {
            if(root->rn==NULL)
            {
                root->rn=newNode;
            }
            else
            {
                insertNode(key, root->rn);
            }
        }
    }

    void displayInorder(Node* root)
    {
        if(root!=NULL)
        {
            displayInorder(root->ln);
            cout<<root->key<<endl;
            displayInorder(root->rn);
        }
    }

    void descending (Node * root)
    {
        if (root != NULL)
        {
            descending (root->rn);
            cout << "\n" << root->key;
            descending (root->ln);
        }
    }


    void displayFirst(Node* root)
    {
        while (root->ln != NULL)
        {
            root=root->ln;
        }
        cout<<"\n Minimum number is "<<root->key;
    }

    void search(Node* root, int searchKey)
    {
        if(searchKey == root->key)
            {
                cout<<"Search Successful. Number Found."<<endl;
            }
        else if(searchKey < root->key)
        {
            if(root->ln != NULL)
            {
                search(root->ln , searchKey);
            }

            else
            {
                cout<<"Entered Number Not Found"<<endl;
                return;
            }
        }
        else if(searchKey > root->key)
            {
                if(root->rn !=NULL)
                {
                    search(root->rn , searchKey);
                }
                else
                {
                    cout<<"Number Not Found"<<endl;
                    return;
                }
            }
        else
            {
                cout<<"Element Not Present in the Tree"<<endl;
                return;
            }
     }

    int longestPath(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int Lctr=longestPath(root->ln);
        int Rctr=longestPath(root->rn);
        if(Lctr>Rctr)
        {
            return (Lctr+1);
        }
        else
        {
            return(Rctr+1);
        }
    }

    Node* swapNode(Node* root)
    {
        Node* temp;
        if(root==NULL)
        {
            return NULL;
        }
        temp= root->ln;
        root->ln=root->rn;
        root->rn=temp;
        swapNode(root->ln);
        swapNode(root->rn);
    }
};

int main()
{
    int choice, order, flag=0;
    int key, searchKey;
    Tree t1;
    Node* root;
    do
    {
        cout<<"\n1. Enter a number \n2. Display \n3. Swap left and right node \n4. Search \n5. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\n Enter the number: ";
                cin>>key;
                if(flag==0)
                {
                    root=t1.createTree(key);
                    flag=1;
                }
                else
                {
                    t1.insertNode(key,root);
                }
                break;

            case 2:
                cout<<"\n1. Display list in ascending order. \n2. Display list descending order. \n3. Show min no. \n4. Show no of nodes in longest path";
                cout<<"\nEnter your choice: ";
                cin>>order;
                switch(order)
                {
                case 1:
                    t1.displayInorder(root);
                    break;
                case 2:
                    t1.descending(root);
                    break;
                case 3:
                    t1.displayFirst(root);
                    break;
                case 4:
                    cout<<"Height of the tree or the longest path is: "<<t1.longestPath(root);
                    break;
                }

                break;

            case 3:
                t1.swapNode(root);
                cout<<"Swapped!! the new list is: \n";
                t1.displayInorder(root);
                break;

            case 4:
                cout<<"Enter the no. you want to search: ";
                cin>> searchKey;
                t1.search(root, searchKey);
                break;

            case 5:
                break;

        }
    }while(choice!=5);
     return 0;
}
