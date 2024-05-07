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
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        //recursive call to reverse 
        ListNode *newHead=reverse(head->next);


        //reference to the next
        ListNode *front=head->next;


        front->next=head;

        //to remove cyclic dependency
        head->next=NULL;

        return newHead;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode *sol=NULL,*sol_head=NULL;
        int c=0;
        while(head){
            int v1=head->val;
            //cout<<v1<<endl;
            int v=(v1*2+c)%10;
            c=(v1*2+c)/10;

            if(sol){
                sol->next=new ListNode(v);
                sol=sol->next;
            }else{
                sol_head=new ListNode(v);
                sol=sol_head;
            }

            head=head->next;

        }

        if(c){
            sol->next=new ListNode(c);
        }

        sol_head=reverse(sol_head);
        return sol_head;
    }
};