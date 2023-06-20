class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n =nums.size();
        // Intializing whole array with -1.
        vector<int>avg(n,-1);
        // window two pointers . sliding them will give us everytime new averages .
        int p=0,q=2*k;
        long long sum=0;
        // pre-computing 1st window average. LaterON we just remove 1 element from back 
        // and include 1 element from q+1.
        for(int i=0;i<n && i<=q;i++){
            sum+=nums[i];
        }
        // start from i=k and end at [(n-1)-k] .Rest self-Explanatory 
        // Just check what you are accessing through array,is it valid 
        // i.e. if(q<n-1) then nums[++q].
        for(int i=k;i<=(n-1-k);i++){
            avg[i]=sum/(2*k+1);
            sum-=(nums[p++]);
            if(q<n-1)sum+=(nums[++q]);
        }
        return avg;
    }
};
