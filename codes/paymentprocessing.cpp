#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    string data;
    Node* next;

    // Node constructor
    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;

    // LinkedList constructor
    LinkedList() {
        head = nullptr;
    }

    // Append function to add a node to the end of the list
    void append(string data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = new_node;
    }

    // Function to print the linked list
    void print_list() {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

// Example usage
int main() {
    LinkedList transactions;
    transactions.append("Transaction1");
    transactions.append("Transaction2");
    transactions.print_list();
    return 0;
}
