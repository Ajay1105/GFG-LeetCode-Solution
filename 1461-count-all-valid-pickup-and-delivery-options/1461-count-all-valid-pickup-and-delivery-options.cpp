class Solution {
    const int MOD = 1e9+7;
public:
    int countOrders(int n) {
        long long int ans = 1;
        
        for(int i=2; i<=n; i++){
            ans = ans*(2*i -1) *i;
            ans %= MOD;
        }

        return (int)ans;
    } 
};