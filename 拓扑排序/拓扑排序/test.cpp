#define _CRT_SECURE_NO_WARNINGS 1

/**
* C++: �޻�·����ͼ(Directed Acyclic Graph)����������
*      ��DAGͼ��ͨ���ڽӱ�ʵ�ֵġ�
*
*
*/

#include <iomanip>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 100
// �ڽӱ�
class ListDG
{
private: // �ڲ���
	// �ڽӱ��б��Ӧ������Ķ���
	class ENode
	{
		int ivex;           // �ñ���ָ��Ķ����λ��
		ENode *nextEdge;    // ָ����һ������ָ��
		friend class ListDG;
	};

	// �ڽӱ��б�Ķ���
	class VNode
	{
		char data;          // ������Ϣ
		ENode *firstEdge;   // ָ���һ�������ö���Ļ�
		friend class ListDG;
	};

private: // ˽�г�Ա
	int mVexNum;             // ͼ�Ķ������Ŀ
	int mEdgNum;             // ͼ�ıߵ���Ŀ
	VNode *mVexs;            // ͼ�Ķ�������

public:
	// �����ڽӱ��Ӧ��ͼ(�Լ�����)
	ListDG();
	// �����ڽӱ��Ӧ��ͼ(�����ṩ������)
	ListDG(char vexs[], int vlen, char edges[][2], int elen);
	~ListDG();

	// ���������������ͼ
	void DFS();
	// ����������������������Ĳ�α�����
	void BFS();
	// ��ӡ�ڽӱ�ͼ
	void print();
	// ��������
	int topologicalSort();

private:
	// ��ȡһ�������ַ�
	char readChar();
	// ����ch��λ��
	int getPosition(char ch);
	// ���������������ͼ�ĵݹ�ʵ��
	void DFS(int i, int *visited);
	// ��node�ڵ����ӵ�list�����
	void linkLast(ENode *list, ENode *node);
};

/*
* �����ڽӱ��Ӧ��ͼ(�Լ�����)********************************************************************
*/
ListDG::ListDG()
{
	char c1, c2;
	int v, e;
	int i, p1, p2;
	ENode *node1, *node2;

	// ����"������"��"����"
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum >(mVexNum * (mVexNum - 1))))
	{
		cout << "input error: invalid parameters!" << endl;
		return;
	}

	// ��ʼ��"�ڽӱ�"�Ķ���
	mVexs = new VNode[mVexNum];
	for (i = 0; i<mVexNum; i++)
	{
		cout << "vertex(" << i << "): ";
		mVexs[i].data = readChar();
		mVexs[i].firstEdge = NULL;
	}

	// ��ʼ��"�ڽӱ�"�ı�
	for (i = 0; i<mEdgNum; i++)
	{
		// ��ȡ�ߵ���ʼ����ͽ�������
		cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		// ��ʼ��node1
		node1 = new ENode();
		node1->ivex = p2;
		// ��node1���ӵ�"p1���������ĩβ"
		if (mVexs[p1].firstEdge == NULL)
			mVexs[p1].firstEdge = node1;
		else
			linkLast(mVexs[p1].firstEdge, node1);
	}
}

/*
* �����ڽӱ��Ӧ��ͼ(�����ṩ������)***********************************************************
*/
ListDG::ListDG(char vexs[], int vlen, char edges[][2], int elen)
{
	char c1, c2;
	int i, p1, p2;
	ENode *node1, *node2;

	// ��ʼ��"������"��"����"
	mVexNum = vlen;
	mEdgNum = elen;
	// ��ʼ��"�ڽӱ�"�Ķ���
	mVexs = new VNode[mVexNum];
	for (i = 0; i<mVexNum; i++)
	{
		mVexs[i].data = vexs[i];
		mVexs[i].firstEdge = NULL;
	}

	// ��ʼ��"�ڽӱ�"�ı�
	for (i = 0; i<mEdgNum; i++)
	{
		// ��ȡ�ߵ���ʼ����ͽ�������
		c1 = edges[i][0];
		c2 = edges[i][1];

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		// ��ʼ��node1
		node1 = new ENode();
		node1->ivex = p2;
		// ��node1���ӵ�"p1���������ĩβ"
		if (mVexs[p1].firstEdge == NULL)
			mVexs[p1].firstEdge = node1;
		else
			linkLast(mVexs[p1].firstEdge, node1);
	}
}

/*
* ��������
*/
ListDG::~ListDG()
{
	ENode *node;

	for (int i = 0; i<mEdgNum; i++)
	{
		node = mVexs[i].firstEdge;
		while (node != NULL)
		{
			delete node;
			node = node->nextEdge;
		}
	}

	delete[] mVexs;
}

/*
* ��node�ڵ����ӵ�list�����
*/
void ListDG::linkLast(ENode *list, ENode *node)
{
	ENode *p = list;

	while (p->nextEdge)
		p = p->nextEdge;
	p->nextEdge = node;
}


