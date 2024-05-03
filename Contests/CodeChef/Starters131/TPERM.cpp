#include <bits/stdc++.h>
using namespace std;

//ensure (pi+i)%3=2
void rec(vector<int> &sol,int n){
    if(n==3){
        sol[0]=1;
        sol[1]=3;
        sol[2]=2;
        return;
    }
    
    if(n==4){
        sol[0]=1;
        sol[1]=3;
        sol[2]=2;
        sol[3]=4;
        return;
        
    }
    
    if(n==5){
        sol[0]=5;
        sol[1]=3;
        sol[2]=2;
        sol[3]=4;
        sol[4]=1;
        
        return;
    }
    
    vector<int> candidates={n-2,n-1,n};
    vector<int> indexes={n-1,n-2,n-3};
    
    
    do{ 
        int f=1;
        for(int i=0;i<3;i++){
            if((indexes[i]+candidates[i]+1)%3 != 2){
                f=0;
                break;
            }
        }
        
        if(f){
            for(int i=0;i<3;i++){
                sol[indexes[i]]=candidates[i];
            }
            
            break;
        }
        
        
    }while(next_permutation(candidates.begin(),candidates.end()));
    
    
    rec(sol,n-3);
    
    
    
    
    
}
int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int> sol(n);
	    rec(sol,n);
	    
        
        for(int i=0;i<n;i++){
            cout<<sol[i]<<" ";
        }
        cout<<endl;
	    
	}
	

}
