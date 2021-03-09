#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //fill
using namespace std;
//priority_queue를 이용한 다익스트라

int arrDis[20001];//start에서 각 정정까지의 거리 저장
vector<vector<pair<int, int>>> g(20001);//시작 정점, 끝 정점, 거리

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;//정점,거리
	pq.push({ 0, start });//자기 자신
	arrDis[start] = 0;//자기 자신의 거리는 0

	while (!pq.empty()) {
		int dis = -pq.top().fitst;//거리 max힙이므로 마이너스
		int ver = pq.top().second;//정점
		
		pq.pop();

		if (arrDis[ver] < dis) continue;//거리가 기존 거리보다 작아야 함

		for (int i = 0; i < g[ver].size(); i++)
		{
			int newDis = g[ver][i].second + dis;//비교할 거리
			int& exist = arrDis[g[ver][i].first];//기존 거리
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