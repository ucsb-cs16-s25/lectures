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

// Function to delete the entire linked list and free memory
void deleteList(Node *&head)
{
    Node *curr = head; // Initialize pointer to traverse the list
    Node *toDelete = nullptr;
    while (curr) // Loop through all nodes in the list
    {
        toDelete = curr;   // Store the current node
        curr = curr->next; // Move to the next node
        delete toDelete;   // Free memory of the current node
    }
    head = nullptr; // ✅ Prevents accessing a dangling pointer after deletion
}

void prepend(Node *&head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head)
{
    if (!head)
    {
        cout << "The list is empty" << endl;
        return;
    }
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    prepend(head, 4);
    prepend(head, 8);
    prepend(head, 2);

    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}