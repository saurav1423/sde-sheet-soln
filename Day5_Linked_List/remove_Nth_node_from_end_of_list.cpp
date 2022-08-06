Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], N = 2
Output: [1,2,3,5]

//brute force
Find length of linked list, subtract length from given K and then traverse that much and remove the node
time - 0(N) + 0(N-K)

//optimal
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        
        //if n = 0, then we have to remove first node
        if(fast == NULL){
            head = head->next;
            return head;
        }
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
        
    }
time - 0(N)
