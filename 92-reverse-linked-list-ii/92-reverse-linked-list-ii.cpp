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
    ListNode *reverse(ListNode *root)
    {
        ListNode *p=root,*q=NULL,*r=NULL;
        while(p)
        {
            r=q;q=p;p=p->next;
            q->next=r;
        }
        return q;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *L=head,*R=head;
        bool flag=true;
        ListNode *LP=NULL;
        for(int i=1;R!=NULL && i<=right-1;i++)
        {
             if(flag==true)
             {
                 if(i==left)
                 {
                     flag=false;
                 }
                 else
                 {
                     LP=L;
                     L=L->next;
                 }
             }
            R=R->next;
        }
        ListNode *LL=L;
        ListNode *RN=R->next;
        R->next=NULL;
        L=reverse(L);
        if(LP!=NULL)
        {
            LP->next=L;
        }
        LL->next=RN;
        if(LP==NULL)
        {
            return L;
        }
        return head;
    }
};