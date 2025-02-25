#include <iostream>
using namespace std;

class Node {
    public: 
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {
        
    }

    //Visualized the linked list

    void display() {
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int get(int index) {
        if(index >= size)
            return -1;
        Node* temp = head;
        for(int i=0; i<index; ++i)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* nnode = new Node(val);
        nnode->next = head;
        head = nnode;
        if(size==0)
            tail = nnode;
        // Visualized the linked list
        cout<<"Added at head "<< val<<endl;
        display();
        size++;
    }
    
    void addAtTail(int val) {
        if(size ==0) {
            addAtHead(val);
            return;
        }
        Node* nnode = new Node(val);
        tail->next = nnode;
        tail = nnode;
        // Visualized the linked list
        cout<<"Added at Tail "<< val<<endl;
        display();
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)
            return;
        else if(index == size)
            addAtTail(val);
        else if(index==0)
            addAtHead(val);
        else {
            Node* temp =head;
            Node* nnode = new Node(val);
            for(int i=0; i<index-1; ++i) {
                temp = temp->next;
            }
            nnode->next = temp->next;
            temp->next = nnode;
            // Visualized the linked list
            cout<<"Added at index "<< index<<" val "<<val<<endl;
            display();
            
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)
            return;
        else if(index == size-1) {
           
            if(index==0){
                head==NULL;
                tail==NULL;
            }
            else {
                Node* temp = head;
                while(temp->next!=tail) {
                    temp= temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }
           
        }
        else if(index==0) {
            Node* temp = head;
            head = head->next;
            temp =NULL;
        }
        else {
            Node* temp = head;
            for(int i=0; i<index-1;++i) {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;
            
        }
        // Visualized the linked list
        cout<<"Deleted at index "<< index<<endl;
        display();
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->get(1);
    obj->deleteAtIndex(1);
    obj->get(1);
    return 0;
}