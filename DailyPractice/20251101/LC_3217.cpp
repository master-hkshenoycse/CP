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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *sol_head=NULL,*prev=NULL;
        set<int> nums_in_list;
        for(auto e:nums){
            nums_in_list.insert(e);
        }

        while(head){
            if(nums_in_list.find(head->val)==nums_in_list.end()){
                if(prev==NULL){
                    sol_head=head;
                    prev=head;
                }else{
                    prev->next=head;
                    prev=prev->next;
                }

            }

            head=head->next;
        }
        if(prev){
            prev->next=NULL;
        }
        return sol_head;
    }
};