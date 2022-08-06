You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

//brute force
same optimal wala solution, bss jha pe direct link kr rhe, wha new node bna ke usme value dalenge.
time - 0(N1) + 0(N2)
space - 0(N1 + N2)

//optimal
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        
        temp->next = list1 ? list1 : list2;
        
        return head->next;
        
    }
time - 0(N1) + 0(N2)
space - 0(1)    