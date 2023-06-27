class Solution {
public:
    typedef tuple<int, int, int> t;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> ans;
        priority_queue<t, vector<t>, greater<t>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums1[i]+nums2[0], i, 0});
        }
        while(k-- && !pq.empty()){
            auto [a,b,c] = pq.top();
            pq.pop();
            ans.push_back({nums1[b], nums2[c]});
            if(c+1 == nums2.size())
                continue;
            pq.push({nums1[b] + nums2[c+1], b, c+1});
        }
        return ans;
    }
};
