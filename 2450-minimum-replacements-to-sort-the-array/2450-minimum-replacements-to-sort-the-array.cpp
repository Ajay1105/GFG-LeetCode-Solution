class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        long long upper_bound = nums.back();

        for(auto it = nums.rbegin()+1; it != nums.rend(); it++){
            long long num = *it;
            long long no_of_times = (num + upper_bound -1)/upper_bound;
            ans += no_of_times-1;
            upper_bound = num/no_of_times;
        }

        return ans;
    }
};