#define _CRT_SECURE_NO_WARNINGS 1
#include"Common.h"
#include"Sysutil.h"

void Test_DirectionList()
{
	const string &path = "C:\\Users\\29357\\Desktop\\pro";
	vector<string> subfile, subdir;
	DirectionList(path,subfile,subdir);
	for (const auto &e : subfile)
		cout << e << endl;
	for (const auto &e : subdir)
		cout << e << endl;
}

int main(int argc,char* argv[])
{
	Test_DirectionList();
	return 0;
}