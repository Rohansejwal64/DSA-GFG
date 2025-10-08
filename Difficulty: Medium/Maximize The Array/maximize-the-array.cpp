// User function template for C++
#include <bits/stdc++.h>
class Solution {
  public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        // code here
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr1[i]);
             temp.push_back(arr2[i]);
            
        }
        sort(temp.begin(),temp.end());
        set<int> s;
        while(s.size()<n){
            s.insert(temp.back());
            temp.pop_back();
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s.find(arr2[i]) !=s.end()){
                ans.push_back(arr2[i]);
                s.erase(arr2[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(s.find(arr1[i]) !=s.end()){
                ans.push_back(arr1[i]);
                s.erase(arr1[i]);
            }
        }
        return ans;
        
    }
};