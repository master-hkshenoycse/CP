#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
class SegTree{
    int n;
    vector<T> tree;

    T Segtree(int n){
        tree.resize(2*n,0);
    }

    void update(int index,T value){
        //update values at index p in array;
        index+=n;
        while(index>1){
            tree[index>>1]=tree[index]+tree[index^1];
            index>>=1;
        }
    }


    T query(int l,int r){
        l+=n;
        r+=n;

        T res=0;

        while(l<r){
            if(l&1){
                res+=tree[l];
                l++;
            }

            if(r&1){
                r--;
                res+=tree[r];
            }

            l>>=1;
            r>>=1;
        }

        return res;
    }

    


};

int main(){
    int n;
    cin>>n;

    SegTree<long long> SegTree(n);


    for(int i=0;i<n;i++){
        tree[n+i]=1;
    }

    build(n);



    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            cout<<i<<" "<<j<<endl;
            query(i,j+1,n);
        }
    }

}