#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> A,int K){
    int n=A.size();
    int lo=0,hi=2e6;
    map<int,int> help;
    for(auto e:A){
        help[e]=1;
    }
    int ans=0;

    while(hi>=lo){
        int mid=(hi+lo)/2;

        int used=0,req=0;
        for(int i=0;i<=mid;i++){
            if(help.find(i) != help.end()){
                used++;
            }else{
                req++;
            }
        }

        if(n-used>=req && req<=K){
            ans=max(ans,mid+1);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
        
    }

    return ans;
}
int main(){
    cout<<solve({1,2,3,4,2},2)<<endl;
}