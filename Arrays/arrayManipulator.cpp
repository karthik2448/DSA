#include <bits/stdc++.h>
using namespace std;
class ArrayManipulator{
public:
  vector<int> rearrangeArrayBySign(vector<int> arr){
      int n=arr.size();
      vector<int> ans(n);

      int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
        else{
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    return ans;
  }
};

int main(){

    vector<int> arr={1, 2, -4, -5};
     ArrayManipulator obj;
    vector<int> ans=obj.rearrangeArrayBySign(arr);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}
