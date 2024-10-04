#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> vowels={'a','e','i','o','u'};
    int get_valid(vector<vector<int> >&cnt,int st,int en,int k){
        int cnt_vowel=0;
        for(auto ch:vowels){
            if(cnt[ch-'a'][en]-cnt[ch-'a'][st-1]==0){
                return 0;
            }
            cnt_vowel+=cnt[ch-'a'][en]-cnt[ch-'a'][st-1];
        }

        return (en-st+1)-cnt_vowel>=k;
    }   

    int count_k(vector<vector<int> >&cnt,int st,int n,int k){
        int lo=st,hi=n,r=n+1;
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(get_valid(cnt,st,mid,k)){
                r=min(r,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return n-r+1;
    }
    int countOfSubstrings(string word, int k) {
       int n=word.size();
       vector<vector<int> >cnt(26,vector<int>(n+1,0));
       for(int i=1;i<=n;i++){
         for(int j=0;j<26;j++){
            cnt[j][i]+=cnt[j][i-1];
         }
         cnt[word[i-1]-'a'][i]++;
       }

       int ans=0;
       for(int i=1;i<=n;i++){
          ans=ans+count_k(cnt,i,n,k)-count_k(cnt,i,n,k+1);
       }
       return ans;


    }
};