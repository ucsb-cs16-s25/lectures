#include <iostream>
using namespace std;

// Structure representing a single node in the linked list
struct Node
{
    int data;   // Value stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head; // Pointer to the first node in the linked list
    Node *tail; // (Currently unused) Pointer to the last node in the linked list

    // Helper function to recursively remove all nodes with the target value
    Node *remove_recursive(Node *h, int target);

public:
    LinkedList() : head(nullptr), tail(nullptr) {} // Constructor initializes an empty list
    ~LinkedList();                                 // Destructor to free memory

    void append(int newValue); // Adds a new node at the end of the list
    void display();            // Prints the elements of the list
    void remove(int target);   // Removes all nodes with the given value
};

// Adds a new node at the end of the list
void LinkedList::append(int newValue)
{
    Node *newNode = new Node(newValue); // Create a new node with the given value

    if (!head) // If the list is empty, set the new node as head (and optionally tail)
    {
        head = newNode;
        return;
    }

    Node *curr = head;
    while (curr->next) // Traverse to the last node
    {
        curr = curr->next;
    }
    curr->next = newNode; // Append the new node
}

// Removes all nodes with the target value by calling the recursive helper
void LinkedList::remove(int target)
{
    head = remove_recursive(head, target); // Update head in case it's deleted
}

// Recursively removes all nodes with the given target value from the list
Node *LinkedList::remove_recursive(Node *h, int target)
{
    if (!h)
        return nullptr;

    // Recursively process the rest of the list first
    h->next = remove_recursive(h->next, target);

    // If the current node matches the target, delete it and return the next node
    if (h->data == target)
    {
        Node *temp = h->next;
        delete h;
        return temp;
    }

    return h; // Otherwise, keep the current node
}

// Prints the elements of the list
void LinkedList::display()
{
    if (!head)
    {
        cout << "The list is empty" << endl;
        return;
    }

    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// Destructor to clean up all dynamically allocated nodes
LinkedList::~LinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    LinkedList ll;

    ll.append(10);
    ll.append(20);
    ll.append(30);
    ll.append(40);
    ll.append(20);
    ll.append(50);
    ll.display();

    ll.remove(20);
    ll.display();

    return 0; // Destructor automatically called here
}