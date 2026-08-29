#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool is_alpha(char ch){
        return ch>='a' && ch<='z';
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string chunks_concat;
        for(auto s:chunks)
            chunks_concat+=s;
        
        map<string,int> str_freq;
        int n=chunks_concat.size();
        string curr;
        for(int i=0;i<n;i++){
            if(is_alpha(chunks_concat[i]))
                curr+=chunks_concat[i];
            else if(chunks_concat[i]=='-' && i-1>=0 && is_alpha(chunks_concat[i-1]) && i+1<n && is_alpha(chunks_concat[i+1])){
                    curr+='-';
            }else{

                if(curr.size()>0)
                    str_freq[curr]++;
                
                curr.clear();
            }
        }

        if(curr.size()>0)
            str_freq[curr]++;
        vector<int> ret;

        for(auto q:queries)
            ret.push_back(str_freq[q]);

        return ret;
    }
};