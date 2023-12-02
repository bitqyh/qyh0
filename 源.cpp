#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct peak{
	int n = 0;//��ǰ�ڵ�
	int roll[5] = { 0 };//��ǰ����������
	int residue;//ʣ�ඥ����
	int peak_num = 0;// ��ǰ�Ŷ�����
	//int* r;//ʣ���
};//״̬Ϊ����֮��

int MAXpeak = 0;/*��ǰ����Ŷ�����*/
int m[5];
std::queue<peak> clique;//����ģ��

bool constraint(int a/*��ǰ����Ľڵ�*/, vector<vector<int>> g, int t, peak lastp) {//Լ������
	for (int i = 0; i < t; i++) {
		if (lastp.roll[i] == 1) {
			if (g[a][i] != 1) {
				return false;
			}
		}
	}
	return true;
}
bool CostFunction(peak p) {//���ۺ���
	if (p.peak_num + p.residue <= MAXpeak) {
		return false;
	}
	return true;
}
peak UpdateP(peak p, peak lastp, int i, int t) {
	p.n = i;
	p.peak_num = lastp.peak_num + 1;
	p.residue = lastp.residue - 1;
	for (int j = 0; j < t; j++) {
		if (j == i) p.roll[j] = 1;
		else{
			p.roll[j] = lastp.roll[j];
		}
	}

	
	return p;
}

int Maximalclique(int t, vector<vector<int>> g) {
	vector<vector<int>> G = g;
	for (int i = 0; i < t; i++) {
		peak p;
		p.n = i;
		p.peak_num = 1;
		p.residue = t - 1;
		p.roll[0] = 1;

		clique.push(p);//���ڵ����
		while (!clique.empty()) {
			peak pop = clique.front();
			clique.pop();
			for (int j = 0; j < t; j++) {
				if (pop.n == j) continue;

				if (G[pop.n][j] == 1 && constraint(j, g, t, pop)) {
					G[pop.n][j] = 0;
					G[j][pop.n] = 0;
					peak next;
					next = UpdateP(next, pop, j, t);//���½ṹ��
					if (CostFunction(next)) clique.push(next);
					if (next.peak_num > MAXpeak) {
						MAXpeak = next.peak_num;
						copy(begin(next.roll), end(next.roll), begin(m));
					}
					
				}
			}
		}
		
	}
	return MAXpeak;
}
int main(void) {
	int t;
	int vertex;
	cin >> t;
	vector<vector<int>> graph(t, vector<int>(t, 0));//��СΪt*t�Ķ�ά����

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			cin >> vertex;
			graph[i][j] = vertex;
		}
		
	}
	cout << Maximalclique(t, graph) << endl;
	for (int i = 0; i < t; i++) {
		cout << m[i];
	}
}
//5
//0 1 0 1 1
//1 0 1 0 1
//0 1 0 0 1
//1 0 0 0 1
//1 1 1 1 0
