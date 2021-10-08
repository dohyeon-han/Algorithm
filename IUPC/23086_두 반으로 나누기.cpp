#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 이분 그래프
// 절교시킬 친구 쌍을 제외한 나머지 그래프를 연결
// bfs로 이분 그래프가 되지 않는다면 -1
// 된다면 절교시킬 친구 쌍을 연결시켰을 때도 이분 그래프가 되는지 비교

int n, m, k, rst[2] = { 0,0 };
bool delChk[200001] = {};
vector<vector<int>> gr;
vector<int> flag, del;
vector<pair<int, int>> order;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	gr.resize(n + 1);
	flag.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		order.push_back({ a,b });
	}

	for (int i = 0; i < k; i++)
	{
		cin >> a;
		del.push_back(a - 1);
		delChk[a - 1] = true;
	}

	for (int i = 0; i < m; i++)
	{
		if (delChk[i]) continue;
		gr[order[i].first].push_back(order[i].second);
		gr[order[i].second].push_back(order[i].first);
	}

	//bfs, 이분 그래프 나누기
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] != 0) continue;
		q.push(i);
		flag[i] = (rst[0] < rst[1] ? -1 : 1);
		while (!q.empty()) {
			int now = q.front();
			flag[now] == -1 ? rst[0]++ : rst[1]++;
			q.pop();
			for (int j = 0; j < gr[now].size(); j++)
			{
				int next = gr[now][j];
				if (flag[next] != 0) {
					if (flag[now] == flag[next]) {//이분 그래프X
						cout << -1;
						return 0;
					}
					continue;
				}
				flag[next] = (flag[now] == 1 ? -1 : 1);
				q.push(next);
			}
		}
	}
	
	// 뒤에서부터 del의 간선 확인하기
	int cnt;
	for (cnt = k-1; cnt >= 0; cnt--)
	{
		pair<int, int> p = order[del[cnt]];
		if (flag[p.first] == flag[p.second]) break;
	}

	if (rst[0] > rst[1]) swap(rst[0], rst[1]);
	cout << cnt + 1 << '\n' << rst[0] << ' ' << rst[1];
}
