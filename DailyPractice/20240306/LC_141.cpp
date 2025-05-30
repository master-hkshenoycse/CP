#include<bits/stdc++.h>
using namespace std;

/* slow and fast pointer approach*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return 0;
        }
        ListNode *slow=head,*fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return 1;
            }
        }

        return 0;
    }
};