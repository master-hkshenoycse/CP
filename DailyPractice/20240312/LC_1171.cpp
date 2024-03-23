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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> prev_cs;
        prev_cs[0]=NULL;

        ListNode *curr=head,*prev=NULL,*sol=head;
        int s=0;
        stack<int> st;
        st.push(0);

        while(curr){
            s=s+curr->val;


            if(prev_cs.find(s)==prev_cs.end()){
                prev_cs[s]=curr;
                prev=curr;
                st.push(s);

            }else{

                //cout<<s<<" "<<(curr->val)<<endl;

                if(prev_cs[s]==NULL){
                    sol=curr->next;
                }else{
                    prev_cs[s]->next=curr->next;
                }

                while(st.size()>0 and st.top()!=s){
                    prev_cs.erase(st.top());
                    st.pop();
                }

                prev=prev_cs[s];
                //if(prev_cs[s] != NULL)prev_cs.erase(s);

            }

            curr=curr->next;
            
        }

        if(sol and sol->val==NULL){
            sol=sol->next;
        }

        return sol;
        
    }
};