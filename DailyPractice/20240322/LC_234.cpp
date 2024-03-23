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
    ListNode *reverse(ListNode *head){
        if(head==NULL){
            return head;
        }
        ListNode *prev=NULL,*nx=NULL;
        while(head){
            nx=head->next;
            head->next=prev;
            prev=head;
            head=nx;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head==NULL or head->next==NULL){
            return 1;
        }

        ListNode *fast=head,*slow=head;

        while(fast and fast->next){
            fast=fast->next->next;
            
            if(fast){
                slow=slow->next;
            }
        }
        slow->next=reverse(slow->next);

        ListNode *en=slow->next;

        while(en and head){
            if(en->val != head->val){
                return 0;
            }
            en=en->next;
            head=head->next;
        }
        return 1;
    }
};