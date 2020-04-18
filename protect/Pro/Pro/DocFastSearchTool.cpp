 #define _CRT_SECURE_NO_WARNINGS 1
#include"Common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"     //具体路径下的头文件


//静态库调用
#pragma comment (lib,"./sqlite/sqlite3.lib")
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
void Test_Sqlite()
{
	//数据库的打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");
	
	
	//数据库的操作
	string sql = "select * from you_tb";
	char **result;
	int row;
	int col;
	char *zErrMsg = 0;

	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);
	
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%-5s", *(result + (i*col) + j));
		}
		cout << endl;
	}

	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);

}

/*
static int callback(void *data, int argc, char **argv, char **azColName)//回调函数
{
	int i;
	fprintf(stderr, "%s: \n", (const char*)data);
	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
void Test_Sqlite()
{
	//数据库的打开
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//数据库的操作
	char *zErrMsg = 0;
	const char* data = "Callback function called";
	//string sql = "create table s_tb(id int,name varchar(20),path varchar(100))";
	string sql = "select * from you_tb";
	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
	//fprintf(stdout, "Table created successfully\n");
		fprintf(stdout, "Select Data successfully\n");

	}
	sqlite3_close(db);
}

/*void Test_Sqlite()//数据库的打开
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if (rc){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
}*/

int main(int argc,char* argv[])
{
	Test_Sqlite();
	//Test_DirectionList();
	return 0;
}