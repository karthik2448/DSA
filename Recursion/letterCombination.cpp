#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int ind,vector<string>& ans,string &digits,string s,int n,vector<string>& key){
        if(ind==n){
            ans.push_back(s);
            return;
        }

        for(int i=0;i<key[digits[ind]-'0'].size();i++){
            generate(ind+1,ans,digits,s+key[digits[ind]-'0'][i],n,key);
        }

    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> ans;
        vector<string> key={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        generate(0,ans,digits,"",n,key);

        return ans;
    }
};