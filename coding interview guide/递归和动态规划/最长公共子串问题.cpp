//
// Created by 钟奇龙 on 2019-05-05.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > getDpArray(string s1,string s2){
    int row = s1.size();
    int col = s2.size();
    vector<vector<int> > dp(row,vector<int> (col,0));
    dp[0][0] = s1[0] == s2[0] ? 1:0;
    for(int i=1; i<row; ++i){
        dp[i][0] = s1[i] == s2[0] ? 1:0;
    }
    for(int j=1; j<col; ++j){
        dp[0][j] = s1[0] == s2[j] ? 1:0;
    }
    for(int i=1; i<row; ++i){
        for(int j=1; j<col; ++j){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    return dp;
}
string longestCommonSubString(string s1,string s2){
    if(s1.size() == 0 || s2.size() == 0){
        return "";
    }
    string res = "";
    vector<vector<int> > dp = getDpArray(s1,s2);
    int maxlen = 0;
    int end = 0;
    for(int i=0; i<dp.size(); ++i){
        for(int j=0; j<dp.size(); ++j){
            if(dp[i][j] > maxlen){
                maxlen = dp[i][j];
                end = i;
            }
        }
    }
    return s1.substr(end-maxlen+1,maxlen);
}
/*
 * 最优解，空间复杂度O(1)
 */
string longestCommonSubstr2(string s1,string s2){
    if(s1.size() == 0 || s2.size() == 0) return "";
    int row = 0;
    int col = s2.size()-1;
    int maxLen = 0;
    int end = 0;
    while(row < s1.size()){
        int i=row;
        int j=col;
        int length = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                length++;
            }else{
                length = 0;
            }
            if(length > maxLen){
                maxLen = length;
                end = i;
            }
            i++;
            j++;
        }
        if(col == 0){
            row++;
        }else{
            col--;
        }

    }
    return s1.substr(end-maxLen+1,maxLen);

}
int main(){
    string s1 = "abcde";
    string s2 = "bebcd";
    cout<<longestCommonSubString(s1,s2)<<endl;
    cout<<longestCommonSubstr2(s1,s2)<<endl;

    return 0;
}
