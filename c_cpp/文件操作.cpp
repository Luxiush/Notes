/*
#include<iostream>
#include<fstream>

int main()
{
	ofstream fout;
	int num;
	char a[] = "John Doe";
	fout.open("output.txt");
	num = 20;
	fout << "Here id a number:" << num << "  \n";
	fout << "Now here.....";
	fout << flush;
	fout.close();
	
	return 0;
} 
*/



#include <iostream>
#include <cstdio>
#include <string>
using namespace std;  

int main()  
{
    while(true)
    {
        string filepath;
        int length;
        FILE *source,*destination;
        cout<<"������Ҫ���Ƶ��ļ�·��(����ִ���ļ������ļ���׺��):\n";
        cin>>filepath;
        source = fopen(filepath.data(),"rb");
        if(source == NULL)
        {
            cout<<"���ļ�ʧ��!����";
            continue;
        }
        fseek(source,0,SEEK_END);
        length = ftell(source);
        char* data = new char[length];
        rewind(source);
        fread((void*)data,sizeof(char),length,source);
        cout<<"�������ļ�ճ��·��(����ִ���ļ������ļ���׺��):\n";
        cin>>filepath;
        destination = fopen(filepath.data(),"wb");
        if(destination == NULL)
        {
            delete data;
            cout<<"д���ļ�ʧ��!"<<endl;
            fclose(source);
            continue;
        }
        fwrite((void*)data,sizeof(char),length,destination);
        fclose(destination);
        fclose(source);
        delete data;
        cout<<"�ر��ļ��ɹ�"<<endl;
        break;
    }

    system("pause");  
}
