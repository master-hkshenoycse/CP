#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_string(vector<int> &cnt){
        string ret;
        for(int i=0;i<26;i++){
            ret+=to_string(cnt[i]);
            if(i<25){
                ret+='$';
            }
        }

        return ret;

    }
    bool isPossibleToRearrange(string s, string t, int k) {
        int n=s.size();
        map<string,int> help;
        int chunk=n/k;

        for(int i=0;i<n;i+=chunk){
            help[s.substr(i,chunk)]++;
            help[t.substr(i,chunk)]--;
        }

        for(auto it:help){

            if(it.second != 0){
                return 0;
            }
        }

        return 1;
    }
};