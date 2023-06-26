class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int l=0,r=n-1;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        long long cost=0;
        for(int i=0;i<k;i++){
            while(pq1.size()<candidates&&(l<=r)){
                pq1.push(costs[l]);
                l++;
            }
            while(pq2.size()<candidates&&(l<=r)){
                pq2.push(costs[r]);
                r--;
            }
            long long top1=INT_MAX,top2=INT_MAX;
            if(pq1.size()>0){
                top1=pq1.top();
            }
            if(pq2.size()>0){
                top2=pq2.top();
            }
            if(top1<=top2){
                cost+=top1;
                pq1.pop();
            }
            else{
                cost+=top2;
                pq2.pop();
            }
        }
        return cost;
    }
           
};
