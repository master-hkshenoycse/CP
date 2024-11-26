#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *child[26];
    Node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
void insert(Node *root,string &s){
    for(auto ch:s){
        if(root->child[ch-'a']==NULL){
            root->child[ch-'a']=new Node();
        }
        root=root->child[ch-'a'];
    }
}
int solve_dp(int ind,string &B,vector<int> &dp,Node *root){
    if(ind==B.size()){
        return 0;
    }

    if(dp[ind] != -1){
        return dp[ind];
    }

    int res=1e9;

    Node *tmp=root;

    for(int i=ind;i<B.size();i++){
        if(tmp->child[B[i]-'a']){
            tmp=tmp->child[B[i]-'a'];
            res=min(res,1+solve_dp(i+1,B,dp,root));
        }else{
            break;
        }
    }

    return dp[ind]=res;
}

int solve(vector<string> &A,string B){
    Node *root=new Node();
    for(auto s:A){
        insert(root,s);
    }

    int n=B.size();
    vector<int> dp(n,-1);
    int res=solve_dp(0,B,dp,root);
    if(res>=1e9){
        res=-1;
    }

    return res;
}
int main(){
    vector<string> A;
    string B;

    A={"abc","bcb","ka","efgh"};
    B="efkabc";

    cout<<solve(A,B)<<endl;

    A={"abcd","cbdc"};
    B="abcbabd";

    cout<<solve(A,B)<<endl;

}