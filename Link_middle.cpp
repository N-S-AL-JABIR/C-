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
        return;
    }
    Node *tmp = Head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
}
int middle(Node *Head, int c)
{

    Node *jj = Head;
    for (int i = 0; i < c-1; i++)
    {
        if (jj->val > jj->next->val)
        {
            return 0;
        }

        jj = jj->next;
    }
}
int main()
{
    Node *Head = NULL;
    int c = 0;
    while (true)
    {
        int v;
        cin >> v;
        c++;
        if (v == -1)
        {
            break;
        }
        insert_at_tail(Head, v);
    }
    c = c - 1;

    int x = middle(Head, c);
    // print_linked_list(Head);
    if (x == 0)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;

    return 0;
}
