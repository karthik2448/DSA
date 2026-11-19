#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
       int n=s.length();
       int res=0;
       for(int i=0;i<n;i++){
             vector<int> freq(26,0);
       int mi=INT_MAX,ma=0;
             for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                 int mi = INT_MAX, ma = 0;
            for (int f : freq) {
                if (f > 0) {
                    mi = min(mi, f);
                    ma = max(ma, f);
                }
            }
                res+=(ma-mi);
             }
       } 
       return res;
    }
};