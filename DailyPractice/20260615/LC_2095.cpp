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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode *sl_p_prev=NULL,*sl_p=head,*fa_p=head;
        
        
        if(head->next==NULL){
            return NULL;
        }
        
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        
        
        while(fa_p){
            fa_p=fa_p->next;
            
            
            
            if(fa_p){
                fa_p=fa_p->next;
                sl_p_prev=sl_p;
                sl_p=sl_p->next;
            }
            
        }
        
        
        sl_p_prev->next=sl_p->next;
        sl_p->next=NULL;
        cout<<(sl_p->val)<<" "<<(sl_p_prev->val)<<endl;
        
        return head;
        
        
        
        
    }
};