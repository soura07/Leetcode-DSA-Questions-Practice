class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int i,j,k,n=grid.size(),ans=0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                k = 0;
                while(k<n&&grid[i][k]==grid[k][j])k++;
                if(k>=n)ans++;
            }
        }
        return ans;
    }
};
