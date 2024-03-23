#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
Challenge 1 description

There is an array A of N integers. What is the largest sum of two numbers which do not have any common digits?

Write a function:

int solution(vector<int> &A);

that, given an array A of length N, returns largest possible sum of two numbers from A which do not have any digits in common. If it is impossible to choose two such numbers, the function should return -1.

Examples:

1. Given A [53, 1, 36, 103, 53, 5], the function should return 108, because we could choose numbers 103 and 5. Other pairs of numbers which do not share any digits, for example 5 and 36, total to a smaller sum.

2. Given A = 19, 19, 99, 291, the function should return -1, as every pair of numbers shares the digit 9.

3. Given A = [6, 17, 71, 66, 17, 61, the function should retum 137. The best pair is 71 and 66.

4. Given A = [15, 0, 1051, the function should retum 15.

Write an efficient algorithm for the following assumptions:

• N is an integer within the range [2..200,000);

⚫ each element of array A is an integer within the range [0..1,000,000,000).
*/
ll get_mask(ll num){

    if(num==0){
        return 1;
    }
    ll ret=0;
    while(num>0){
        ll dig=(num%10);
        ret=(ret | (1ll<<dig));
        num/=10;
    }
    return ret;
}
bool check_mask(ll mask_1,ll mask_2){
    for(ll i=0;i<10;i++){
        ll x=(mask_1 & (1ll<<i));
        ll y=(mask_2 & (1ll<<i));
        if(x>0 and y>0){
            return 0;
        }
    }

    return 1;
}
int solution(vector<int> &A){

    ll lim=(1ll<<10);
    vector<ll> max_val_mask(lim,-1);

    for(auto e:A){
        ll curr_mask=get_mask(e);
        //cout<<e<<" "<<curr_mask<<endl;
        max_val_mask[curr_mask]=max(max_val_mask[curr_mask],e*1ll);
    }


    ll ans=-1;
    for(ll i=0;i<lim;i++){
        for(ll j=i+1;j<lim;j++){
            
            if(max_val_mask[i]!=-1 and max_val_mask[j]!=-1 and check_mask(i,j)){
                ans=max(ans,max_val_mask[i]+max_val_mask[j]);
            }
        }
    }

    return ans;
    
}


int main(){
    vector<int> A;
    A={53,1,36,103,53,5};
    cout<<solution(A)<<endl;

    A={19,19,99,291};
    cout<<solution(A)<<endl;

    A={6,17,71,66,17,61};
    cout<<solution(A)<<endl;

    A={15,0,1051};
    cout<<solution(A)<<endl;
    
}
