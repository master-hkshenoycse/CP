#include <bits/stdc++.h>
using namespace std;

bool check_prime(int v){
    for(int i=2;i*i<=v;i++){
        if(v%i==0){
            return 0;
        }
    }
    return 1;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    
    
    while(t--){
        int n;
        cin>>n;
        
        int e;
        map<int,vector<int> > help;
        for(int i=0;i<n;i++){
            cin>>e;
            help[e].push_back(i);
        }
        
        vector<int> sol={-1,-1};
        for(auto it:help){
            if(it.second.size()>1 and it.first>1){
                sol[0]=it.second[0];
                sol[1]=it.second[1];
                break;
            }
        }
        
        if(sol[0]==-1){
            for(auto it:help){
                for(auto it2:help){
                    if(it.first == it2.first){
                        continue;
                    }
                    if(check_prime(it.first+it2.first)==0){
                        sol[0]=it.second[0];
                        sol[1]=it2.second[0];
                        break;
                    }
                }
                
                if(sol[0] != -1){
                    break;
                }
            }
        }
        
        if(sol[0]==-1){
            cout<<-1<<endl;
        }else{
            cout<<sol[0]+1<<" "<<sol[1]+1<<endl;
        }
        
    }
}
