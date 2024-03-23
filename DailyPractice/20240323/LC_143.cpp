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
    ListNode *reverse(ListNode* head){
        ListNode *prev=NULL,*nx=NULL;
        while(head){
            nx=head->next;
            head->next=prev;
            prev=head;
            head=nx;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL){
            return;
        }

        ListNode *slow=head,*fast=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        slow=reverse(slow);

        ListNode *x=head,*y=slow,*nx_x,*nx_y;

        while(x!=slow and y){
            nx_x=x->next;
            nx_y=y->next;
            x->next=y;
            y->next=nx_x;

            x=nx_x;
            y=nx_y;
        }

        if(x){
            x->next=NULL;
        }
    }
};