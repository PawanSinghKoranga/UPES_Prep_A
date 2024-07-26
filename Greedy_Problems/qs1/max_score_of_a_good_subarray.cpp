#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
  
   void funl(vector<int> &left,vector<int> &nums)
   {

       stack<int> stk;
       stk.push(-1);

       for(int i=0;i<nums.size();i++)
       {
           
           while(stk.top()!=-1 and !stk.empty() and nums[stk.top()]>=nums[i])
           {
               stk.pop();
           }

           left.push_back(stk.top());
           stk.push(i);

       }

   }

    void funr(vector<int> &right,vector<int> &nums)
    {
        stack<int> stk;

        stk.push(nums.size());

        for(int i=nums.size()-1;i>=0;i--)
        {

            while(stk.top()!=nums.size() and !stk.empty() and nums[stk.top()]>=nums[i])
            {
                stk.pop();

            }

            right.push_back(stk.top());
            stk.push(i);

        }
    }



    int maximumScore(vector<int>& nums, int k) 
    {
        vector<int> left;
        vector<int> right;

        funl(left,nums);
        funr(right,nums);


        reverse(right.begin(),right.end());

        int ans=0;



  

        for(int i=0;i<nums.size();i++)
        {
            if(k>=(left[i]+1) and k<=(right[i]-1))
            ans=max(ans,nums[i]*(right[i]-left[i]-1));
        }

        return ans;

    }
};


int main()
{
    Solution a;
    vector<int> v={1,4,3,7,4,5};
    int ans=a.maximumScore(v,3);
    cout<<ans<<endl;

    return 0;
}

