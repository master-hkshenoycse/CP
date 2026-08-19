#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(int l,int r,vector<int> &arr,int target){
        unordered_map<int,int> mp;
        mp[0]=l-1;
        int sum=0,ans=0;
        for(int i=l;i<=r;i++){
            sum+=arr[i];
            if(mp.find(sum-target) != mp.end())
                ans=max(ans,i-mp[sum-target]);
            
            if(mp.find(sum) == mp.end())
                mp[sum]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n=s.size();
        vector<int> arr(n,0);

        for(int i=0;i<n;i++){
            if(s[i]=='1')arr[i]=1;
            else arr[i]=-1;
        }
        int firstOne=-1,lastOne=-1,firstZero=-1,lastZero=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(firstZero==-1)firstZero=i;
                lastZero=i;
            }else{
                if(firstOne==-1)firstOne=i;
                lastOne=i;
            }
        }

        if(firstOne==-1 || firstZero==-1)
            return 0;

        int ans=0;
        ans=max(ans,fun(0,n-1,arr,0));
        ans=max(ans,fun(firstOne+1,n-1,arr,-2));
        ans=max(ans,fun(0,lastOne-1,arr,-2));
        ans=max(ans,fun(firstZero+1,n-1,arr,2));
        ans=max(ans,fun(0,lastZero-1,arr,2));
        return ans;   
    }
};