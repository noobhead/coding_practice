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

int ll_size(node* head)
{
    int c = 0;
    while(head!= NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

void insert_beg(node* &head, int d)
{
    node* ptr = new node(d);
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next=head;
        head = ptr;
    }
}

istream& operator >>(istream &is, node* &head)
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

ostream& operator <<(ostream& os, node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    return os;
}

void ll_bubble(node* &head, int n)
{
    for (int i=0;i<n;i++)
    {
        node *curr = head, *prev = NULL, *nextptr = NULL;
        while(curr!=NULL&& curr->next!=NULL)
        {
            if(curr->next->data<curr->data) //initial change
            {
                if(prev==NULL)
                {
                    nextptr = curr->next;
                    curr->next=nextptr->next;
                    nextptr->next = curr;
                    head = nextptr;
                    prev = nextptr;
                }
                else
                {
                    nextptr = curr->next;
                    prev->next=nextptr;
                    curr->next=nextptr->next;
                    nextptr->next = curr;
                    prev = nextptr;
                }
            }
            else
            {
                prev = curr;
                curr=curr->next;
            }
        }
    }
}

int main()
{
    node* head = NULL;
    cin>>head;
    cout<<head<<endl;
    int n = ll_size(head);
    ll_bubble(head,n);
    cout<<head<<endl;
    return 0;
}
