/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
         int len=0;  ListNode*cur=head;
        while(cur!=NULL)
        { len++ ;cur=cur->next;}                                                                                  //count length of linked list
        
        ListNode* dummy=new ListNode(0) ;
		ListNode *nex=NULL ,*prev=NULL;
        dummy->next=head ; prev=dummy;
        
        int k=1;
		
        while(len>0)
        {
            cur=prev->next;
            nex=cur->next;
                                                
            if((k%2!=0 && len>=k) || (len<k && len%2!=0))
               for(int i=1;i<k && (len-i) ;i++)                                     // no reverse at odd group and if last group is odd
                cur=cur->next;
            
            else if((k%2==0 && len>=k) || (len<k && len%2==0)) 
                for(int i=1;i<k && (len-i) ;i++)                                // reverse at even group and if last group is even
               {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
               }
            
            len-=k;
            prev=cur;
            k++;
        }
        return dummy->next;
    }
};