/*
* ����ch��λ��
*/
int ListDG::getPosition(char ch)
{
	int i;
	for (i = 0; i<mVexNum; i++)
	if (mVexs[i].data == ch)
		return i;
	return -1;
}

/*
* ��ȡһ�������ַ�
*/
char ListDG::readChar()
{
	char ch;

	do {
		cin >> ch;
	} while (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')));

	return ch;
}


/*
* ���������������ͼ�ĵݹ�ʵ��*****************************************************************
*/
void ListDG::DFS(int i, int *visited)
{
	ENode *node;

	visited[i] = 1;
	cout << mVexs[i].data << " ";
	node = mVexs[i].firstEdge;
	while (node != NULL)
	{
		if (!visited[node->ivex])
			DFS(node->ivex, visited);
		node = node->nextEdge;
	}
}

/*
* ���������������ͼ
*/
void ListDG::DFS()
{
	int i;
	int *visited;       // ������ʱ��

	visited = new int[mVexNum];
	// ��ʼ�����ж��㶼û�б�����
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "== DFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;

	delete[] visited;
}

/*
* ����������������������Ĳ�α�����************************************************************
*/
void ListDG::BFS()
{
	int head = 0;
	int rear = 0;
	int *queue;     // �������
	int *visited;   // ������ʱ��
	int i, j, k;
	ENode *node;

	queue = new int[mVexNum];
	visited = new int[mVexNum];
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "== BFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << mVexs[i].data << " ";
			queue[rear++] = i;  // �����
		}
		while (head != rear)
		{
			j = queue[head++];  // ������
			node = mVexs[j].firstEdge;
			while (node != NULL)
			{
				k = node->ivex;
				if (!visited[k])
				{
					visited[k] = 1;
					cout << mVexs[k].data << " ";
					queue[rear++] = k;
				}
				node = node->nextEdge;
			}
		}
	}
	cout << endl;

	delete[] visited;
	delete[] queue;
}

/*
* ��ӡ�ڽӱ�ͼ
*/
void ListDG::print()
{
	int i, j;
	ENode *node;

	cout << "== List Graph:" << endl;
	for (i = 0; i < mVexNum; i++)
	{
		cout << i << "(" << mVexs[i].data << "): ";
		node = mVexs[i].firstEdge;
		while (node != NULL)
		{
			cout << node->ivex << "(" << mVexs[node->ivex].data << ") ";
			node = node->nextEdge;
		}
		cout << endl;
	}
}

/*
* ��������*********************************************************************************
******************************************************************************************
* ����ֵ��
*     -1 -- ʧ��(�����ڴ治���ԭ����)
*      0 -- �ɹ����򣬲�������
*      1 -- ʧ��(������ͼ���л���)
*/
int ListDG::topologicalSort()
{
	int i, j;
	int index = 0;
	int head = 0;           // �������е�ͷ
	int rear = 0;           // �������е�β
	int *queue;             // �������
	int *ins;               // �������
	char *tops;             // �������������飬��¼ÿ���ڵ����������š�
	ENode *node;

	ins = new int[mVexNum];
	queue = new int[mVexNum];
	tops = new char[mVexNum];
	memset(ins, 0, mVexNum*sizeof(int));
	memset(queue, 0, mVexNum*sizeof(int));
	memset(tops, 0, mVexNum*sizeof(char));

	// ͳ��ÿ������������
	for (i = 0; i < mVexNum; i++)
	{
		node = mVexs[i].firstEdge;
		while (node != NULL)
		{
			ins[node->ivex]++;
			node = node->nextEdge;
		}
	}

	// ���������Ϊ0�Ķ��������
	for (i = 0; i < mVexNum; i++)
	if (ins[i] == 0)
		queue[rear++] = i;          // �����

	while (head != rear)                // ���зǿ�
	{
		j = queue[head++];              // �����С�j�Ƕ�������
		tops[index++] = mVexs[j].data;  // ���ö�����ӵ�tops�У�tops��������
		node = mVexs[j].firstEdge;      // ��ȡ�Ըö���Ϊ���ĳ��߶���

		// ����"node"�����Ľڵ����ȼ�1��
		// ����1֮�󣬸ýڵ�����Ϊ0���򽫸ýڵ���ӵ������С�
		while (node != NULL)
		{
			// ���ڵ�(���Ϊnode->ivex)����ȼ�1��
			ins[node->ivex]--;
			// ���ڵ�����Ϊ0������"�����"
			if (ins[node->ivex] == 0)
				queue[rear++] = node->ivex;  // �����

			node = node->nextEdge;
		}
	}

	if (index != mVexNum)
	{
		cout << "Graph has a cycle" << endl;
		delete queue;
		delete ins;
		delete tops;
		return 1;
	}

	// ��ӡ����������
	cout << "== TopSort: ";
	for (i = 0; i < mVexNum; i++)
		cout << tops[i] << " ";
	cout << endl;

	delete queue;
	delete ins;
	delete tops;

	return 0;
}

