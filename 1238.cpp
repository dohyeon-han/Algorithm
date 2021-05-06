#include<iostream>
#include<vector>
#include<queue>
#define MAX 987654321
using namespace std;

int v, e, x;
vector<pair<int,int>> road[1001];//다음 노드, 거리
vector<pair<int, int>> roadRv[1001];//다음 노드, 거리
int d[1001],dRv[1001];

void dijkstra(vector<pair<int,int>> *vec, int *arr) {
	priority_queue<pair<int, int>> pq;//{-지나온 거리,현재 노드}
	pq.push({ 0,x });
	arr[x] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < vec[node].size(); i++)
		{
			int nextNode = vec[node][i].first;
			int nextDist = dist + vec[node][i].second;
			if (arr[nextNode] > nextDist) {
				arr[nextNode] = nextDist;
				pq.push({ -nextDist,nextNode });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> v >> e >> x;

	int a, b, c;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		roadRv[b].push_back({ a,c });
	}
	for (int i = 0; i <= v; i++)
	{
		d[i] = MAX;
		dRv[i] = MAX;
	}
	dijkstra(road,d);
	dijkstra(roadRv,dRv);

	int rst = 0;
	for (int i = 1; i <= v; i++)
	{
		rst = max(rst, d[i] + dRv[i]);
	}
	
	cout << rst;
}