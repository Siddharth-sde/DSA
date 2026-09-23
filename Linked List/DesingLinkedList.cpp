/*
    ## REVIEW
    Problem - 707. Design Linked List

    Pattern:
    Singly Linked List - Pointer Traversal

    The main idea was to understand how nodes are connected using pointers
    and how insertion, deletion, and traversal work by changing the next
    pointer of the appropriate node.

    The biggest challenge was handling edge cases:
        Empty list
        Inserting/deleting at the head
        Invalid indices
        Deleting the last node

    A key realization was that changing a pointer like temp = nullptr does
    not modify the linked list. To actually modify the list, I need to
    change the next pointer of the previous node.

    Key Learning:
    Many edge cases don't need separate hardcoded logic. For example,
    temp->next = temp->next->next naturally handles deleting both a middle
    node and the last node because the last node's next is already nullptr.
*/


struct Node{
    int value;
    Node* next;
};

class MyLinkedList {
public:
    Node* head;
    Node* temp;
    MyLinkedList() {
        head =nullptr;
    }
    
    int get(int index) {
        if (index < 0) return -1;
        temp = head;
        if (temp == NULL) return -1;
        for(int i = 0; i < index ; i++){
            temp = temp -> next; 
        }
        if (temp == NULL) return -1;
        return temp -> value;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node();
        newNode->next = head;
        newNode ->value = val;
        head = newNode;
    }
    
    void addAtTail(int val) {
        temp = head;
        if (temp == NULL){
            Node* newNode = new Node;
            newNode -> value = val;
            newNode -> next = NULL;
            head = newNode;
            return;
        }
        while (temp -> next != nullptr){
            temp = temp -> next;
        }
        Node* newNode = new Node();
        newNode -> next = nullptr;
        newNode -> value = val;
        temp -> next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        temp = head;
        if (index == 0){
            Node* newNode = new Node;
            newNode -> value = val;
            newNode -> next = head;
            head = newNode;
            return;
        }
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        } 
        if (temp == NULL) return;
        Node* newNode = new Node();
        newNode -> value = val;
        newNode -> next = temp -> next;
        temp -> next= newNode;
    }
    
    void deleteAtIndex(int index) {
        if (head == NULL) return;
        temp = head;
        if (index == 0){
            head = head -> next;
            return;
        }
        for(int i = 0; i < index - 1; i++){
            temp = temp -> next;
        }
        if (temp == NULL || temp -> next ==NULL) return;
        temp -> next= temp ->next ->next;
    }
};