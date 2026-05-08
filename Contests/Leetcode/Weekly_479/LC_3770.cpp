#include<bits/stdc++.h>
using namespace std;
vector<int> pri;
int mark[500001];
int is_done=0;
void pre_cum(){
    if(is_done)
        return;
    
    is_done=1;
    
    for(int i=2;i<=500000;i++){
        if(mark[i]==0){
            for(int j=2*i;j<=500000;j+=i)
                mark[j]=1;
        }
    }
    for(int i=2;i<=500000;i++){
        if(mark[i]==0)
            pri.push_back(i);
    }
}
class Solution {
public:
    int largestPrime(int n) {
        pre_cum();
        int ret=0,j=0,s=0;
        while(j<pri.size()){
            s+=pri[j];

            if(s>n){
                break;
            }

            if(mark[s]==0)
                ret=max(ret,s);

            j++;
        }
        

        return ret;
        
    }
};