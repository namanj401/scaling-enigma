/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * Hello
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;ListNode* p=l1;ListNode* q=l2;
        ListNode* head= new ListNode(0);
        ListNode* temp= head;
        while(p!=NULL || q!=NULL)
        {   
            int x=0,y=0;
            if(p!=NULL)
                 x= p->val;
            if(q!=NULL)
                 y= q->val;
            int data= x+y+ carry;
            carry= data/10;
            data=data%10;
            temp->next=new ListNode(data);
            temp=temp->next;
            if(p!=NULL)
                p=p->next;
            if(q!=NULL)
                q=q->next;
            
            
        }
        if(carry!=0)
            temp->next=new ListNode(carry);
        return head->next;
    }
    
};
