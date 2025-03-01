#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size();
    
            set<int> s;
            for(auto e:arr){
                s.insert(e);
            }    
    
    
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int x=arr[j],y=arr[i]+arr[j];
                    int len=2;
    
                    while(s.find(y) != s.end()){
                        int tmp=y;
                        y+=x;
                        x=tmp;
                        ans=max(ans,++len);
                    }
    
                    
                }
            }
    
            return ans>=3?ans:0;
        }
    };