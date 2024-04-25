#include <iostream> 
#include <Windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasDuplicatePair(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        int currentValue = current->data;
        Node* runner = current->next;

        while (runner != nullptr) {
            if (runner->data == currentValue)
                return true;
            runner = runner->next;
        }
        current = current->next;
    }
    return false;
}

void createList(Node*& head, Node*& tail, int valuesV1[], int valuesV2[], int size) {
    head = nullptr;
    tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node* newNodeV1 = new Node();
        newNodeV1->data = valuesV1[i];
        newNodeV1->next = nullptr;

        Node* newNodeV2 = new Node();
        newNodeV2->data = valuesV2[i];
        newNodeV2->next = nullptr;

        if (head == nullptr) {
            head = newNodeV1;
            tail = newNodeV2;
        }
        else {
            tail->next = newNodeV1;
            tail = newNodeV2;
        }
        newNodeV1->next = newNodeV2;
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    int valuesV1[] = { 1, 2, 3, 4, 5 };
    int valuesV2[] = { 11, 12, 13, 14, 15 };
    int size = sizeof(valuesV1) / sizeof(valuesV1[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createList(head, tail, valuesV1, valuesV2, size);

    cout << "List of elements:" << endl;
    printList(head);

    if (hasDuplicatePair(head))
        cout << "The list contains a pair of elements with the same values." << endl;
    else
        cout << "The list does not contain a pair of elements with the same values." << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}