class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        auto check = [&](int val)->int{
            int a = upper_bound(nums1.begin(),nums1.end(),val)-nums1.begin();
            int b = upper_bound(nums2.begin(),nums2.end(),val)-nums2.begin();
            return a + b;
        };
        auto bs = [&](int k)->int{
            int low = INT_MAX;
            int high = INT_MIN;
            if(!nums1.empty()){
                low = min(nums1[0],low);
                high = max(nums1[nums1.size()-1],high);
            }
            if(!nums2.empty()){
                low  = min(low,nums2[0]);
                high = max(high,nums2[nums2.size()-1]);
            }
            int result = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(check(mid)>k){
                    result = mid;
                    high = mid - 1;
                }
                else
                low = mid + 1;
            }
            return result;
        };
        if(n%2!=0){
            return bs(n/2);
        }
        else{
            double x = bs(n/2);
            double y = bs(n/2-1);
            return (x+y)/2.0;
        }
    }
};