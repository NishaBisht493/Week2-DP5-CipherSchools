#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &prices){
    int L = prices.size();
    vector<int> dp(L + 1, 0);
    for(int l = 1; l <= L; l++){
        dp[l] = prices[l - 1];
        for(int j = 1; j <= l; j++){
            dp[l] = max(dp[l], dp[j] + dp[l - j]);
        }
    }
    return dp[L];
}

int main(){

}