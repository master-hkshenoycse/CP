#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node){
       // Your code here
        
       Node *prev=NULL;
       Node *nx=NULL;
       
       while(del_node){
          nx=del_node->next;
          if(nx){
              del_node->data=nx->data;
          }else{
              prev->next=NULL;
          }
          
          prev=del_node;
          del_node=del_node->next;
       }
       
       //prev=NULL;
    }
    

};