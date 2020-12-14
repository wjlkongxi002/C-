#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include <iostream>
using namespace std;


#define N 9
int x[N];
  int count = 0;

void dump()
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%d", x[i]);
	}
	printf("\n");
}

void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}

void run(int n) {
	int i;
	//int count = 0;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	} 
	for(i = n; i < N; i++) {
			swap(n, i);
			run(n + 1);
			swap(n, i);
		}
	//cout << count << endl;
}

int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	} 
	run(0);
	printf("* Total: %d\n", count);
	//return 0;
}