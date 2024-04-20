#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> sol;
        int i=0,j=0;
        while(i<n and j<m){
            
            if(arr1[i]<arr2[j]){
                sol.push_back(arr1[i]);
                
                int k=i+1;
                while(k<n and arr1[k]==arr1[i]){
                    k++;
                }
                
                i=k;
                
            }else if(arr1[i]>arr2[j]){
                sol.push_back(arr2[j]);
                
                int k=j+1;
                while(k<m and arr2[k]==arr2[j]){
                    k++;
                }
                
                j=k;
            }else{
                sol.push_back(arr1[i]);
                
                int k=i+1;
                while(k<n and arr1[k]==arr1[i]){
                    k++;
                }
                
                i=k;
                
                
                k=j+1;
                while(k<m and arr2[k]==arr2[j]){
                    k++;
                }
                
                j=k;
                
            }
        }
        
        
        while(i<n){
            if(i==0 or arr1[i]!=arr1[i-1]){
                sol.push_back(arr1[i]);
            }
            i++;
        }
        
        while(j<m){

            if(j==0 or arr2[j]!=arr2[j-1]){
                sol.push_back(arr2[j]);
            }
            j++;
        }
        
        return sol;
    }
};