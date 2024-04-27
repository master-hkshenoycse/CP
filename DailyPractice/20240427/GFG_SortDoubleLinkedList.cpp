#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};


class Solution {
  public:
  
  
    // Function to sort the given doubly linked list using Merge Sort.
    Node *find_mid(Node *head){
        Node *slow=head,*fast=head->next;
        
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
    }
    Node *merge(Node *a,Node *b){
        
        if(a==NULL){
            return b;
        }
        
        if(b==NULL){
            return a;
        }
        
        if((a->data) < (b->data)){
        
            a->next=merge(a->next,b);
            if(a->next){
                a->next->prev=a;
            }
            a->prev=NULL;
            
            return a;
        }else{
            b->next=merge(a,b->next);
            if(b->next){
                b->next->prev=b;
            }
            b->prev=NULL;
            return b;
        }
        
        
        return NULL;
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        
            
        Node *mid=find_mid(head);
        Node *nxt_mid=mid->next;
        
        mid->next=NULL;
        nxt_mid->prev=NULL;
        
        Node *left=sortDoubly(head);
        Node *right=sortDoubly(nxt_mid);

        return merge(left,right);
        
    }
};