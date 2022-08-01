
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size=0;
    Node* head=new Node(0);
    MyLinkedList() {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp=head->next;
        head->next=new Node(val);
        head->next->next=temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=new Node(val);
        temp->next->next=temp1;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=temp1->next;
        //temp1->next=NULL;
        size--;
        delete temp1;
    }
};
// class List{
//     public:
//     int val;
//     List*next;
//     List(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };
// class MyLinkedList {
// public:
//     List*head;
//     MyLinkedList() {
        
//     }
    
//     int get(int index) {
//         List*temp = head;
//         while(temp!=NULL && index--)
//         {
//             temp=temp->next;
//         }
//         if(temp!=NULL)
//             return temp->val;
//         return -1;
//     }
    
//     void addAtHead(int val) {
//         List*temp = new List(val);
//         temp->next = head;
//         head=temp;
//     }
    
//     void addAtTail(int val) {
//         List*temp=head;
//         while(temp!=NULL && temp->next!=NULL)
//         {
//             temp=temp->next;
//         }
//         List *node = new List(val);
//         if(temp!=NULL)temp->next=node;
//     }
//     //manage index--
//     void addAtIndex(int index, int val) {
//         List *temp = head;
//         List* node = new List(val);
//         if(index==0){
//             node->next=head;
//             head=node;
//         }

//         else{
//             index--;
//             while(index-- && temp!=NULL && temp->next!=NULL)
//             {
//                 temp=temp->next;
//             }
//             List*nt =NULL;
//             if(temp!=NULL)
//             nt = temp->next;
//             temp->next = node;
//             node->next = nt;
//         }
//     }
    
//     void deleteAtIndex(int index) {
//         List*temp = head;
//         if(index==0)head=head->next;
//         else{
//             index--;
//             while(index-- && temp!=NULL && temp->next!=NULL)
//             {
//                 temp=temp->next;
//             }
//             if(temp->next)
//             temp->next = temp->next->next;
//         }
        
//     }
// };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */