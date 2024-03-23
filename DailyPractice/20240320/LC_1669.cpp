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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev_a=NULL,*curr_b=NULL;
        ListNode *head=list1;
        b++;
        while(a-- and b--){
            prev_a=list1;
            curr_b=list1;
            list1=list1->next;
        
        }

        while(b--){
            curr_b=list1;
            list1=list1->next;
        }

        if(prev_a==NULL){
            head=list2;
        }else{
            prev_a->next=list2;
        }

        while(list2->next != NULL){
            list2=list2->next;
        }
        list2->next=curr_b->next;




        return head;
    }
};