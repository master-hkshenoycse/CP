#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        unordered_set<int> is_present;
        while(head1){
            is_present.insert(head1->data);
            head1=head1->next;
        }
        
        int ans=0;
        while(head2){
            if(is_present.find(x-head2->data) != is_present.end()){
                ans++;
            }
            head2=head2->next;
        }
        return ans;
    }
};