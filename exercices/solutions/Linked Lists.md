**Implement a Singly Linked List with Operations:**

```c++
#include <iostream>

// Define a structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Delete a node with the given value from the list
    void deleteNode(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Traverse and print the linked list
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);
    myList.insertAtBeginning(0);

    myList.printList(); // Output: 0 -> 1 -> 2 -> 3 -> nullptr

    myList.deleteNode(2);
    myList.printList(); // Output: 0 -> 1 -> 3 -> nullptr

    return 0;
}
```

**Detect and Remove Loops in a Linked List:**

```c++
#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // ... (Insertion and other operations as before)

    // Detect and remove a loop in the linked list
    bool detectAndRemoveLoop() {
        if (!head || !head->next) {
            return false; // No loop exists
        }

        Node* slow = head;
        Node* fast = head;

        // Move slow by one step and fast by two steps until they meet
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Loop detected
                break;
            }
        }

        if (slow != fast) {
            return false; // No loop found
        }

        // Move one pointer to the head and keep the other at the meeting point
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the loop by setting the next of the last node to nullptr
        fast->next = nullptr;
        return true;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);

    // Create a loop for testing
    myList.head->next->next->next = myList.head;

    if (myList.detectAndRemoveLoop()) {
        std::cout << "Loop detected and removed." << std::endl;
    } else {
        std::cout << "No loop found." << std::endl;
    }

    return 0;
}
```

**Reverse a Linked List (Iteratively and Recursively):**

```c++
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // ... (Insertion and other operations as before)

    // Reverse the linked list iteratively
    void reverseIteratively() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev; // Update the head
    }

    // Reverse the linked list recursively
    Node* reverseRecursively(Node* current) {
        if (!current || !current->next) {
            return current;
        }

        Node* rest = reverseRecursively(current->next);
        current->next->next = current;
        current->next = nullptr;
        return rest;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);

    myList.printList(); // Output: 1 -> 2 -> 3 -> nullptr

    myList.reverseIteratively();
    myList.printList(); // Output: 3 -> 2 -> 1 -> nullptr

    myList.head = myList.reverseRecursively(myList.head);
    myList.printList(); // Output: 1 -> 2 -> 3 -> nullptr

    return 0;
}
```