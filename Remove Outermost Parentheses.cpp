class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        bool flag = true;
        string ans = "";
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='(')
            count++;
            else count--;
            if(count==1 && flag==true)
            {
                flag = false;
                continue;
            }
            if(count==0 && flag==false)
            {
                flag =true;
                continue;
            }
            ans = ans+s[i];
        }
        return ans;
    }
};
