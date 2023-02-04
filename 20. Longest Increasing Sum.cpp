#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSum(vector<int> &nums){
    int N = nums.size();
    int maxLen = 1;
    vector<int> dp(N + 1, 1);
    for(int i = 2; i < N ; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }
    return maxLen;
}

int longestIncreasingSum(vector<int> &nums){
    int N = nums.size();
    int maxLen = 1;
    vector<int> dp(N + 1);
    for(int i = 0; i < N;i++){
        dp[i] = nums[i];
    }
    for(int i = 1; i < N ; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], nums[i] + dp[j]);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }
    return maxLen;
}

int main(){

}