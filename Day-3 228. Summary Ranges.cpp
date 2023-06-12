class Solution {
public:
    vector<string> summaryRanges(vector<int>& vec) {
        vector<string>res;
        if(vec.size()==0){
            return res;
        }
        if(vec.size()==1){
            string p=to_string(vec[0]);
            res.push_back(p);
            return res;
        }
        int n=vec.size();
        int l=0,r=0;
        int i=0;
        vector<pair<int,int>>ans;
        while(i<n-1){
            if(vec[i]+1==vec[i+1]){
                r++;
            }
            else if(vec[i]+1!=vec[i+1]){
                ans.push_back({vec[l],vec[r]});
                l=i+1;
                r=i+1;
            }
            i++;
        }
        if(vec[i]==vec[i-1]+1){
            ans.push_back({vec[l],vec[r]});
        }
        else{
            ans.push_back({vec[l],vec[r]});
        }
        for(auto ele:ans){
            string temp="";
            cout<<ele.first<<" "<<ele.second<<endl;
            if(ele.first!=ele.second){
                temp+=(to_string(ele.first));
                temp+="->";
                temp+=(to_string(ele.second));
            }
            else{
                temp+=(to_string(ele.first));
            }
            res.push_back(temp);
        }
        return res;
    }
    //<!-- Please upvote if you liked!!! -->
};
