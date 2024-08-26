class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL){
            return NULL;
        }

        
        ListNode* check =head;
        for(int i=0;i<k;i++){
            if(!check) return head;
            check=check->next;
        }

        
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *forward=NULL;
        int count=0;
        
        while(curr!=NULL&&count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }

        //  Recursion dekh lega 
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }

       
        return prev;
    }
};
