class Solution {
public:

    void util(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i){
        ans.push_back(temp);

        for(int j=i; j<nums.size(); j++){
            if(j!=i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            util(ans,temp, nums, j+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;
       sort(nums.begin(), nums.end());
       util(ans,temp,nums,0);
       return ans; 
    }
};