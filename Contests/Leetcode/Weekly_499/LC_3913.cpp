#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        map<char,int> cnt,first_pos;
        int n=s.size();
        vector<int> vowel_index;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowel_index.push_back(i);
                cnt[s[i]]++;
                first_pos[s[i]]=i;
            }
        }

        vector<int> og=vowel_index;
        sort(vowel_index.begin(),vowel_index.end(),[&](int a,int b){
            
            if(cnt[s[a]] != cnt[s[b]])
                return cnt[s[a]]>cnt[s[b]];
            
            if(first_pos[s[a]] != first_pos[s[b]])
                return first_pos[s[a]] < first_pos[s[b]];

            return a<b;
        });
            
        reverse(og.begin(),og.end());
        string ret=s;
        for(int i=0;i<og.size();i++)
            ret[og[i]]=s[vowel_index[i]];
        

        return ret;
        
    }
};