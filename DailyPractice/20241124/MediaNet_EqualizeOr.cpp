#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A){
    int n=A.size();
    map<int,int> help;
    help[0]=0;

    int req=0;
    for(auto e:A){
        req=(req | e);
        map<int,int> tmp;
        for(auto it:help){
            int val=(it.first | e);
            int steps=(it.second+1);
            if(tmp.find(val) == tmp.end()){
                tmp[val]=steps;
            }else{
                tmp[val]=max(tmp[val],steps);
            }
        }

        for(auto it:tmp){
            int val=it.first;
            int steps=it.second;

            if(help.find(val) == help.end()){
                help[val] = steps; 
            }else{
                help[val]=min(help[val],steps);
            }
        }
    }

    int cnt=0;
    for(auto e:A){
        cnt+=(e==req);
    }

    if(cnt==n){
        return 0;
    }

    return help[req];
    

}
int main(){
    vector<int> A;
    A={0,4,3};
    cout<<solve(A)<<endl;

    A={10};
    cout<<solve(A)<<endl;
}