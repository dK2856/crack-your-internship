class Solution {
public:
    // TC-O(N*K*Log(N*K))  ||  SC-O(N*K)
    // Using Priority Queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int> pq;
        
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* ptr=dummy;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            
            while(temp!=NULL)
            {
                pq.push(-(temp->val));
                temp=temp->next;
            }
        }
        
        while(!pq.empty())
        {
            int nodeVal=pq.top(); pq.pop();
            
            ListNode* node=new ListNode(-(nodeVal));
            
            ptr->next=node;  ptr=ptr->next;
        }
        
        return dummy->next;
    }
};