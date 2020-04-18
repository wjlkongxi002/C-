#define _CRT_SECURE_NO_WARNINGS 1
#include"Sysutil.h"

void DirectionList(const string &path, vector<string> &subfile, vector<string> &subdir)//目录的显示
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*该目录下任何文件
	_finddata_t file;       //定义 file 的结构体
	long handle = _findfirst(_path.c_str(), &file);//handle文件描述符接收返回值
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1，搜索错误
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//屏蔽.和..文件
			continue;
		if (file.attrib & _A_SUBDIR)//匹配文件夹  显示文件夹下面的目录（递归实现）
		{
			subdir.push_back(file.name);//目录向量
		}
		else
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);//返回值为0是搜索正确
	_findclose(handle);
}

/*
//显示文件下面的目录
void DirectionList(const string &path)//目录的显示
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*该目录下任何文件
	_finddata_t file;       //定义 file 的结构体
	long handle = _findfirst(_path.c_str(), &file);//handle文件描述符接收返回值
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1，搜索错误
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//屏蔽.和..文件
			continue;
		if (file.attrib & _A_SUBDIR)//匹配文件夹  显示文件夹下面的目录（递归实现）
		{
			cout << file.name << endl;
			string tmp_path = path;
			tmp_path += "\\";
			tmp_path += file.name;
			DirectionList(tmp_path);
		}
		else
		  cout << file.name << endl;

	} while (_findnext(handle, &file) == 0);//返回值为0是搜索正确
	_findclose(handle);
}

/*
//打印指定目录下的文件
void DirectionList(const string &path)//目录的显示
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*该目录下任何文件
	_finddata_t file;       //定义 file 的结构体
	long handle = _findfirst(_path.c_str(), &file);//handle文件描述符接收返回值
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1，搜索错误
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//屏蔽.和..文件
			continue;
		cout << file.name << endl;

	} while (_findnext(handle, &file) == 0);//返回值为0是搜索正确
	_findclose(handle);
}
*/