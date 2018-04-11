#include <iostream>
using namespace std;
class node {
    public:
        int data;
        node* next;
        node(int x) {
            data = x;
            next = NULL;
        }
};

class LinkedList {
    public:
        node *head;
        //
        void addAtFront(node *n) {
            n->next = head;
            head = n;
        }
        //
        bool isEmpty() {
            if(head == NULL)
                return 1;
            else
                return 0;
        }
        //
        void addAtEnd(node *n) {
            if(head == NULL) {
                head = n;
                n->next = NULL;
            }
            else {
                node *n2 = getLastNode();
                n2->next = n;
            }
        }
        //
        node *getLastNode() {
            node* ptr = head;
            while(ptr->next!=NULL) {
                ptr = ptr->next;
            }
            return ptr;
        }
        //
        node *search(int k) {
            node *ptr = head;
            while(ptr->next!=NULL && ptr->data!=k) {
                ptr = ptr->next;
            }
            return ptr;
        }
        //
        node *deleteNode(int x) {
            node *n = search(x);
            node *ptr = head;
            if(ptr == n){
                ptr->next = n->next;
                return n;
            }
            else {
                while(ptr->next!=n) {
                    ptr = ptr->next;
                }
                ptr->next = n->next;
                return n;
            }
        }
        //
        void printList() {
            node *ptr = head;
            while(ptr!=NULL) {
                cout << ptr->data << "->";
                ptr = ptr->next;
            }
        }
        //
        LinkedList() {
            head = NULL;
        }
};

void testLinkedList() {
    LinkedList L;

    node *n1 = new node(5);
    node *n2 = new node(8);
    node *n3 = new node(12);

    L.addAtFront(n1);
    L.addAtFront(n2);
    L.addAtEnd(n3);

    L.printList();

    delete [] n1;
    delete [] n2;
    delete [] n3;
}
int main() {
    cout << "Hello world!" << endl;
    testLinkedList();
    return 0;
}
