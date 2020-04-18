#define _CRT_SECURE_NO_WARNINGS 1
#include"Sysutil.h"

void DirectionList(const string &path, vector<string> &subfile, vector<string> &subdir)//Ŀ¼����ʾ
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*��Ŀ¼���κ��ļ�
	_finddata_t file;       //���� file �Ľṹ��
	long handle = _findfirst(_path.c_str(), &file);//handle�ļ����������շ���ֵ
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1����������
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//����.��..�ļ�
			continue;
		if (file.attrib & _A_SUBDIR)//ƥ���ļ���  ��ʾ�ļ��������Ŀ¼���ݹ�ʵ�֣�
		{
			subdir.push_back(file.name);//Ŀ¼����
		}
		else
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);//����ֵΪ0��������ȷ
	_findclose(handle);
}

/*
//��ʾ�ļ������Ŀ¼
void DirectionList(const string &path)//Ŀ¼����ʾ
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*��Ŀ¼���κ��ļ�
	_finddata_t file;       //���� file �Ľṹ��
	long handle = _findfirst(_path.c_str(), &file);//handle�ļ����������շ���ֵ
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1����������
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//����.��..�ļ�
			continue;
		if (file.attrib & _A_SUBDIR)//ƥ���ļ���  ��ʾ�ļ��������Ŀ¼���ݹ�ʵ�֣�
		{
			cout << file.name << endl;
			string tmp_path = path;
			tmp_path += "\\";
			tmp_path += file.name;
			DirectionList(tmp_path);
		}
		else
		  cout << file.name << endl;

	} while (_findnext(handle, &file) == 0);//����ֵΪ0��������ȷ
	_findclose(handle);
}

/*
//��ӡָ��Ŀ¼�µ��ļ�
void DirectionList(const string &path)//Ŀ¼����ʾ
{
	string _path = path;    //C:\\Users\\29357\\Desktop\\pro
	_path += "\\*.*";       //C:\\Users\\29357\\Desktop\\pro\\*.*��Ŀ¼���κ��ļ�
	_finddata_t file;       //���� file �Ľṹ��
	long handle = _findfirst(_path.c_str(), &file);//handle�ļ����������շ���ֵ
	if (handle == -1)
	{
		perror("_findfirst");   //handle=-1����������
		return;
	}
	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)//����.��..�ļ�
			continue;
		cout << file.name << endl;

	} while (_findnext(handle, &file) == 0);//����ֵΪ0��������ȷ
	_findclose(handle);
}
*/