#include <bits/stdc++.h>
using namespace std;
int smallest_prime_factor[10000001];

void pre_cum(){
    smallest_prime_factor[1]=1;
    for(int i=2;i<=10000000;i++){
        if(smallest_prime_factor[i]==0){
            for(int j=i;j<=10000000;j+=i){
                if(smallest_prime_factor[j]==0){
                    smallest_prime_factor[j]=i;
                }
            }
        }   
    }
        
}
set<int> get_digit_space(int n){
    vector<int> digits;
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    sort(digits.begin(),digits.end());
    set<int> d_space;
    do{
        int value=0;
        if(digits[0]==0){
            continue;
        }
        
        for(auto d:digits){
            value=value*10+d;
        }
        
        while(value>1){
            d_space.insert(smallest_prime_factor[value]);
            int p=smallest_prime_factor[value];
            while(value % p==0){
                value/=p;
            }
        }
        
        
        
    }while(next_permutation(digits.begin(),digits.end()));
    
    return d_space;
}
int main() {
	// your code goes here
	pre_cum();
    int t;
    cin>>t;
    
    
    while(t--){
        
        int x,y;
        cin>>x>>y;
        
        int ans=1;
        
        set<int> d_space_x=get_digit_space(x);
        set<int> d_space_y=get_digit_space(y);
        
        for(auto e:d_space_x){
            if(d_space_y.find(e) != d_space_y.end()){
                ans=max(ans,e);
            }
        }
        
        cout<<ans<<endl;
    }
}
