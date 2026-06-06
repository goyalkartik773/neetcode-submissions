class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int potRow = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target)
            return true;
            else if(matrix[mid][0] < target)
            low = mid + 1;
            else
            high = mid - 1;
        }
        if(low==0) return false;
        potRow = low - 1;
        low = 0;
        high = matrix[0].size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(matrix[potRow][mid]==target) 
            return true;
            else if(matrix[potRow][mid]<target)
            low = mid + 1;
            else
            high = mid - 1;
        }
        return false;
    }
};
