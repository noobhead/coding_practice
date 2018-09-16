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
        ptr->next=head;
        head = ptr;
    }
}

istream& operator>>(istream& is, node* &head)
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
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    return os;
}

node* ll_selection_sort(node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    else
    {
        node *min=head, *beforemin=NULL;
        node *ptr=head;
        while(ptr->next!=NULL)
        {
            if(min->data>ptr->next->data)
            {
                beforemin = ptr;
                min=ptr->next;
            }
            ptr=ptr->next;
        }
        if(min!=head)
        {
            beforemin->next=head;
            node* aftermin = min->next;
            min->next=head->next;
            head->next=aftermin;
            head=min;
        }
        head->next = ll_selection_sort(head->next);
        return head;
    }
}

int main()
{
    node * head = NULL;
    cin>>head;
    cout<<head<<endl;
    head = ll_selection_sort(head);
    cout<<head<<endl;
    return 0;
}
