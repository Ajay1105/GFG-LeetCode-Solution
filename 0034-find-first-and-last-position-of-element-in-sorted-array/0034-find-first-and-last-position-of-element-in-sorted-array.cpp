class Solution {
public:
    int first_search(vector<int>& nums, int target){
        int first_position = -1;
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
           int mid = low + (high - low)/2;
            if(nums[mid] == target){
                first_position = mid;
                high = mid-1;
            }else if(nums[mid] > target){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return first_position;
    }
    int last_search(vector<int>& nums, int target){
        int last_position = -1;
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
           int mid = low + (high - low)/2;
            if(nums[mid] == target){
                last_position = mid;
                low = mid+1;
            }else if(nums[mid] > target){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return last_position;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(first_search(nums, target));
        result.push_back(last_search(nums, target));
        return result;
    }
};