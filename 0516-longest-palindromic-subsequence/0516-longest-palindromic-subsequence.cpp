class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t,s);
    }

    int lcs(string source, string target)
    {
        int n = source.size();
        int m = target.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i = 1; i<= n ; i++)
        {
            for(int j = 1; j<= m ; j++)
            {
                if(source[i-1]== target[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};