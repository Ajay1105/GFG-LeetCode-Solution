class Solution {
public:
    int dp[205][205];

    bool isValid(int i, int j, vector<vector<int>>& matrix) {
        int n, m;
        n = matrix.size(); m = matrix[0].size();
        return i>=0&&j>=0&&i<n&&j<m;
    }

    int rec(int sr, int sc, vector<vector<int>>& matrix) {

        if (dp[sr][sc]!=-1) return dp[sr][sc];

        int ans = 1;
        if (isValid(sr+1,sc,matrix)&&matrix[sr][sc]<matrix[sr+1][sc]) {
            ans = max(ans, rec(sr+1,sc,matrix)+1);
        }
        if (isValid(sr,sc+1,matrix)&&matrix[sr][sc]<matrix[sr][sc+1]) {
            ans = max(ans, rec(sr,sc+1,matrix)+1);
        }       
        if (isValid(sr-1,sc,matrix)&&matrix[sr][sc]<matrix[sr-1][sc]) {
            ans = max(ans, rec(sr-1,sc,matrix)+1);
        }       
        if (isValid(sr,sc-1,matrix)&&matrix[sr][sc]<matrix[sr][sc-1]) {
            ans = max(ans, rec(sr,sc-1,matrix)+1);
        }       

        return dp[sr][sc] = ans;        

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int n, m;
        n = matrix.size(); m = matrix[0].size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, rec(i,j,matrix));
            }
        }
        return ans;
    }
};