

#pragma once

#include<iostream>
#include<string>
using namespace std;

/*
���õ��ڽӾ������洢ͼ
*/
//��¼��㵽ÿ����������·������Ϣ
struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG {
private:
	int vexnum;   //ͼ�Ķ������
	int edge;     //ͼ�ı���
	int **arc;   //�ڽӾ���
	Dis * dis;   //��¼�����������·������Ϣ
public:
	//���캯��
	Graph_DG(int vexnum, int edge);
	//��������
	~Graph_DG();
	// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
	//�����1��ʼ���
	bool check_edge_value(int start, int end, int weight);
	//����ͼ
	void createGraph();
	//��ӡ�ڽӾ���
	void print();
	//�����·��
	void Dijkstra(int begin);
	//��ӡ���·��
	void print_path(int);
};
