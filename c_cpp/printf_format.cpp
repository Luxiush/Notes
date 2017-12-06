/* 十进制 转 16进制 */
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	int a = 0;
	char hex_str[50];
	cin >> a;
	
	sprintf(hex_str, "%07x\n", a);
	
	cout<< hex_str<< endl;
	
	return 0;
}