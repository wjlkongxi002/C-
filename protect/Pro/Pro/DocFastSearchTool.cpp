#define _CRT_SECURE_NO_WARNINGS 1
#include"Common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"     //����·���µ�ͷ�ļ�
#include"DataManager.h"
#include"ScanManager.h"


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
	//���ݿ�Ĵ�
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		cout << "Open database failed." << endl;
		//printf("Open database failed.\n");
	else
		printf("Open database successed.\n");
	
	
	//���ݿ�Ĳ���
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
	//�ر����ݿ�
	sqlite3_close(db);

}
void Test_SqliteManager()
{
	SqliteManager sm;
	sm.Open("doc.db");

	//string sql = "create table if not exists doc_tb(id integer primary key autoincrement, doc_name text, doc_path text)";
	//sm.ExecuteSql(sql);
	//string sql1 = "insert into doc_tb values(null, 'stl.pdf', 'c:\\')";
	//sm.ExecuteSql(sql1);

	string sql = "select * from doc_tb";
	int row = 0, col = 0;
	char **ppRet = 0;
	sm.GetResultTable(sql, row, col, ppRet);
	for (int i = 0; i <= row; ++i)
	{
		for (int j = 0; j<col; ++j)
		{
			printf("%-10s", *(ppRet + (i*col) + j));
		}
		cout << endl;
	} 
	sqlite3_free_table(ppRet);
}

void Test_Log()//��־����
{
	FILE *fp = fopen("Test.txt", "r");
	if (fp == NULL)
	{
		TRACE_LOG("Open File Error.");
		return;
	}
	else
		TRACE_LOG("Open File Success.");

	fclose(fp);
}

void Test_Scan()
{
	const string &path = "C:\\Users\\29357\\Desktop\\pro";
	ScanManager sm;
    sm.ScanDirectory(path);
}

void Test_Search()
{
	const string &path = "C:\\Users\\29357\\Desktop\\pro";

	//����ɨ��ʵ��
	ScanManager sm;
	sm.ScanDirectory(path);

	//��������ʵ��
	DataManager dm;
	string key;

	vector<pair<string, string>> doc_path;
	while (1)
	{
		cout << "������Ҫ�����Ĺؼ���:>";
		cin >> key;
		dm.Search(key, doc_path);

		//��ʾ���
		printf("%-15s%-50s\n", "����", "·��");
		for (const auto &e : doc_path)
			printf("%-15s%-50s\n", e.first.c_str(), e.second.c_str());
	}
}

void thread_fun(int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << "This is Child Thread." << endl;
	}
}

class Test
{
public:
	void fun()
	{
		cout << "This is Test::fun()" << endl;
	}
};

void Test_Thread()
{
	Test t;
	thread th(&Test::fun, &t);
	th.detach();  //����

	for (int i = 0; i<10; ++i)
	{
		cout << "This is Main Thread." << endl;
	}

	//th.join();//�ȴ�

}


int main(int argc, char* argv[])
{
	//Test_Log();//��־����
	//Test_SqliteManager();//���ݿ������ԣ���װ��
	//Test_Sqlite();
	//Test_DirectionList();
	//Test_Scan();
	//Test_Search();
	Test_Thread();
	return 0;
}
/*
static int callback(void *data, int argc, char **argv, char **azColName)//�ص�����
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
	//���ݿ�Ĵ�
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//���ݿ�Ĳ���
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

/*void Test_Sqlite()//���ݿ�Ĵ�
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
}

int main(int argc,char* argv[])
{
	Test_Sqlite();
	//Test_DirectionList();
	return 0;
}*/
