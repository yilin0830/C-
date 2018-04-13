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

class Stack {
    public:
        node *top;
        //
        void push(node *n) {
            n->next = top;
            top = n;
        }
        //
        void pop() {
            node *n = top;
            cout << n->data <<endl;
            top = top->next;
            delete(n);
        }

        void printStack() {
            node *ptr = top;
            while(ptr!=NULL){
                cout << ptr->data <<endl;
                ptr = ptr->next;
            }
        }
        Stack() {
            top = NULL;
        }
};

void testStack() {
    Stack S;

    node *n1 = new node(5);
    node *n2 = new node(8);
    node *n3 = new node(12);

    S.push(n1);
    S.push(n2);
    S.push(n3);

    S.printStack();

    S.pop();

    S.printStack();
    delete [] n1;
    delete [] n2;
    delete [] n3;
}
int main() {
    cout << "Hello world!" << endl;
    testStack();
    return 0;
}
