/**
## 矩阵中的路径
### 题目:
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
### 思路: 递归
**/

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        _matrix = matrix;
        _rows = rows;
        _cols = cols;

        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols; ++c){
                if(mat(r,c)==str[0] && hasPathRec(r,c, str))
                    return true;
            }
        }
        return false;
    }

private:
    char* _matrix;
    int _rows;
    int _cols;

    char& mat(int r, int c){ // 0<r<_rows, 0<c<_cols
        return _matrix[r*_cols+c];
    }

    bool hasPathRec(int current_r, int current_c, char* str){
        if(str[0]=='\0')
            return true;
        if(current_r<0 || current_c<0) return false;
        else if(current_r>=_rows || current_c>=_cols) return false;

        if(mat(current_r,current_c)==str[0]){
            char tmp = mat(current_r,current_c);
            mat(current_r,current_c) = 255;		// 标记已经走过的
            if(
               (str[1]=='\0')||					// 下一个为字符串的结束符, 则停止递归
			   // 递归匹配上下左右
               (current_r-1>=0    && hasPathRec(current_r-1, current_c, str+1))||
               (current_r+1<_rows && hasPathRec(current_r+1, current_c, str+1))||
               (current_c-1>=0    && hasPathRec(current_r, current_c-1, str+1))||
               (current_c+1<_cols && hasPathRec(current_r, current_c+1, str+1))
              ){
                mat(current_r,current_c) = tmp;		// 返回之前去掉标记
                return true;

            }
            mat(current_r,current_c) = tmp;			// 返回之前去掉标记

        }
        return false;
    }
};
