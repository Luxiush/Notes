/**
## 替换空格
### 题目:
将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy. 
### 解:
一个空格只需要占一个char,但是替换成"%20"后需要占用3个char. 所以需要在替换的时候用一个变量来记录偏移量. 
**/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		char buffer[4*length];
        int offset = 0;
        for(int i=0; i<length; ++i){
            if(str[i] == ' '){
                buffer[i+offset] = '%';
                buffer[i+offset+1] = '2';
                buffer[i+offset+2] = '0';
                offset += 2;
            }
            else
                buffer[i+offset] = str[i];
        }
        int j;
        for(j=0; j<length+offset; ++j){
            str[j] = buffer[j];
        }
        str[j] = '\0';
	}
};