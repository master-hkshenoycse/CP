
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr=head;
        int rem=n;

        
        while(rem--){
            curr=curr->next;
        }

        ListNode *prev=NULL,*iter=head,*sol=head;

        while(curr){
            prev=iter;
            iter=iter->next;
            curr=curr->next;
            
        }

        if(prev==NULL){
            sol=iter->next;
        }else{
            prev->next=iter->next;

        }

        return sol;
    }
};