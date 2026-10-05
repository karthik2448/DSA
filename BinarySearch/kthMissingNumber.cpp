class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mis=0;
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            mis=arr[mid]-(mid+1);
            if(mis<k){
            low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high+1+k;
    }
};