#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void complete_string(string &w1,string &w2,int st,int c,int ex,vector<int> &sol){
        

        for(int i=st;i<w1.size();i++){
            if(sol.size()==w2.size()){
                return;
            }


            if(w2[c]==w1[i]){
                sol.push_back(i);
                c++;
            }else if(ex>0){
                ex--;
                sol.push_back(i);
                c++;
            }

            
        }
    }
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();

        vector<int> suff_match(n+1,m);
        int p=m-1;
        for(int i=n-1;i>=0;i--){
            if(p>=0 and word2[p]==word1[i]){
                suff_match[i]=p;
                p--;
            }else{
                if(i+1<n){
                    suff_match[i]=suff_match[i+1];
                }
            }
        }


        vector<int> sol;
        int curr=0;
        for(int i=0;i<n;i++){
            if(suff_match[i+1]<=curr+1){

                sol.push_back(i);
                int ex=0;
                if(word1[i]==word2[curr]){
                    ex=1;
                }
                complete_string(word1,word2,i+1,curr+1,ex,sol);

                return sol;


            }else{
                if(word1[i]==word2[curr]){
                    sol.push_back(i);
                    curr++;
                }
            }

            if(sol.size()==m){
                return sol;
            }
        }

        if(sol.size() != m){
            sol.clear();
        }

        return sol;

        
    }
};