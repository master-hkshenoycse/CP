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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode *prev=NULL,*sol=NULL;

        while(head){
            if(head->val==0){
                if(sum>0){
                    if(prev){
                        prev->next=new ListNode(sum);
                        prev=prev->next;
                    }else{
                        sol=new ListNode(sum);
                        prev=sol;
                    }
                    sum=0;
                }
            }else{
                sum=sum+head->val;
            }
            head=head->next;
        }

        return sol;
    }
};