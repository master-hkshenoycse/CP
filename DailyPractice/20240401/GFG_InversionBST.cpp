#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
class Solution {
  public:
    void rec(Node *root,vector<int> &inorder){
        if(root){
            rec(root->left,inorder);
            inorder.push_back(root->data);
            rec(root->right,inorder);
        }
    }
    void merge(vector<int> &v,int low,int mid,int high,int &ans){
        vector<int> tmp(high-low+1);
        int i=low,j=mid+1,k=0;
        
        while(i<=mid and j<=high){
            if(v[i]<=v[j]){
                tmp[k++]=v[i++];
            }else{
                tmp[k++]=v[j++];
                ans+=(mid-i+1);
            }
        }
        
        while(i<=mid){
            tmp[k++]=v[i++];
        }
        
        while(j<=high){
            tmp[k++]=v[j++];
        }
        
        for(int i=low;i<=high;i++){
            v[i]=tmp[i-low];
        }
        
    }
    void mergeSort(vector<int> &inorder,int low,int high,int &ans){
        if(high>low){
            int mid=(high+low)/2;
            mergeSort(inorder,low,mid,ans);
            mergeSort(inorder,mid+1,high,ans);
            merge(inorder,low,mid,high,ans);
        }
    }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> inorder;
        rec(root,inorder);
        
        
        int ans=0;
        mergeSort(inorder,0,n-1,ans);
        
        
        return ans;
    }
};