Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

//brute force
one solution will be, we will keep shifting the last node to first by k
while(k--){
    traverse till end of list
    point last node to head and point second last node to NULL
}

time - 0(K*N)
space - 0(1)

//optimal
 ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL)
            return NULL;
        
        ListNode* temp = head;
        int len = 1;
        while(temp->next){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        int toMove = len - (k%len);
        
        while(toMove--){
            temp = temp->next;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        
        return newHead;
        
    }

time - 0(N) + 0(N-K) , N is length of linked list
space - 0(1)