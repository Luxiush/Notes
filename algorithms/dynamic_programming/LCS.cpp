/*最长公共子序列*/
#include<string.h>
#include<memory.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void LCS(const char* str1, const char* str2, char* lcs){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len_lcs = 0;
		
	int* table = new int [(len1+1)*(len2+1)]; //决策表
	
	for(int i=0; i<=len1; i++)
		table[i*(len2+1)] = 0;
	for(int j=0; j<=len2; j++)
		table[j] = 0;
	
	for(int i=1; i<=len1; i++){
		for(int j=1; j<=len2; j++){
			if(str1[i-1] == str2[j-1]){
				table[i*(len2+1)+j] = table[(i-1)*(len2+1)+(j-1)]+1;
			}
			else if(table[(i-1)*(len2+1)+j] >= table[i*(len2+1)+(j-1)]){
				table[i*(len2+1)+j] = table[(i-1)*(len2+1)+j];
			}
			else{
				table[i*(len2+1)+j] = table[i*(len2+1)+(j-1)];
			}
		}
	}
	
	//构造LCS
	//......
	
	
	printf("===========================\n");
	for(int i=0; i<=len1; i++){
		for(int j=0; j<=len2; j++){
			printf("(%2d,%2d):%2d||\t",i,j,table[i*(len2+1)+j]);
		}
		printf("\n");
	}
	
	delete [] table;
}

int main(int argc, char* argv[]){
	if(argc != 3){
		cout<< "ERROR."<< endl;
		return -1;
	}
	
	const int MAXLEN = 100;
	char lcs[MAXLEN];
	memset(lcs, 0, sizeof(char)*MAXLEN);
	
	LCS(argv[1], argv[2], lcs);
	
	printf("%s\nDone.\n",lcs);
	
	return 0;
}