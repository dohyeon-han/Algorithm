#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define MAX 20000000001 //N*w
#define DIV 1000000009
using namespace std;

// ���ͽ�Ʈ��
// �ִ� �Ÿ�, �뼱 ���� �� ��
// �ִ� �Ÿ�, ���� �뼱�� ���� ����� �� �߰�
//
// ���� �ִܰŸ��� ���� visit�� ��ģ �뼱 ����, ��ġ�� ��� �߰�

int n, m, x, y;
vector<vector<pair<long long, long long>>> v;//���� �뼱, �Ÿ�
vector<tuple<long long,long long,long long>> visit;//�Ÿ�,�뼱 ����,���

void dijkstra() {
	priority_queue<tuple<long long,long long,long long>> pq;
	pq.push({ 0,0,x });
	visit[x] = { 0,0,1 };
	while (!pq.empty()) {
		long long dis = -get<0>(pq.top());//�Ÿ�
		long long cur = -get<1>(pq.top());//���� �뼱
		long long node = get<2>(pq.top());//���� ��
		pq.pop();
		
		// pq�� visit�� ���� �ٸ��� -> �ִ� �Ÿ� or ���� �뼱�� ���ŵǾ���
		if (dis != get<0>(visit[node]) || cur++ != get<1>(visit[node])) continue;

		// ���� ��忡�� ���� ���� ��
		for (size_t i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i].first; 
			long long sum = v[node][i].second + dis;

			long long nsum = get<0>(visit[next]);
			long long ncur = get<1>(visit[next]);
			long long& path = get<2>(visit[next]);

			if (nsum < sum || get<0>(visit[y]) < sum) continue;
			if ((nsum == sum && ncur < cur) || (get<0>(visit[y]) == sum && get<1>(visit[y]) < cur)) continue;

			// ���� ��忡 ���� �������� �� �߰�
			if (nsum == sum && ncur == cur) {
				path = (path + get<2>(visit[node])) % DIV;
				continue;
			}
			visit[next] = { sum,cur,get<2>(visit[node]) };

			// ������
			if (next == y) continue;
			else pq.push({ -sum,-cur,next });
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x >> y;
	
	v.resize(n + 1);
	visit.resize(n + 1);
	for (size_t i = 1; i <= n; i++)
	{
		visit[i] = { MAX,MAX,0 };
	}
	for (size_t i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dijkstra();
	if (get<2>(visit[y]) == 0) cout << -1;	
	else cout << get<0>(visit[y]) << '\n' << get<1>(visit[y]) << '\n' << get<2>(visit[y]);
}