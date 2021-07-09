#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *head = NULL;

void push(int data)
{
    if (head == NULL)
    {
        head = new (Node);

        head->data = data;
        head->link = NULL;

        return;
    }

    Node *p = head;

    while (p->link != NULL)
    {
        p = p->link;
    }

    Node *current = new (Node);

    current->data = data;
    current->link = NULL;

    p->link = current;
}

void pop()
{
    Node *p = head;

    if (head == NULL)
    {
        cout << "Stack is already empty"
             << "\n";

        return;
    }
    else if (p->link == NULL)
    {
        free(p);

        head = NULL;

        return;
    }

    while (p->link->link != NULL)
    {
        p = p->link;
    }

    free(p->link);

    p->link = NULL;
}

void print()
{

    if (head == NULL)
    {
        cout << "Stack is empty"
             << "\n";

        return;
    }

    Node *p = head;
    int count = 0;

    while (p != NULL)
    {
        cout << p->data << "\n";

        p = p->link;
        count++;
    }

    cout << "--------------------"
         << "\n";

    cout << count << " elements in stack"
         << "\n";

    cout << "--------------------"
         << "\n";
}

bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }

    return false;
}

int main()
{
    push(5);
    push(6);
    push(4);
    push(1);

    print();

    if (isEmpty())
    {
        cout << "Stack is empty"
             << "\n";
    }
    else
    {
        cout << "Stack is not empty"
             << "\n";
    }

    return 0;
}