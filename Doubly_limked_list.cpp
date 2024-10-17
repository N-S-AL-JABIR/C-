#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_N(Node *Head)
{
    Node *tmp = Head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_rev(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
void insert_tail(Node *&Head, Node *&tail, int v)
{
    Node *node = new Node(v);
    if (tail == NULL)
    {
        Head = node;
        tail = node;
        return;
    }
    tail->next = node;
    node->prev = tail;
    tail = tail->next;
}
void insert_position(Node *Head, int po, int v)
{
    Node *node = new Node(v);
    Node *tmp = Head;
    for (int i = 1; i < po; i++)
    {
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;
    node->next->prev = node;
    node->prev = tmp;
}
int Size(Node *Head)
{
    Node *tmp = Head;
    int c = 0;
    while (tmp != NULL)
    {
        c++;
        tmp = tmp->next;
    }

    return c;
}
void insert_Head(Node *&Head, Node *&tail, int v)
{
    Node *node = new Node(v);
    if (Head == NULL)
    {
        Head = node;
        tail = node;
        return;
    }
    node->next = Head;
    Head->prev = node;
    Head = node;
}
int main()
{
    Node *Head = NULL;
    Node *tail = NULL;
    while (true)
    {
        int v;
        cin >> v;
        if (v==-1)
        {
            break;
        }
        
        insert_tail(Head, tail, v); 
    }
    
    // insert_Head(Head, tail, v);
    // insert_tail(Head, tail, 30);
    // insert_position(Head, 1, 20);
    // // cout << Head->val << " " << Head->next->val << " " << Head->next->next->val << " " ;
    // cout << Size(Head)<<endl;
    print_N(Head);
    print_rev(tail);
    return 0;
}
