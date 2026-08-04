class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        auto result = std::minmax_element(nums.begin(), nums.end());
        int max = *result.second;
        int min = *result.first;
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int>ans ;

        for(int i=min ;i<=max;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans ;
    }
};