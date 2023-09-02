class Trie{
     Trie* list[26];
     bool flag;
     public: 
     Trie(){
         for(int i=0;i<26;i++){
             list[i]=NULL;
         }
         flag=false;
     }

     void put(char c){
         list[c-'a']=new Trie();
     }
     Trie* get(char c){
         return list[c-'a'];
     }
     bool contain(char c){
         return list[c-'a']!=NULL;
     }
     void setflag(){
         flag=true;
     }
     bool getflag(){
         return flag;
     }

};

class Solution {
public:
   int dp[50];
    int helper(string &s,int index,Trie* root){

        if(index==s.length()) return 0;

        if(dp[index]!=-1) return dp[index];
        int j=index;
        int mini=51;

        Trie* iter= root;

        while(j<s.length() && iter->contain(s[j])){
          
            iter=iter->get(s[j]);
            j++;
              if(iter->getflag()){
                  mini=min(mini,helper(s,j,root));
              }

        }

        mini = min(mini, 1+helper(s,index+1,root));

        return dp[index]=mini;
    }


    int minExtraChar(string s, vector<string>& dictionary) {
    
       Trie* root= new Trie();         
         for(auto &word : dictionary){
             Trie* iter=root;
             for(auto &ch: word){
                 
                 if(!iter->contain(ch)){
                     iter->put(ch);
                 }
                 iter=iter->get(ch);
             }
             iter->setflag();
         }
         memset(dp,-1,sizeof(dp));
        return helper(s,0,root);
    }
};