class Solution {
public:
    vector<int> countBits(int n) {
vector<int> vec;
        vec.push_back(0);
        if(n==0) return vec;
        vec.push_back(1);
        if(n==1) return vec;
        for(int i=2;i<=n;i++){
            if(i%2==0) vec.push_back(vec[i/2]);
            else vec.push_back(vec[i/2]+1);
        }
    return vec;
    }
};