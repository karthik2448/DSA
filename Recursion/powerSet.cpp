#include   <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void subset(int ind,vector<vector<int>>& ans,vector<int>& nums,vector<int>& t){
        if(ind==nums.size()){
            ans.push_back(t);
            return;
        }
        t.push_back(nums[ind]);
        subset(ind+1,ans,nums,t);
        t.pop_back();
        subset(ind+1,ans,nums,t);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> t;
        subset(0,ans,nums,t);

        return ans;
    }
};