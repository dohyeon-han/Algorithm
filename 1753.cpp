#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //fill
using namespace std;
//priority_queue�� �̿��� ���ͽ�Ʈ��

int arrDis[20001];//start���� �� ���������� �Ÿ� ����
vector<vector<pair<int, int>>> g(20001);//���� ����, �� ����, �Ÿ�

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;//����,�Ÿ�
	pq.push({ 0, start });//�ڱ� �ڽ�
	arrDis[start] = 0;//�ڱ� �ڽ��� �Ÿ��� 0

	while (!pq.empty()) {
		int dis = -pq.top().fitst;//�Ÿ� max���̹Ƿ� ���̳ʽ�
		int ver = pq.top().second;//����
		
		pq.pop();

		if (arrDis[ver] < dis) continue;//�Ÿ��� ���� �Ÿ����� �۾ƾ� ��

		for (int i = 0; i < g[ver].size(); i++)
		{
			int newDis = g[ver][i].second + dis;//���� �Ÿ�
			int& exist = arrDis[g[ver][i].first];//���� �Ÿ�
			if (exist > newDis) {
				exist = newDis;
				pq.push({ -newDis,g[ver][i].first });
			}
		}
	}
}

int main() {
	int v, e, start;
	
	cin >> v >> e >> start;

	fill(arrDis, arrDis + v + 1, 5000000);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++)
	{
		if (arrDis[i] >= 5000000) {
			cout << "INF\n";
		}
		else {
			cout << arrDis[i] << '\n';
		}
	}
}