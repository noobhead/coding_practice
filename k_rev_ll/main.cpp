#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insert_beg(node* &head, int d)
{
    node* ptr = new node(d);
    if(head==NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }

}

istream& operator >>(istream& is, node*& head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insert_beg(head, d);
        cin>>d;
    }
    return is;
}

ostream& operator<<(ostream& os, node* head)
{
    //node* ptr = head;
    while(head)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    return os;
}


node* revkelements(node* head, int k)
{
    //reversefirst k elments
    int count = 0;
    node* curr = head;
    node* prev = NULL, *nextptr=NULL;
    while(count<k&&curr!=NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next = revkelements(nextptr, k);
    }
    return prev;
}

int main()
{
    node* head = NULL;
    cin>>head;
    cout<<head<<endl;
    node* ptr = revkelements(head, 3);
    cout<<ptr;
    return 0;
}
