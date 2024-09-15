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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr=head,*nx;

        while(curr and curr->next){
            nx=curr->next;
            int ins=__gcd(curr->val,curr->next->val);
            curr->next=new ListNode(ins);
            curr->next->next=nx;
            curr=nx;
        }

        return head;

    }
};