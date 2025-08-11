#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* prev;
    node* next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    } 

    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"deleted"<<endl;
    } 
};

void display(node* &head)
{
    node*temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

void insertathead(node* &head, node* &tail, int d)
{
    //for empty list 
    if (head == NULL)
    {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(node* &head, node* &tail, int d)
{
    if (tail == NULL)
    {
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp; 
    }
}

void insertatpos(node* &head, node* &tail, int pos, int d)
{
    if (pos == 1)
    {
        insertathead(head, tail, d);
        return;
    }

    node* temp = head;
    int cnt = 1;
    while (cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }
    
    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }

    node* midnode = new node(d);
    midnode->next = temp->next;
    temp->next->prev = midnode;
    temp->next = midnode;
    midnode->prev = temp;
}

void deletenode(node* &head, int pos)
{
    if (pos == 1)
    {
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    display(head);

    return 0;
}