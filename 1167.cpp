#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//트리의 지름
//정점 x에서 가장 먼 점 -> y
//y에서 가장 먼 점 ->z
//지름 : y~z의 거리

bool visited[100001] = { false };

void dfs(vector<vector<pair<int, int>>>& tree, int &disMax, int &longestV, int now, int dis) {
	visited[now] = true;
	if (disMax < dis) {
		disMax = dis;
		longestV = now;
	}
	for (int i = 0; i < tree[now].size(); i++)
	{
		if (visited[tree[now][i].first]) continue;
		dfs(tree, disMax, longestV, tree[now][i].first, tree[now][i].second + dis);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int v;
	cin >> v;
	vector<vector<pair<int,int>>> tree(v+1);
	
	for (int i = 1; i <= v; i++)
	{
		int n;
		cin >> n;
		while (true) {
			int o, dis;
			cin >> o;
			if (o == -1) {
				break;
			}
			cin >> dis;

			tree[n].push_back(make_pair(o, dis));
		}
	}
	int disMax = 0,longestV = 0;
	
	dfs(tree, disMax, longestV, 1, 0);//트리,최대거리,최대거리의 정점,시작 정점, 현재 거리
	fill(visited, visited + v + 1, false);
	dfs(tree, disMax, longestV, longestV, 0);
	cout << disMax;
}