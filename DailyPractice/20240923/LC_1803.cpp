#include<bits/stdc++.h>
using namespace std;
struct trie_node{
    int cnt;
    trie_node *child[2];

    trie_node(){
        child[0]=NULL;
        child[1]=NULL;
        cnt=0;
    }

};
class Solution {
public:
    void insert(trie_node *root,int num){
        for(int i=20;i>=0;i--){
            int ch=0;

            if(num & (1<<i)){
                ch=1;
            }

            root->cnt++;

            if(root->child[ch]==NULL){
                root->child[ch]=new trie_node();
            }

            root=root->child[ch];
        }

        root->cnt++;
    }
    //cnt less than equal to
    int query(trie_node *root,int value,int limit,int po,int ti){
        

        if(root==NULL){
            return 0;
        }

        if(po<0){
            return root->cnt;
        }

        if(ti==0){
            return root->cnt;
        }

        int values_set=0;
        int limit_set=0;

        if(value & (1<<po)){
            values_set=1;
        }
        if(limit  & (1<<po)){
            limit_set=1;
        }

        int ret=0;
    

        if(limit_set){
            ret=ret+query(root->child[values_set],value,limit,po-1,0);
            ret=ret+query(root->child[1-values_set],value,limit,po-1,1);
        }else{
            ret=ret+query(root->child[values_set],value,limit,po-1,1);
        }



        return ret;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        trie_node *root=new trie_node();
        int ans=0;

        for(auto e:nums){
            ans=ans+query(root,e,high,20,1)-query(root,e,low-1,20,1);
            //cout<<e<<" "<<ans<<endl;
            insert(root,e);
        }

        return ans;
        
    }
};