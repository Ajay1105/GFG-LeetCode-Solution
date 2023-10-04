class Solution {
public:
    bool find132pattern(vector<int>& nums) {  
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);      
        int k = INT_MIN;
        stack<int> st;
        int n = nums.size();

        for(int i = n-1; i>=0; i--){
            if(st.empty() || nums[i] < st.top()) st.push(nums[i]);
            else if(nums[i] > st.top()){
                while(!st.empty() && nums[i] > st.top()){
                    k = st.top();
                    st.pop();
                }
                st.push(nums[i]);
            }
            if(nums[i] < k)
                return true;
        }
        return false;
    }
};