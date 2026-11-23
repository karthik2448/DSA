#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     void combination(int i,int target,vector<int>& temp,vector<int>& nums,vector<vector<int>>& ans,int k){
        if(temp.size()==k || i==nums.size()){
            if(target==0 && temp.size()==k){
                ans.push_back(temp);
                
            }
            return;
        }
       
        temp.push_back(nums[i]);
        combination(i+1,target-nums[i],temp,nums,ans,k);
        temp.pop_back();
        combination(i+1,target,temp,nums,ans,k);
        return;

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        combination(0,n,temp,nums,ans,k);
        return ans;
    }
};