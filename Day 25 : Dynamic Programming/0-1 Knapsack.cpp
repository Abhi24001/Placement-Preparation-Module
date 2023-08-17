class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }

       for(int i =1;i<n;i++){
           for(int w=0;w<=W;w++){
               int p = INT_MIN;
                int np = dp[i-1][w];
                if(wt[i]<=w){
                    p= val[i]+dp[i-1][w-wt[i]];
                }
                dp[i][w]= max(p,np);
           }
       }
       return dp[n-1][W];
    }
};
