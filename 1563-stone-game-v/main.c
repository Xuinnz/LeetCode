#include <string.h>

int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    if (n == 1){
        return 0;
    }
    int prefix[505];
    prefix[0] = 0;
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    int dp[505][505];
    memset(dp, 0, sizeof(dp));

    for(int length = 2; length < n + 1; length++){
        for(int i = 0; i < n - length + 1; i++){
            int j = length + i - 1;
            for(int k = i; k < j; k++){
                int left_sum = prefix[k + 1] - prefix[i];
                int right_sum = prefix[j + 1] - prefix[k + 1];

                if (left_sum < right_sum){
                    dp[i][j] = MAX(dp[i][j], left_sum + dp[i][k]);
                } 
                else if (left_sum > right_sum){
                    dp[i][j] = MAX(dp[i][j], right_sum + dp[k + 1][j]);
                }
                else{
                    dp[i][j] = MAX(dp[i][j], left_sum + MAX(dp[i][k], dp[k + 1][j]));
                }
            }
        }
    }
    return dp[0][n - 1];
}
//used c instead of python so it wont get TLE and beating only 5% in time. accepted tho
