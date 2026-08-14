class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length() ;
        vector<int>counter(26,0);
        int i = 0;
        int j = 0;
        int maxL = INT_MIN ;
        while(j<n){
            counter[s[j]-'a']++;
            while(counter[s[j]-'a']>2){
                counter[s[i]-'a']--;
                i++;
            }
            maxL = max(maxL,j-i+1);
            j++;
        }

        return maxL ;
    }
};