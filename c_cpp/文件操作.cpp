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
        cout<<"请输入要复制的文件路径(包括执行文件名和文件后缀名):\n";
        cin>>filepath;
        source = fopen(filepath.data(),"rb");
        if(source == NULL)
        {
            cout<<"打开文件失败!从新";
            continue;
        }
        fseek(source,0,SEEK_END);
        length = ftell(source);
        char* data = new char[length];
        rewind(source);
        fread((void*)data,sizeof(char),length,source);
        cout<<"请输入文件粘贴路径(包括执行文件名和文件后缀名):\n";
        cin>>filepath;
        destination = fopen(filepath.data(),"wb");
        if(destination == NULL)
        {
            delete data;
            cout<<"写入文件失败!"<<endl;
            fclose(source);
            continue;
        }
        fwrite((void*)data,sizeof(char),length,destination);
        fclose(destination);
        fclose(source);
        delete data;
        cout<<"关闭文件成功"<<endl;
        break;
    }

    system("pause");  
}
