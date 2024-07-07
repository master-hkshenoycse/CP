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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> index_req;
        
        ListNode *prev=NULL;
        int c=0;
        while(head){
            c++;
            int v=head->val;
            if(prev and head->next){
                
                if(v>(prev->val) and v> (head->next->val)){
                    index_req.push_back(c);
                }
                
                if(v<(prev->val) and v < (head->next->val)){
                    index_req.push_back(c);
                }
                
            }
            
            prev=head;
            head=head->next;
        }
                   
                   
        if(index_req.size()<2){
            return {-1,-1};
        }
        int sz=index_req.size();
        vector<int> sol={1000000000,0};       
        for(int i=1;i<sz;i++){
            sol[0]=min(sol[0],index_req[i]-index_req[i-1]);
        }
        sol[1]=index_req[sz-1]-index_req[0];
        return sol;
                   
                   
    }
};