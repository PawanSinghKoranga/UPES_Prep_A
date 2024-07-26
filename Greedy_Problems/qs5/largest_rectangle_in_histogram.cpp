class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
       int n=heights.size();
        
        int left[n];
        int right[n];
       
        stack<int> stk;
        stk.push(n-1);
        right[n-1]=n;
      
        for(int i=n-2;i>=0;i--)
        {
            if(heights[i]>heights[stk.top()])
            {
                right[i]=stk.top();
                stk.push(i);
            }
            else
            {
                while(!stk.empty()&&heights[i]<=heights[stk.top()])
                    stk.pop();
                
                if(stk.empty())
                    right[i]=n;
                 else   
                  right[i]=stk.top();
                  stk.push(i);
                
            }
        }
        
        while(!stk.empty())
            stk.pop();
        
        stk.push(0);
        left[0]=-1;
        
        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[stk.top()])
            {
                left[i]=stk.top();
                stk.push(i);
            }
            else
            {
                while(!stk.empty()&&heights[i]<=heights[stk.top()])
                    stk.pop();
                
                if(stk.empty())
                    left[i]=-1;
                else
                left[i]=stk.top();
                stk.push(i);
                
            }
        }
        
        int maxim=0;
        
        for(int i=0;i<n;i++)
        {
            int width=right[i]-left[i]-1;
            int area=width*heights[i];
            if(area>maxim)
                maxim=area;
        }
        
        return maxim;
        
    }
};