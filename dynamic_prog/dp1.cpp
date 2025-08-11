/*dp has 2 approaches :
1) top down - recursion + memoization
2) bottom up - tabulation


steps :
1) first create a dp array of dp[n+1]
2) then return dp[n]
3) if dp[n] has a value then no need to go to recursion 
and return value from the dp array*/

//to calculate fibonacci number
//top down method
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp)
{
    //base case
    if (n <= 1)
    {
        return n;
    }

    //step 3
    if (dp[n] != -1)
    {
        return dp[n];
    }

    //step 2
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    //step 1
    vector<int> dp(n+1);
    for (int i = 0; i <=n; i++)
    {
        dp[i] = -1;
    }

    cout<<fib(n, dp)<<endl;
    return 0;
}

//tabulation method
int main2()
{
    int n;
    cin>>n;

    //step 1
    vector<int>dp(n+1);

    //step 2
    dp[1] = 1;
    dp[0] = 0;

    //step3
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<endl;
    return 0;
}