#include <iostream>

struct Node
{
    int value;
    Node* next;

    Node(int v): value(v), next(NULL) {};
};

class LinkedList{
    Node* head = new Node(0);
    Node* last = NULL;

    public:
        LinkedList(int value) {
            this->head->value = value;
            this->last = this->head;
        }

        ~LinkedList(){
            Node *current = this->head;
            while (current)
            {
                this->head = this->head->next;
                delete current;
                current = this->head;
            }
        }

        void append(int value){
            Node* newNode = new Node(value);
            this->last->next = newNode;
            this->last = newNode;
        }

        void printList(){
            Node* current = this->head;
            while (current){
                std::cout<<current->value<<" ";
                current = current->next;
            }
        }

        void reverse(){
            Node *pre = NULL, *cur = this->head;
            while(cur){
                Node *next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            this->head = pre;
        }
};

int main(){
    LinkedList list(0);
    for(int i = 1; i <= 5; i++) list.append(i);
    list.reverse();
    list.printList();
    return 0;
}
