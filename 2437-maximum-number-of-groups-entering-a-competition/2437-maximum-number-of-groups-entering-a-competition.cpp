class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());

        int n = grades.size();
        int teamSize = 2;
        int i = 1;
        int ans = 1;

        while(i < n){
            if(n-i < teamSize) return ans;
            int j = 0;
            while(j< teamSize){
                i++;
                j++;
            }
            teamSize++;
            ans++;
        }

        return ans;
    }
};