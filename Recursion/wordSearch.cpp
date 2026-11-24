#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find(int i,int j,int ind,vector<vector<char>>& board, string word){
        if(ind==word.size()){return true;}
        if(i<0  || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='*';
        
        bool found=find(i-1,j,ind+1,board,word) ||
                   find(i+1,j,ind+1,board,word) ||
                   find(i,j-1,ind+1,board,word) ||
                   find(i,j+1,ind+1,board,word);
        board[i][j]=temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(find(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};