#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLCP(string &fi,string &se){
        int i=0;
        while(i<fi.size() && i<se.size()){
            if(fi[i] != se[i]){
                return i;
            }
            i++;
        }

        return i;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int> lcp_prefix(n,0),lcp_suffix(n,0);

        for(int i=1;i<n;i++){
            lcp_prefix[i]=getLCP(words[i-1],words[i]);
            lcp_prefix[i]=max(lcp_prefix[i],lcp_prefix[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            lcp_suffix[i]=getLCP(words[i],words[i+1]);
            lcp_suffix[i]=max(lcp_suffix[i],lcp_suffix[i+1]);
        }

        vector<int> sol(n,0);
        
        for(int i=0;i<n;i++){
            if(i-1>=0){
                sol[i]=max(sol[i],lcp_prefix[i-1]);
            }

            if(i+1<n){
                sol[i]=max(sol[i],lcp_suffix[i+1]);
            }

            if(i-1>=0  && i+1<n){
                sol[i]=max(sol[i],getLCP(words[i-1],words[i+1]));
            }
        }

        return sol;
    }
};