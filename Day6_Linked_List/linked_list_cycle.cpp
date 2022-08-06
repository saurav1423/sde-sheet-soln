Given head, the head of a linked list, determine if the linked list has a cycle in it.

//brute force
use unordered map to store numbers(whole treenode*) if it is not present and return true if it is present in unordered map

//optimal
bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head == NULL || head->next == NULL)
            return false;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
        
    }
time - 0(N)    
space - 0(1)

intution 
x -> y
let fast at x and slow at y, next step they are bound to meet(you can take any example, they will meet for sure)

a -> b -> c -> d -> e -> f
fast at a and slow at d
next step, fast will be at c and slow at e
next step, fast will be at e and slow at f
next step they are bound to meet