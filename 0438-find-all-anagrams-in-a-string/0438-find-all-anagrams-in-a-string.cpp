class Solution {
public:


   bool allZero(vector<int>& counter ){
    for(int &x:counter){
        if(x!=0)
        return false ;
    }
    return true ;
   }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int>counter(26,0);
        for(int i=0;i<m;i++){
            char ch = p[i];
            counter[ch-'a']++ ;
        }

        int i = 0;
        int j = 0 ;
        vector<int>result ;
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==m){
                if(allZero(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
           return result ;
    }
};