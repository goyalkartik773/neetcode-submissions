class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        long long low = 1;
        long long high = (long long)*max_element(arr.begin(),arr.end());
        long long result = LLONG_MAX;
        auto check = [&](long long k)->bool{
            long long time=0;
            for(auto &ele:arr){
                time += (ele + k - 1) / k;
            }
            return (time<=h)?true:false;
        };
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid)){
                result = min(result,mid);
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
        return result;
    }
};
