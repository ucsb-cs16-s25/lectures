#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

// Function to create a new node with a given value
Node *createNode(int value)
{
  Node *newNode = new Node; // Allocate memory for a new node
  newNode->data = value;    // Set the data
  newNode->next = nullptr;  // Initialize next to nullptr
  return newNode;           // Return the newly created node
}

void printList(Node *head)
{
  Node *curr = head;
  while (curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  Node *head; // Pointer to the first node in the list
  Node *newNode;    // Temporary pointer to create and link nodes

  // Create the first node with value 1 and make it the head
  head = createNode(1);

  // Create a node with value 2 and prepend it to the list
  newNode = createNode(2);
  newNode->next = head; // Link it to the current head
  head = newNode;       // Update head to point to the new node

  // Create a node with value 3 and prepend it to the list
  newNode = createNode(3);
  newNode->next = head; // Link it to the current head
  head = newNode;       // Update head to point to the new node

  // Print the list: output should be "3 2 1"
  printList(head);

  return 0;
}