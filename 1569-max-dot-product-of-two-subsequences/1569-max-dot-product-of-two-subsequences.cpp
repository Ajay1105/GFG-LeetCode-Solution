class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n+1][m+1];

        auto m1= max_element(nums1.begin(), nums1.end());
        auto m2= max_element(nums2.begin(), nums2.end());
        auto n1= min_element(nums1.begin(), nums1.end());
        auto n2= min_element(nums2.begin(), nums2.end());

        if((*m1)*(*m2) < 0)
            return max((*m1)*(*n2), (*n1)*(*m2));

        for(int i=0; i<=n; i++)
            dp[i][0] = 0;

        for(int i=0; i<=m; i++)
            dp[0][i] = 0;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]), (dp[i-1][j-1]+(nums1[i-1]*nums2[j-1])));

        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         cout << dp[i][j]<< " ";
        //     }
        //     cout << endl;
        // }

        return dp[n][m];
    }
};