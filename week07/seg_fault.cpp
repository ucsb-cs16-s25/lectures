#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node *findTail(Node *head)
{
    cout << 4 << endl;
    Node *curr = head;
    cout << 5 << endl;
    while (curr->next)
    {
        cout << 6 << endl;
        curr = curr->next;
    }
    cout << 7 << endl;
    return curr;
}

// Function to append a node with the given value to the end of the list
void append(Node *&head, int value)
{
    cout << 2 << endl;
    Node *newNode = createNode(value);
    cout << 3 << endl;
    // ❗ BUG: if head is nullptr, findTail(head) will crash
    findTail(head)->next = newNode; // Link the new node to the end of the list
}

// // Fix: handle the empty list case in append
// void append(Node *&head, int value)
// {
//     Node *newNode = createNode(value);
//     if (head == nullptr)
//     {
//         head = newNode;        // If list is empty, new node becomes the head
//     }
//     else
//     {
//         findTail(head)->next = newNode;
//     }
// }

int main()
{
    Node *head = nullptr; // Initialize an empty list
    cout << 1 << endl;
    append(head, 40);
    cout << 8 << endl;

    return 0;
}
