#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

Node *reverse(Node *head){
    if(head==NULL){
        return head;
    }
    
    Node *prev=NULL,*nx=NULL;
    while(head){
        nx=head->next;
        head->next=prev;
        prev=head;
        head=nx;
    }
    
    return prev;
}
void sort(Node **head)
{
        // Code here
        Node *asc_curr=NULL,*dsc_curr=NULL,*asc_head=NULL,*dsc_head=NULL;
        Node *curr=*head;
        int p=0;
        
        
        while(curr){
            
            if(p==0){
                
                if(asc_curr==NULL){
                    asc_head=curr;
                    asc_curr=curr;
                }else{
                    asc_curr->next=curr;
                    asc_curr=asc_curr->next;
                    
                }
                
                //asc_curr->next=NULL;
                
            }else{
                
                if(dsc_curr==NULL){
                    dsc_head=curr;
                    dsc_curr=curr;
                }else{
                    dsc_curr->next=curr;
                    dsc_curr=dsc_curr->next;
                    
                }
                
            // dsc_curr->next=NULL;
                
            }
            
            p=1-p;
            curr=curr->next;
        }
        
        dsc_curr->next=NULL;
        dsc_head=reverse(dsc_head);
        asc_curr->next=dsc_head;
        
        
        //*head=asc_head;
}