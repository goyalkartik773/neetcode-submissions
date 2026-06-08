class Solution {
public:
    int bs(vector<int>& nums,int low,int high,int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid] < target)
            low = mid + 1;
            else
            high = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pkIdx = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high])
            low = mid + 1;
            else
            high = mid;
        }
        pkIdx = high - 1;
        cout<<pkIdx<<endl;
        int ans = bs(nums,0,pkIdx,target);
        if(ans!=-1) return ans;
        else
        ans = bs(nums,pkIdx+1,nums.size()-1,target);
        return ans;
    }
};
