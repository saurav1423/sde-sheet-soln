Given the head of a singly linked list, return true if it is a palindrome.

//brute force
take an array, put every element in that and then check it is palindrome or not
time - 0(N) + 0(N)
space - 0(N)

//optimal
It will be easy if we can find the middle of linked list.
after finding middle of linked list, just reverse the list and then check for palindrome

bool isPalindrome(ListNode* head) {
        
        //navie
        //push all node value in vector and check if vector is palindrome or not
        
        if(head == NULL || head->next == NULL)return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            
            head = head->next;
            slow = slow->next;
        }
        
        return true;
        
    }
    
    
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        ListNode* next = NULL;
        
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }