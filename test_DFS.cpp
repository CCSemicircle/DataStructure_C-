#include<iostream>
#include<string>
#include"DFS.h"

using namespace std;

int main()
{
	// ���������������
	Graphm G(6);

	// ��ʼ��ͼGm
	G.setEdge(1, 2, 10);
	G.setEdge(1, 4, 20);
	G.setEdge(1, 6, 2);
	G.setEdge(2, 1, 10);
	G.setEdge(2, 3, 3);
	G.setEdge(2, 4, 5);
	G.setEdge(3, 2, 3);
	G.setEdge(3, 5, 15);
	G.setEdge(4, 1, 20);
	G.setEdge(4, 2, 5);
	G.setEdge(4, 5, 11);
	G.setEdge(4, 6, 10);
	G.setEdge(5, 3, 15);
	G.setEdge(5, 4, 11);
	G.setEdge(5, 6, 3);
	G.setEdge(6, 1, 2);
	G.setEdge(6, 4, 10);
	G.setEdge(6, 5, 3);

	// �Ӷ���1��ʼ�����������
	DFS(&G, 1);

	//// ���������������
	//Graphl Gl(6);

	//// ��ʼ��ͼGl
	//Gl.setEdge(1, 2, 10);
	//Gl.setEdge(1, 4, 20);
	//Gl.setEdge(1, 6, 2);
	//Gl.setEdge(2, 1, 10);
	//Gl.setEdge(2, 3, 3);
	//Gl.setEdge(2, 4, 5);
	//Gl.setEdge(3, 2, 3);
	//Gl.setEdge(3, 5, 15);
	//Gl.setEdge(4, 1, 20);
	//Gl.setEdge(4, 2, 5);
	//Gl.setEdge(4, 5, 11);
	//Gl.setEdge(4, 6, 10);
	//Gl.setEdge(5, 3, 15);
	//Gl.setEdge(5, 4, 11);
	//Gl.setEdge(5, 6, 3);
	//Gl.setEdge(6, 1, 2);
	//Gl.setEdge(6, 4, 10);
	//Gl.setEdge(6, 5, 3);

	//// �Ӷ���1��ʼ�����������
	//AQueue<int> Q(6);				// ���帨������

	//BFS(&Gl, 1,&Q);

	system("pause");
	return 0;
}