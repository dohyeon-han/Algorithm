#include<iostream>
#include<algorithm>
using namespace std;

//Kruskal's 알고리즘
//기본적으로 유니온 파인트 형태
//거리가 작은 순으로 정렬 후 
//union find를 통해 같은 부모(노드)가 나오면 순환이 되므로 건너뜀
struct S {
	int from, to, dist;
};

int v, e, parent[100001], rst = 0;
S arr[100001];

bool cmp(S a, S b) {
	return a.dist < b.dist;
}
int find(int node) {//트리의 최상위 노드 찾기
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void uni(int from, int to, int dist) {//union 순환 판별
	from = find(from);
	to = find(to);

	if (from == to) return;//순환 발생
	parent[from] = to;
	rst += dist;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> v >> e;

	S s;
	for (int i = 0; i < e; i++)
	{
		cin >> s.from >> s.to >> s.dist;
		arr[i] = s;
	}
	sort(arr, arr + e, cmp);
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		uni(arr[i].from, arr[i].to, arr[i].dist);
	}
	cout << rst;
}