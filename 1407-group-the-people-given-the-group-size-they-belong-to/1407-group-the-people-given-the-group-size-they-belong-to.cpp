class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;

        for(int i=0; i<gs.size(); i++)
            mp[gs[i]].push_back(i);
        
        for(auto i:mp){
            while(i.second.size()){
                vector<int> temp;
                for(int j=0; j<i.first; j++){
                    temp.push_back(i.second.front());
                    i.second.erase(i.second.begin());
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};