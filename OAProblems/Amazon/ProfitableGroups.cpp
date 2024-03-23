/*https://leetcode.com/discuss/interview-question/4778515/Amazon-OA-question*/

/*A team of analysts at Amazon needs to analyze the stock prices of Amazon over a period of several months.

A group of consecutively chosen months is said to be maximum profitable if the price in its first or last month is the maximum for the group. More formally, a group of consecutive months [l, r] (1 ≤ l ≤ r ≤ n) is said to be maximum profitable if either:

stockPrice[l] = max(stockPrice[l], stockPrice[l + 1], ..., stockPrice[r])
or, stockPrice[r] = max(stockPrice[l], stockPrice[l + 1], ..., stockPrice[r])
Given prices over n consecutive months, find the number of maximum profitable groups which can be formed. Note that the months chosen must be consecutive, i.e., you must choose a subarray of the given array.

Function Description

Complete the function countMaximumProfitableGroups function in the editor below.

countMaximumProfitableGroups has the following parameter:

int stockPrice[n]: the stock prices
Returns

long integer: the number of maximum profitable groups

Example 1:

Input: stockPrice = [3, 1, 3, 5]
Output: 10
Explanation:

The 10 possible groups are [3], [3, 1], [1, 3], [1], [3, 1, 3], [1, 3, 5], [1], [3, 1, 3, 5], [3, 5], [5].
In each group, the maximum price is in either the first or last position.

Example 2:

Input: stockPrice = [1, 5, 2]
Output: 5
Explanation:

There are 6 possible groups: [1], [1, 5], [5], [5, 2], [2].
Only [1, 5, 2], is not maximum profitable because its maximum value 5 is not at either end of the group.
*/
#include<bits/stdc++.h>
#define ll long
using namespace std;
int countMaximumProfitableGroups(vector<int> stockPrice){
    ll n=stockPrice.size();
    ll ans=0;


    stack<ll> st;
    for(ll i=0;i<n;i++){
        while(st.size()>0 and stockPrice[i]>=a[st.top()]){
            st.pop();
        }

        if(st.size()>0){
            ans=ans+(i-st.top());
        }else{
            ans=ans+(i+1);
        }
    }



    return ans;

    
}
int main(){

}