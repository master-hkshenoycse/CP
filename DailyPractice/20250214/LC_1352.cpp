#include<bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    public:
        int prod=1;
        vector<int> v;
        ProductOfNumbers() {
            v.clear();
            prod=1;
        }
        
        void add(int num) {
            v.push_back(num);
        }
        
        int getProduct(int k) {
            int ret=1;
            int sz=v.size();
            for(int i=sz-1;i>=sz-k;i--){
                ret=ret*v[i];
            }
            return ret;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */