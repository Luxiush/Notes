/*
## �����е�·��
### ��Ŀ:
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� ���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
### ˼·: �ݹ�
*/

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
            mat(current_r,current_c) = 255;		// ����Ѿ��߹���
            if(
               (str[1]=='\0')||					// ��һ��Ϊ�ַ����Ľ�����, ��ֹͣ�ݹ�
			   // �ݹ�ƥ����������
               (current_r-1>=0    && hasPathRec(current_r-1, current_c, str+1))||
               (current_r+1<_rows && hasPathRec(current_r+1, current_c, str+1))||
               (current_c-1>=0    && hasPathRec(current_r, current_c-1, str+1))||
               (current_c+1<_cols && hasPathRec(current_r, current_c+1, str+1))
              ){
                mat(current_r,current_c) = tmp;		// ����֮ǰȥ�����
                return true;
                 
            }
            mat(current_r,current_c) = tmp;			// ����֮ǰȥ�����
             
        }
        return false;
    }
};