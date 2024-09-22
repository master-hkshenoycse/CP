
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    
    Node *copyList(Node *head) {
        // Write your code here
        
        Node *clone_head=NULL;
        Node *curr=head;
        
        while(curr){
            Node *nx=curr->next;
            
            curr->next=new Node(curr->data);//new node for each
            curr->next->random=curr->random;
            curr->next->next=nx;
            
            
            if(clone_head==NULL){
                clone_head=curr->next;
            }    
            
            curr=nx;
        }
        

        curr=clone_head;
        while(curr){
            
            if(curr->random){
                curr->random=curr->random->next;
            }
            
            if(curr->next){
                curr=curr->next->next;
            }else{
                break;
            }
        }
        
        curr=head;
        
        while(curr){
            
            Node *nx=curr->next;
            
            nx->next=nx->next->next;
            curr->next=nx->next;
            
            
            
            curr=curr->next->next;
        }
        
        
        
        return clone_head;
        
        
        
        
        
    }
};