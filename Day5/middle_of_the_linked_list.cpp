Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

//brute force
we will count the number of node first. Then we divide it by 2 and add 1 (middle number defition according to question)
then we will again traverse and return the node.

time - 0(N) + 0(N/2)


//optimal

ListNode* middleNode(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }

time - 0(N)    

//let say ll is , 1->2->3->4->5->6
to abi according to question ans 4 hai, but agar koi 3 print krne khe to hmlog previous ko store kr skte, uss tarike se ho jayega
//even ll ke case me fast hamesa 2nd last node pe rukta hai aur odd ll ke case me last node pe. you can use this logic to implement above line