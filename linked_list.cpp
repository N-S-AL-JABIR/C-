#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&Head, int v)
{
    Node *node = new Node(v);
    if (Head == NULL)
    {
        Head = node;
        cout << "inserted at Head" << endl
             << endl;
        return;
    }
    Node *tmp = Head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void print_linked_list(Node *Head)
{
    cout << endl;
    cout << "Your linked list: ";
    Node *tmp = Head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl
         << endl;
}

void insert_at_position(Node *Head, int po, int v)
{
    Node *node = new Node(v);
    Node *tmp = Head;
    for (int i = 1; i < po; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            cout << endl
                 << "Invalid Index" << endl
                 << endl;
            return;
        }
    }
    node->next = tmp->next;
    tmp->next = node;
    cout << endl
         << endl
         << "iserted position." << endl
         << endl;
}

void insert_at_Head(Node *&Head, int v)
{
    Node *node = new Node(v);
    node->next = Head;
    Head = node;
    cout << endl
         << endl
         << "iserted at Head." << endl
         << endl;
}

void delete_position(Node *Head, int po)
{
    Node *tmp = Head;
    for (int i = 1; i < po; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            cout << endl
                 << "Invalid Index" << endl
                 << endl;
            return;
        }
    }
    if (tmp->next == NULL)
    {
        cout << endl
             << "Invalid Index" << endl
             << endl;
        return;
    }
    Node *dnode = tmp->next;
    tmp->next = tmp->next->next;
    delete dnode;
    cout << "Deleted psition" << endl
         << endl;
}

void Delete_Head(Node *&Head)
{
    if (Head == NULL)
    {
        cout << endl
             << "Head is not available" << endl
             << endl;
        return;
    }
    Node *dHead = Head;
    Head = Head->next;
    delete dHead;
    cout << "Head Deleted" << endl
         << endl;
}

int Size(Node *Head)
{
    int c = 0;
    for (Node *i = Head; i != NULL; i = i->next)
    {
        c++;
    }
    return c;
}

int main()
{
    Node *Head = NULL;
    while (true)
    {
        cout << "Option 1: Insert at tail;" << endl;
        cout << "Option 2: print linked list;" << endl;
        cout << "Option 3: Insert at any position;" << endl;
        cout << "Option 4: Delete any position;" << endl;
        cout << "Option 5: terminate;" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            int v;
            cout << "Please Inter a value: ";
            cin >> v;
            insert_at_tail(Head, v);
        }
        else if (op == 2)
        {
            print_linked_list(Head);
        }
        else if (op == 3)
        {
            cout << "Inter position: ";
            int po, v;
            cin >> po;
            cout << "Inter value: ";
            cin >> v;
            if (po == 0)
            {
                insert_at_Head(Head, v);
            }
            else
            {
                insert_at_position(Head, po, v);
            }
        }
        else if (op == 4)
        {
            cout << "Inter position: ";
            int po, v;
            cin >> po;
            if (po == 0)
            {
                Delete_Head(Head);
            }
            else
            {
                delete_position(Head, po);
            }
        }

        else if (op == 5)
        {
            break;
        }
    }
    return 0;
}
