/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     int fun(ListNode *h)
     {
         int c=0;
         while(h!=NULL)
         {
             c++;
             h=h->next;
         }
         return c;
     }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=fun(headA);
        int b=fun(headB);
        while(a!=0 and b!=0)
        {
            if(a==b)
            {
                if(headA==headB)
                {
                    return headA;
                }
                headA=headA->next;
                headB=headB->next;
                a--;
                b--;
            }
           else if(a>b)
            {
                headA=headA->next;
                a--;
            }
            else
            {
                headB=headB->next;
                b--;
            }
        }
        return NULL;
        }
};