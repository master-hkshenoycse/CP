#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode *get_rev(ListNode *head){
        if(head==NULL or head->next==NULL) {
            return head;
        }

        ListNode *prev=NULL,*nx;

        while(head){
            nx=head->next;
            head->next=prev;
            prev=head;
            head=nx;
        }

        return prev;
    }
    int pairSum(ListNode* head) {


        ListNode *slow=head,*fast=head,*prev=NULL;

        while(fast and fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;

        }      

        prev->next=get_rev(slow);
        
        prev=prev->next;
        
        int ans=0;
        while(prev){
            ans=max(ans,head->val+prev->val);
            prev=prev->next;
            head=head->next;
        }
        
        return ans;

    }
};