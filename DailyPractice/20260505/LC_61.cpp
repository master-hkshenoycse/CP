

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int get_len(ListNode *head){
        if(head==NULL){
            return 0;
        }

        return 1+get_len(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL or head->next==NULL){
            return head;
        }
        int n=get_len(head);
        k%=n;

        if(k==0){
            return head;
        }

        int rem=n-k;
        ListNode *prev=NULL,*nx,*first=head;
        while(rem--){
            nx=head->next;
            prev=head;
            head=head->next;
        }
        cout<<(nx->val)<<endl;
        prev->next=NULL;
     
        
        while(head){
            prev=head;
            head=head->next;
        }

        prev->next=first;
        



        return nx;
    }
};