/*最长公共子序列*/
#include<string.h>
#include<memory.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<algorithm>

using namespace std;

class INT_MAT{
public:
	int* mat;
	int width;
	int height;
	int out_of_range;
	
	int& operator()(const int a, const int b){
		if(a<0 || b<0){
			return out_of_range;
		}
		else if(0<=a && a<width && 0<=b && b<height){
			return mat[b*width+a];
		}
		printf("INT_MAT error: index out of range.\n");
		return out_of_range;
	}
	
	string str(){
		stringstream s;
		for(int i=0; i<this->height; ++i){
			s << "|";
			for(int j=0; j<this->width; ++j){
				s<< setw(3)<< mat[i*width+j]<< "|";
			}
			s << endl;
		}
		return s.str();
	}
	
	INT_MAT(int w, int h){
		this->width = w;
		this->height = h;
		mat = new int[width * height];
		memset(mat, 0, width*height*sizeof(int));
		out_of_range = 0;
	}
	
	~INT_MAT(){
		delete [] mat;
	}
};


void LCS(const char* s1, const char* s2, char* lcs){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	
	INT_MAT decision_table(len1, len2);
	//INT_MAT res_table(len1,lne2);
	
	for(int i1=0; i1<len1; ++i1){
		for(int i2=0; i2<len2; ++i2){
			if(s1[i1] == s2[i2]){
				decision_table(i1,i2) = decision_table(i1-1,i2-1) + 1;
			}
			else{
				if(decision_table(i1-1,i2) >= decision_table(i1,i2-1)){
					decision_table(i1,i2) = decision_table(i1-1,i2);
				}
				else{
					decision_table(i1,i2) = decision_table(i1,i2-1);
				}
			}
		}
	}
	
	printf("decision_table:\n%s\n", decision_table.str().c_str());
	
	int res_len = decision_table(len1-1,len2-2);
	lcs[res_len-1] = '\0';
	int i1 = len1-1;
	int i2 = len2-1;
	for(; res_len>0; --res_len){
		while(decision_table(i1-1,i2)==decision_table(i1,i2) && i1>0){
			i1 -= 1;
		}
		while(decision_table(i1,i2-1)==decision_table(i1,i2) && i2>0){
			i2 -= 1;
		}
		lcs[res_len-1] = s1[i1];
		i1 -= 1;
		i2 -= 1;
	}
	return; 
}


int main(int argc, char** argv){
	if(argc < 3){
		printf("Not enough arguments.\n");
		return -1;
	}
	
	char res[100];
	memset(res, 0, 100);
	printf("s1: %s\ns2: %s\n", argv[1], argv[2]);
	LCS(argv[1], argv[2], res);
	printf("res: %s\n\n", res);
	return 0;
}
