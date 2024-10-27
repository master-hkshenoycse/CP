#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


int sumOfLastN_Nodes(struct Node* head, int n) {
    // Code here
    Node *removed=head,*ptr=head;
    int sum=0;
    while(ptr){
        if(n==0){
            sum-=removed->data;
            removed=removed->next;
        }
        
        sum+=ptr->data;
        ptr=ptr->next;
        
        if(n>0){
            n--;
        }
    }
    
    return sum;
    
}