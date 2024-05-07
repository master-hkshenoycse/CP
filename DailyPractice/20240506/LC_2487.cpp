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
    ListNode *get_reverse(ListNode *head){
        ListNode *prev=NULL,*nx=NULL;
        while(head){
            nx=head->next;
            head->next=prev;
            prev=head;
            head=nx;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=get_reverse(head);
        ListNode *sol=NULL,*sol_head=NULL;

        int max_so_far=-1;
        
        while(head){
            if(head->val >= max_so_far){
                if(sol){
                    sol->next=head;
                    sol=sol->next;
                }else{
                    sol_head=head;
                    sol=head;
                }

                max_so_far=head->val;
            }
            head=head->next;
        }

        sol->next=NULL;
        sol_head=get_reverse(sol_head);
        return sol_head;
    }
};