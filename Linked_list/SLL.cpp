#include <iostream>
using namespace std;

class node
{

public: 
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        //mem free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"deleted"<<endl;
    }
};

void insertathead(node* &head, int x)
{
    node* temp = new node(x);
    temp->next = head;
    head = temp;
}

void insertattail(node* &tail, int y)
{
    node* temp = new node(y);
    tail->next = temp;
    tail = temp;
}

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

void insertatpos(node* &head, node* &tail, int pos, int z)
{
    if (pos == 1)
    {
        insertathead(head, z);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL)
    {
        insertattail(tail, z);
        return;
    }

    node* midnode = new node(z);
    midnode->next = temp->next;
    temp->next = midnode;
}

void deletenode(node* &head, int pos)
{
    if (pos == 1)
    {
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node* node1 = new node(20);
    node* head = node1;
    node* tail = node1;

    insertathead(head, 12);
    display(head);

}
