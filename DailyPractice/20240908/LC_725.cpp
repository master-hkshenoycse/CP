
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
    int get_len(ListNode *head){
        if(head==NULL){
            return 0;
        }
        return 1+get_len(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l=get_len(head);
        int rem=l%k;
        vector<ListNode*> sol(k);

        ListNode *curr=head,*nx=NULL;
        
        for(int i=0;i<k;i++){
            int req=l/k;
            
            if(i<rem){
                req++;
            }

            sol[i]=curr;
            while(curr){
                nx=curr->next;
                req--;

                if(req==0){
                    break;
                }

                curr=curr->next;
                
            }
            
            if(curr)curr->next=NULL;
            curr=nx;

        }


        return sol;
    }
};