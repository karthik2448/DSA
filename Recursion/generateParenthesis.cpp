#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int open,int close,string& s,vector<string>& ans,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            generate(open+1,close,s,ans,n);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            generate(open,close+1,s,ans,n);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string s="";
        generate(0,0,s,ans,n);
        return ans;
    }
};