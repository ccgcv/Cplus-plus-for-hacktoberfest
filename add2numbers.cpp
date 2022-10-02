ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * head = NULL;
        ListNode * tail = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry)
        {
            int a = 0;
            if(l1 != NULL)
            {
               a = l1->val;
            }
            int b = 0;
            if(l2 != NULL)
            {
                b = l2->val;
            }
            int sum = a + b + carry;
            int num = sum % 10;
            ListNode * temp = new ListNode(num);
            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail= tail->next;
            }
            carry = sum/10;
            
            if(l1 != NULL)
            {
               l1 = l1->next;
            }
            if(l2 != NULL)
            {
                l2 = l2->next;
            }
            
        }
        return head;
    }
