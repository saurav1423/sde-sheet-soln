Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

//brute force
first ask interviewer if values are unique or Not
if yes the use unordered map and put value in it if it comes first time otherwise return the value.
if no, use unordered map and put whole node in it

//optimal
 ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
            
        }
        
        return NULL;
        
    }
time - 0(N)    
space - 0(1)

for intution, see bonuss 