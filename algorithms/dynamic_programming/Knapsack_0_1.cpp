/** 0-1��������
 * http://blog.csdn.net/mu399/article/details/7722810
 * �ӽṹ��
		����һ��������Ʒi���Ƚ�ѡ��i�γɵ�����������Ž���
		��ѡ��i�γɵ����Ž⣬ѡ�����е����š�
		
 * ת�Ʒ��̣�
		n			��Ʒ�ܼ���
		w[i]		��Ʒi������
		v[i]		��Ʒi�ļ۸�
		c			��������
		m[i,j]		ǰi��([0,i])��Ʒ��������Ϊj�ı����л�õ�����ֵ
	m[i,j] = max{m[i-1,j-w[i]]+v[i], m[i-1,j]}
					ѡi			  , ��ѡi

 * �ݹ��α����
	knap_rec(i,j){
		if(i==0){
			if(w[i]<=j) return v[i];
			else return 0;
		}
		return max(knap_rec(i-1, j-w[i])+v[i],knap_rec(i-1,j));
	}
	Knap(n,c){
		return knap_rec(n,c);
	}

 * �������ݹ��
	knap_mem_rec(i,j, m){
		if(i==0){
			if(w[i]<=j) return v[i];
			else return 0;
		}
		
		if(m[i,j] == 0) 
			m[i,j] = max(knap_mem_rec(i-1, j-w[i], m)+v[i], knap_mem_rec(i-1,j, m));
		
		return m[i,j];
	}
	
	Knap(n,c){
		set m to 0;
		return knap_mem_rec(n,c, m);
	}
*/
/* �Ե����ϣ��ǵݹ��*/
#include<memory.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int Knap(int n, int c, int* w, int* v){
	int m[n][c+1];
	int i,j;
	memset(m, 0, n*(c+1)*sizeof(int));
	
	int temp = 0;
	for(j=c; j>=w[0]; --j)
		m[0][j] = v[0];
	for(i=1; i<n; ++i){
		for(j=1; j<=c; ++j){
			if(j-w[i]>=0)
				m[i][j] = m[i-1][j-w[i]]+v[i];
			
			if(m[i][j]<m[i-1][j]) 
				m[i][j] = m[i-1][j];
		}
	}
	
	printf("��Ʒѡ�񷽰�: ");
	for(i=n-1, j=c; i>=0; --i){
		if(m[i][j] != m[i-1][j]){
			printf("%5d", i);
			j -= w[i];
		} 
	}
	printf("\n");
	
	printf("m:\n");
	for(i=0; i<n; ++i){
		for(j=0; j<=c; ++j){
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
	
	return m[n-1][c];
}

int main(int argc, char** argv){
	if(argc != 2){
		printf("Not enough arguments.\n");
		return -1;
	}
	
	const int MAX_SIZE = 100;
	int w[MAX_SIZE];
	int v[MAX_SIZE];
	int n, c;
	
	fstream fin(argv[1], ios::in);
	fin>> n>> c;
	for(int i=0; i<n; ++i)
		fin>> w[i];
	for(int i=0; i<n; ++i)
		fin>> v[i];
	fin.close();
	
	cout<< "����ֵ: "<< Knap(n, c, w, v)<< endl;
	
	return 0;
}
















