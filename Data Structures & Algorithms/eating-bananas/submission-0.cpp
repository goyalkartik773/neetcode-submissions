class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        int result = -1;
        auto check = [&](int k)->bool{
            int time=0;
            float x = (float)k;
            for(auto &ele:arr){
                float val = (float)ele;
                time += ceil(val/x);
            }
            return (time<=h)?true:false;
        };
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid)){
                result = mid;
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
        return result;
    }
};
