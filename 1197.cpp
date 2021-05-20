#include<iostream>
#include<algorithm>
using namespace std;

//Kruskal's �˰���
//�⺻������ ���Ͽ� ����Ʈ ����
//�Ÿ��� ���� ������ ���� �� 
//union find�� ���� ���� �θ�(���)�� ������ ��ȯ�� �ǹǷ� �ǳʶ�
struct S {
	int from, to, dist;
};

int v, e, parent[100001], rst = 0;
S arr[100001];

bool cmp(S a, S b) {
	return a.dist < b.dist;
}
int find(int node) {//Ʈ���� �ֻ��� ��� ã��
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}

void uni(int from, int to, int dist) {//union ��ȯ �Ǻ�
	from = find(from);
	to = find(to);

	if (from == to) return;//��ȯ �߻�
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