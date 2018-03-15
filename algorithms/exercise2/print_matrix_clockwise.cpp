/**
## 顺时针打印矩阵
## 题目
输入一个矩阵, 按从外到里以顺时针的顺序输出矩阵的每个元素,
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
## 思路
按要求输出即可, 没什么难度. 
注意只有一行或只有一列的特殊情况下不要重复输出就好. 
**/
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > mat) {
        vector<int> res;
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows==0 || cols==0) return res;
        int r_min = 0, r_max = rows-1;
        int c_min = 0, c_max = cols-1;
        while(r_min<=r_max && c_min<=c_max){
            for(int i=c_min; i<=c_max; ++i){
                res.push_back(mat[r_min][i]);
            }
            for(int i=r_min+1; i<=r_max-1; ++i){
                res.push_back(mat[i][c_max]);
            }
            for(int i=c_max; r_min!=r_max && i>=c_min; --i){    //
                res.push_back(mat[r_max][i]);
            }
            for(int i=r_max-1; c_min!=c_max && i>=r_min+1; --i){ //
                res.push_back(mat[i][c_min]);
            }
            
            r_min++; r_max--;
            c_min++; c_max--;
        }
        return res;
    }
};

void print_mat(const vector<vector<int> > & mat, stringstream& sout){
    for(int i=0; i<mat.size(); ++i){
    for(int j=0; j<mat[i].size(); ++j){
        sout<< mat[i][j]<< " ";
    }
    sout<< endl;
    }
}

int main(){
    vector<vector<int> > mat;
    vector<int> temp;
    for(int i=0; i<16; ++i){
        temp.push_back(i);
        if(i%4 == 3){
            mat.push_back(temp);
            temp.clear();
        }
    }

    Solution S;
    vector<int> res;
    res = S.printMatrix(mat);
    for(int i=0; i<res.size(); ++i){
        cout<< res[i]<< " ";
    }
    cout<< endl;
    
    return 0;
}