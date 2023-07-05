//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    int f(int ind, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind==n)
          return 0;
        
        if(dp[ind][buy]!=-1)
          return dp[ind][buy];
        
        int profit=0;
        if(buy)
           profit = max(-prices[ind] + f(ind+1,0,n,prices,dp), 0 + f(ind+1,1,n,prices,dp));
        else
           profit = max(prices[ind] + f(ind+1,1,n,prices,dp), 0 + f(ind+1,0,n,prices,dp));
           
        return dp[ind][buy]=profit;
    }
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return f(0,1,n,prices,dp);
        
        // Tabulation Code
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        int profit=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
              if(buy)
                profit = max(-prices[ind] + f(ind+1,0,n,prices,dp), 0 + f(ind+1,1,n,prices,dp));
              else
                profit = max(prices[ind] + f(ind+1,1,n,prices,dp), 0 + f(ind+1,0,n,prices,dp));
           
               dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends