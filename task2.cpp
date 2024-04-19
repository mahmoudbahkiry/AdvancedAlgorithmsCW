#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->prev = temp->next = nullptr;
    return temp;
}

void insertEnd(Node** head, int data) {
    Node* temp = newNode(data);
    if (*head == nullptr) {
        *head = temp;
    } else {
        Node* last = *head;
        while (last->next != nullptr)
            last = last->next;
        last->next = temp;
        temp->prev = last;
    }
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertEnd(&head, 7);
    insertEnd(&head, 90);
    insertEnd(&head, 4);
    insertEnd(&head, 54);
    insertEnd(&head, 21);
    insertEnd(&head, 0);


    cout << "Original list: ";
    printList(head);

    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    quickSort(head, lastNode);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}