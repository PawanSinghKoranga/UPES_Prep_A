class Solution {
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        
        stk.push(-1);
        
        int maxim=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            else
                if(s[i]==')')
                {
                    
                    stk.pop();
                    
                    if(!stk.empty())
                    {
                    int len=i-stk.top();
                    if(maxim<len)
                        maxim=len;
                    }
                    else
                    stk.push(i);
                    
                }
            
        }
        
        return maxim;
        
    }
};