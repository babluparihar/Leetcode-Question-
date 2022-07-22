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
    ListNode* partition(ListNode* head, int x) {
        vector<int>vec;
        while(head!=NULL)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        ListNode *res=new ListNode();
        ListNode *last=res;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]<x)
            {
                ListNode *t=new ListNode(vec[i]);
                last->next=t;
                last=t;
                last->next=NULL;
            }
        }
                for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>=x)
            {
                ListNode *t=new ListNode(vec[i]);
                last->next=t;
                last=t;
                last->next=NULL;
            }
        }
        return res->next;
        
    }
};