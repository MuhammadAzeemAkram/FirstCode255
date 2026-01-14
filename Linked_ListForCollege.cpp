#include<iostream>
#include<string>
using namespace std;
    struct StdNode
    {
        int RolNo;
        string Name;
        StdNode * next;
    };
class StdList
{
    private:
    StdNode *start, *current, *temp, *previous;
    public:
    StdList()
    {
        start=NULL;
    }
    void insert(int a, string nm)
    {   
        temp= new StdNode;
        temp->RolNo=a;
        temp->Name=nm;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            current = start;
            while(current->next!=NULL)
            {
                current=current->next; 
            }
            current->next=temp;
        }
    }
    void display()
    {
        cout<<"There is the values of given records"<<endl;
        if(start==NULL)
        {
            cout<<"there is no Linked List";
        }
        else
        {
            current = start;
            while(current!=NULL)
            {
                cout<<current->RolNo<<endl;
                cout<<current->Name<<endl;
                current=current->next;
            }
        }
    }
    void insert_Start(int , string );
    void insert_Location(int,string);
    void delete_End();
    void delete_Start();
    void delete_Location();
    void count();
};

int main()
{
    StdList student;
    int n;
    int i=1;
    string nm;
    int j;
    int L;
    while(1)
    {
    cout<<"There is the Manue . Please select one:"<<endl;
    cout<<"Press 1 for creating Linked List."<<endl;
    cout<<"Press 2 for Insert the Node value."<<endl;
    cout<<"Press 3 for Delete the Node value."<<endl;
    cout<<"Press 4 for Display the Node value."<<endl;
    cout<<"Press 5 for count the Node :"<<endl;
    cout<<"Press 6 for exit the Program"<<endl;
    cin>>j;
    switch(j)
    {
        case 1:
        {
            cout<<"Enter the Number of Node"<<endl;
            cin>>L;
            do
            {
            cout<<" Enter record of Student "<<i<<endl;
            cout<<"Enter the RollNo of Student"<<endl;
            cin>>n;
            cout<<" Enter the Name of Student "<<endl;
            cin>>nm;
            student.insert(n,nm);
            i++;
            } while (i<=L);
            break;
        }
        case 2:
        {
            char k;
            cout<<"Press 'A' for Insert at End"<<endl;
            cout<<"Press 'B' for Insert at Start"<<endl;
            cout<<"Press 'C' for Insert at specific Location"<<endl;
            cin>>k;
            switch(k)
            {
                case 'A':
                {
                    cout<<" Enter record of Student "<<i<<endl;
                    cout<<"Enter the RollNo of Student"<<endl;
                    cin>>n;
                    cout<<" Enter the Name of Student "<<endl;
                    cin>>nm;
                    student.insert(n,nm);
                    i++;
                    break;
                }
                case 'B':
                {
                    cout<<" Enter record of Student "<<i<<endl;
                    cout<<"Enter the RollNo of Student"<<endl;
                    cin>>n;
                    cout<<" Enter the Name of Student "<<endl;
                    cin>>nm;
                    student.insert_Start(n,nm);
                    break;
                }
                case 'C':
                {
                    cout<<" Enter record of Student "<<i<<endl;
                    cout<<"Enter the RollNo of Student"<<endl;
                    cin>>n;
                    cout<<" Enter the Name of Student "<<endl;
                    cin>>nm;
                    student.insert_Location(n,nm);
                    break;
                }    
                default:
                {
                    cout<<"Invalid Input";
                    break;
                }
            }
            break;
        }
        case 3:
        {
            char k;
            cout<<"select one of these."<<endl;
            cout<<"press 'A' for delete at End:  "<<endl;
            cout<<"Press 'B' for delete from  start:"<<endl;
            cout<<"Press 'C' for delete from Location"<<endl;
            cin>>k;
            switch(k)
            {
                case 'A':
                {
                    student.delete_End();
                    break;
                }
                case 'B':
                {
                    student.delete_Start();
                    break;
                }
                case 'C':
                {
                    student.delete_Location();
                    break;
                }
                default :
                {
                    cout<<"Invalid Input"<<endl;
                    break;
                }
            }
            break;
        }
        case 4:
        {
            student.display();
            break; 
        }
        case 5:
        {
            student.count();
            break;
        }
        case 6:
        {
            cout<<"Program is exit:"<<endl;
            break;
        }
        default :
        {
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
    if(j==6)
    break;
    }
    cout<<"Good Bye "<<endl;
return 0;
}


void StdList::insert_Start(int n,string nm)
{
    temp= new StdNode;
    temp->RolNo=n;
    temp->Name=nm;
    temp->next=NULL;
if(start==NULL)
start=temp;
else
{
    current=start;
    temp->next=current;
    start=temp;
}
}
void StdList::insert_Location(int n , string nm)
{
    int Loc;
    cout<<"Enter the RollNo where you want to add a new record"<<endl;
    cin>>Loc;
    temp= new StdNode;
    temp->RolNo=n;
    temp->Name=nm;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        current = start;
        while(current!=NULL)
        {
            cout<<" Function is executing "<<endl;
            if(current->RolNo==Loc)
            {
                temp->next=current->next;
                current->next=temp;
                break;
            }
            current=current->next;
        }
        cout<<"Value Not Found"<<endl;
    }
}

void StdList::count()
{
    if(start==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        int a=0;
        current = start;
        while(current!=NULL)
        {
            a++;
            current=current->next;
        }
        cout<<"Total Number of Records:  ";
        cout<<a<<endl;
    }
}
void StdList::delete_End() 
{
    if(start==NULL)
    {
        cout<<"There is no Linked List: ";
    }
    else
    {
        current=start;
        while(current!=NULL)
        {
            previous = current;
            current=current->next;
        }
        cout<<"this is the value of record :"<<current->RolNo<<"/t"<<current->Name<<endl;
        previous->next=NULL;
        delete current;
        cout<<"Last Node is deleted.";
    }
}  

void StdList::delete_Start()
{
    if(start==NULL)
    cout<<" Linked List is Empty";
    else
    {
        current=start;
        start=current->next;
        cout<<"This is the data of given record:"<<current->RolNo<<" "<<current->Name<<endl;
        delete current;
        cout<<"Record is deleted.";
    }
}

void StdList ::delete_Location()
{
    if(start== NULL)
        cout<<" There is no Linked List.";
    else
    {
        current=start;
        int loc;
        cout<<"Enter the data which you want to delete "<<endl;
        cin>>loc;
        while(current!=NULL)
        {
            
            if(current->RolNo==loc)
            {
                previous->next=current->next;
                delete current;
                cout<<"Node is deleted";
                break;
            }
            previous=current; 
            current=current->next;  
        }
    }
}