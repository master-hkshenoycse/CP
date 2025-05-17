#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_sod(int n){
            int s=0;
            while(n){
                s=s+(n%10);
                n/=10;
            }
            return s;
        }
        int countLargestGroup(int n) {
            map<int,int> help;
            int ans=0;
            for(int i=1;i<=n;i++){
                help[get_sod(i)]++;
                ans=max(ans,help[get_sod(i)]);
            }
            
            int sol=0;
            for(auto it:help){
                if(it.second==ans){
                    sol++;
                }
            }
            return sol;
        }
    };