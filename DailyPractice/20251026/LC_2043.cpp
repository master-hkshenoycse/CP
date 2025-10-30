#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Bank {
public:
    ll n,bal[200005];
    
    Bank(vector<long long>& balance) {
        n=balance.size();
        for(int i=1;i<=n;i++){
            bal[i]=balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(account1>n or account2>n) return 0;
        if(bal[account1]>=money){
            bal[account1]-=money;
            bal[account2]+=money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        
        if(account>n)return 0;
        bal[account]+=money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if(account>n)return 0;
        if(bal[account]>=money){
            bal[account]-=money;
            return 1;
        }
        return 0;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */