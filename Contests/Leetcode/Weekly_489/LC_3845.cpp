#include<bits/stdc++.h>
using namespace std;
class BinaryTrie {
private:
    struct Node {
        Node* child[2];
        int cnt;        // Number of values passing through this node

        Node() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Node* root;
    static const int MAX_BIT = 31;   // Use 31 for int, 63 for long long

public:
    BinaryTrie() {
        root = new Node();
    }

    // Insert a number
    void insert(int num) {
        Node* cur = root;

        for(int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if(cur->child[b] == nullptr)
                cur->child[b] = new Node();

            cur = cur->child[b];
            cur->cnt++;
        }
    }

    // Remove one occurrence
    void erase(int num) {
        Node* cur = root;
        for(int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            cur = cur->child[b];
            cur->cnt--;
        }
    }

    // Maximum XOR with num
    int maxXor(int num) {
        Node* cur = root;
        int ans = 0;

        for(int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if(cur->child[1 - b] && cur->child[1 - b]->cnt > 0) {
                ans |= (1 << bit);
                cur = cur->child[1 - b];
            }
            else {
                cur = cur->child[b];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        deque<int> nx_min,nx_max;
        vector<int> c_xor(n+1,0);
        int j=1;
       
        BinaryTrie trie;
        
        for(int i=1;i<=n;i++){
            c_xor[i]=nums[i-1];
            c_xor[i] = (c_xor[i] ^ c_xor[i-1]);
            

            while(nx_min.size()>0 && nums[nx_min.back()-1]>=nums[i-1])
                nx_min.pop_back();

            while(nx_max.size()>0 && nums[nx_max.back()-1]<=nums[i-1])
                nx_max.pop_back();
            
            nx_min.push_back(i);
            nx_max.push_back(i);

            while(nums[nx_max.front()-1]-nums[nx_min.front()-1]>k){

                if(j==nx_max.front())
                    nx_max.pop_front();
                
                if(j==nx_min.front())
                    nx_min.pop_front();
                
                trie.erase(c_xor[j-1]);
                j++;
            }

            //cout<<i<<" "<<j<<endl;

            trie.insert(c_xor[i-1]);
            ans=max(ans,trie.maxXor(c_xor[i]));
            

        }
        return ans;
    }
};