class Solution {
public:
    //Optimal Solution with O(1)space by reversing the next half of list.
    
    ListNode* reverseList(ListNode* ptr)
    {
         ListNode* curr=ptr;
         ListNode* prev=NULL;
         ListNode* front=ptr;
        
        while(front!=NULL)
        {
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
      //Traversing to the previous node of the middle node of the list
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        ListNode* temp=head; 
        ListNode* temp1=slow->next;
        //Traversal check of values in both halves of the list
        while(temp1!=NULL)
        {
            if(temp->val!=temp1->val)
                return false;
            temp=temp->next;
            temp1=temp1->next;
        }
        return true;
        slow->next=reverseList(slow->next);
    }
};