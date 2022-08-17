Input: Head of following linked list 
1->2->3->4->NULL 
Output: Linked list should be changed to, 
4->3->2->1->NULL

//iterative

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            next = NULL;
        }
};


class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }

        void push(int data){
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<"  ";
                temp = temp->next;
            }
              
        }

        Node* reverse(){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }
};


int main(){

   LinkedList ll;
   ll.push(8);
   ll.push(12);
   ll.push(9);
   ll.push(2);
   ll.push(15);

   ll.print();
   ll.reverse();
   cout<<"   ";
   ll.print();


}



//Recursive

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this->data = data;
            next = NULL;
        }
};


class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }

        void push(int data){
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<"  ";
                temp = temp->next;
            }
              
        }

        Node* reverse(Node* head){
            if(head == NULL || head->next == NULL)
               return head;

            Node* newHead = reverse(head->next);
            head->next->next = head;   
            head->next = NULL;

            return newHead;
        }
};

//eg
1 -> 2 -> 3-> 4
recursive call hote hote, newHead 4 pe pahuch jayega, then 4 ka head->next null hai to 4 he return hoga, then at 3, head->next->next mtlb
4 ke next me 3 ka address rkh rhe aur 3 ke next me null, and similarly doing for every node


int main(){

   LinkedList ll;
   ll.push(8);
   ll.push(12);
   ll.push(9);
   ll.push(2);
   ll.push(15);

   ll.print();
   ll.head = ll.reverse(ll.head);
   cout << "\nReversed Linked list \n";
   ll.print();


}

