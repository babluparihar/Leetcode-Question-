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
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    int list_len(ListNode *head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp=head;
        ListNode *second=NULL;
        ListNode *third=NULL;
        ListNode *first=head;
        int len=list_len(head);
        if(left==right)
        {
            return head;
        }
        if(left==1 and right!=len)
        {
            ListNode *t=head;
            ListNode *f=head;
            right--;
            while(right--)
            {
                t=t->next;
            }
            ListNode *add=t->next;
            t->next=NULL;
            f=reverse(f);
            ListNode *ans=f;
            while(f->next!=NULL)
            {
                f=f->next;
            }
            f->next=add;
            return ans;
        }
        if(right==len)
        {
            if(left==1 and right==len)
            {
                head=reverse(head);
                return head;
            }
            else
            {
                ListNode *f=head;
                ListNode *t=NULL;
                for(int i=1;i<=left;i++)
                {
                    if(i<left)
                    {
                        t=head;
                    }
                    else
                    {
                        t->next=NULL;
                        break;
                    }
                    head=head->next;
                }
                head=reverse(head);
                t->next=head;
                return f;
            }
        }
        for(int i=1;head!=NULL and i<=right;i++)
        {
            if(i<left)
            {
                temp=head;
            }
            else if(i==left)
            {
                temp->next=NULL;
                second=head;
            }
            else if (i==right)
            {
                if(head->next!=NULL)
                {
                    third=head->next;
                    head->next=NULL;
                }
                else
                {
                    third=NULL;
                }
                break;
            }
            head=head->next;
        }
        if(second==NULL)
        {
            return first;
        }
        second=reverse(second);
        temp->next=second;
        while(second!=NULL and second->next!=NULL)
        {
            second=second->next;
        }
        if(third!=NULL)
        {    
        second->next=third;
        }
        return first;
    }
};