int main()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	char edges[][2] = {
		{ 'A', 'G' },
		{ 'B', 'A' },
		{ 'B', 'D' },
		{ 'C', 'F' },
		{ 'C', 'G' },
		{ 'D', 'E' },
		{ 'D', 'F' } };
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	int elen = sizeof(edges) / sizeof(edges[0]);
	ListDG* pG;

	// �Զ���"ͼ"(����������)
	//pG = new ListDG();
	// �������е�"ͼ"
	pG = new ListDG(vexs, vlen, edges, elen);

	pG->print();   // ��ӡͼ
	//pG->DFS();     // ������ȱ���
	//pG->BFS();     // ������ȱ���
	pG->topologicalSort();     // ��������

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
struct node
{
	int v, next;
}edge[maxn*maxn];
int degree[maxn], head[maxn];
queue<int> q;
list<int> ans;
int n, m, no;
inline void init()
{
	no = 0;
	while (!q.empty()) q.pop();
	memset(degree, 0, sizeof degree);
	memset(head, -1, sizeof head);
}
inline void add(int u, int v)
{
	edge[no].v = v;
	edge[no].next = head[u];
	head[u] = no++;
}
int Kahn()
{
	int count = 0;
	while (!q.empty())
	{
		int tp = q.front(); q.pop();
		++count; ans.push_back(tp); //���������У������������vector����queue������ν 
		int k = head[tp];
		while (k != -1)
		{
			--degree[edge[k].v];
			if (!degree[edge[k].v]) q.push(edge[k].v);
			k = edge[k].next;
		}
	}
	if (count == n) return 1;
	return 0;
}
int main()
{
	int u, v;
	scanf("%d %d", &n, &m); init();
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &u, &v);
		add(u, v); ++degree[v];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!degree[i]) q.push(i);
	}
	Kahn();
	list<int>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
/*#include <iostream>
#include <stack>
using namespace std;

struct Edge {
	int to, next;
};

const int maxn = 10010;
int head[maxn] = {};
int n, m, cnt = 1;
bool vis[maxn] = {};
Edge edge[maxn];
stack<int> S;

void add(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int u)
{
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (!vis[v]) dfs(v);
	}
	S.push(u);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0) dfs(i);
	}
	while (!S.empty()) {
		cout << S.top() << ' ';
		S.pop();
	}
}
/*#include<iostream>
using namespace std;
//package ͼ��;

//import java.util.ArrayDeque;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.Queue;
//import java.util.Stack;

public class tuopu {
	static class node
	{
		int value;
		List<Integer> next;
		public node(int value) {
			this.value = value;
			next = new ArrayList<Integer>();
		}
		public void setnext(List<Integer>list) {
			this.next = list;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		node[]nodes = new node[9];//����ڵ�
		int a[] = new int[9];//�������
		List<Integer>list[] = new ArrayList[10];//��ʱ�ռ䣬Ϊ�˴洢ָ��ļ���
		for (int i = 1; i<9; i++)
		{
			nodes[i] = new node(i);
			list[i] = new ArrayList<Integer>();
		}
		initmap(nodes, list, a);

		//��Ҫ����
		//Queue<node>q1=new ArrayDeque<node>();
		Stack<node>s1 = new Stack<node>();
		for (int i = 1; i<9; i++)
		{
			//System.out.print(nodes[i].next.size()+" 55 ");
			//System.out.println(a[i]);
			if (a[i] == 0) { s1.add(nodes[i]); }

		}
		while (!s1.isEmpty())
		{
			node n1 = s1.pop();//�׳����

			System.out.print(n1.value + " ");

			List<Integer>next = n1.next;
			for (int i = 0; i<next.size(); i++)
			{
				a[next.get(i)]--;//��ȼ�һ
				if (a[next.get(i)] == 0)//������Ϊ0
				{
					s1.add(nodes[next.get(i)]);
				}
			}
		}
	}

	private static void initmap(node[] nodes, List<Integer>[] list, int[] a) {
		list[1].add(3);
		nodes[1].setnext(list[1]);
		a[3]++;
		list[2].add(4); list[2].add(6);
		nodes[2].setnext(list[2]);
		a[4]++; a[6]++;
		list[3].add(5);
		nodes[3].setnext(list[3]);
		a[5]++;
		list[4].add(5); list[4].add(6);
		nodes[4].setnext(list[4]);
		a[5]++; a[6]++;
		list[5].add(7);
		nodes[5].setnext(list[5]);
		a[7]++;
		list[6].add(8);
		nodes[6].setnext(list[6]);
		a[8]++;
		list[7].add(8);
		nodes[7].setnext(list[7]);
		a[8]++;

	}
}
*/