Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

//brute force
traverse linked list 1 for every node of linked list 2, if you find match, return it and if you reach end means no intersection present.
time - 0(M*N)

//better
use unordered map. hash address of all node of linked list 1 and then traverse linked list 2 and check for every node
time - 0(M+N)
space - 0(M)


//optimal
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != temp2){
            temp1 = temp1 ? temp1->next : headB;
            temp2 = temp2 ? temp2->next : headA;
        }
        
        return temp1;
    }

time - 0(2(M+N))   
conside ll1 = 2,3,4,5  and ll2 = 1,2,3,4,5 
space - 0(1)