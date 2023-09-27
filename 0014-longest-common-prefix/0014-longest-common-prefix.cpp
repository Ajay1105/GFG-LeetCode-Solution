class Solution {
public:

    string util(string a, string b){
        int n = a.length(), m = b.length(), i = 0;
        string ans;

        while(i<n && i<m){
            if(a[i] == b[i]){
                ans.push_back(a[i++]);
            }else{
                break;
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int len = strs.size();
        
        if(len == 1) return strs[0];
        if(len == 0) return "";
        
        string temp = util(strs[0], strs[1]);

        for(int i=2; i<strs.size(); i++){
            temp = util(temp, strs[i]);
        }

        return temp;
    }
};