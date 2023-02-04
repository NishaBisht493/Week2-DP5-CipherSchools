#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    string result = "";
    int len = s.size();
    int maxLen = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
        if(maxLen < dp[i][i]){
            maxLen = dp[i][i];
            result = s.substr(i, 1);
        }
    }

    int i, j;
    for(int window = 2; window <= len; window++){
        for(i = 0; i < len - window + 1; i++){
            j = i + window - 1;
            if(window == 2){
                if(s[i] == s[j]){
                    dp[i][j] = 2;
                    if(maxLen < dp[i][j]){
                        maxLen = dp[i][j];
                        result = s.substr(i, 2);
                    }
                }
            }
            else{
                if(s[i] == s[j] && dp[i + 1][j - 1] > 2){
                    dp[i][j] = window;
                    if(maxLen < dp[i][j]){
                        maxLen = dp[i][j];
                        result = s.substr(i, window);
                    }

                }
                else{
                    dp[i][j] = 0;
                }
            }

        }
    }
}

int main(){

}