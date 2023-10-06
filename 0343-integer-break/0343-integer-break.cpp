class Solution {
public:
    int integerBreak(int n) {
       if(n==2) return 1;
       if(n==3) return 2;
       if(n==4) return 4;
       
       int ans=0;

       if(n%3 ==1){
           n-=4;
           ans = 4;
       }else{
           ans= n%3;
       }

       if(ans) ans *= pow(3,n/3);
       else ans = pow(3,n/3);

       return ans;
    }
};