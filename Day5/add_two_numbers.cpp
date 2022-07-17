ou are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


//iss question ka koi brute force ni hai, direct optimal hai. so interviewer ka time kill krne ke liye different question kro like

does two numbers contain any leading zero?

l1 bda le lo aur l2 chota lelo, aur answer confirm kro
l1 chota le lo aur l2 bda lelo aur answer confirm kro etc


//optimal
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0;
        int carry = 0;
        ListNode* temp = new ListNode();
        ListNode* head = temp;
        
        while(l1 || l2 || carry){
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            sum = 0;
            temp = temp->next;
            
        }
        return head->next;
        
    }

time - 0(max(N1, N2)), N1 and N2 are respectively length of l1 and l2
