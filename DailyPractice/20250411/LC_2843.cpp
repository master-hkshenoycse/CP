#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans=0;
            for(int i=low;i<=high;i++){
                int j=i;
                vector<int> d;
                while(j>0){
                    d.push_back(j%10);
                    j/=10;
                }
                if(d.size()%2==0){
                    int sz=d.size();
                    int s=0;
                    
                    for(int i=0;i<sz;i++){
                        if(i<sz/2)s+=d[i];
                        else s-=d[i];
                    }
                    
                    if(s==0){
                        //cout<<i<<endl;
                        ans++;
                    }
                }
            }
            
            return ans;
        }
    };