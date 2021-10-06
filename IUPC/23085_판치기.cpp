#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;

int n, k,fnt = 0, bk = 0, visit[3001];

void solve() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, fnt });
	visit[fnt] = 0;
	while (!pq.empty()) {
		int cnt = -pq.top().first + 1;
		int f = pq.top().second;
		int b = n - f;
		pq.pop();
		for (int i = 0; i <= k; i++)
		{
			int nf = f - i + (k - i);
			int nb = b - (k - i) + i;
			if (f - i < 0 || b - (k - i) < 0 || f - i + (k - i) == f) continue;
			if (nf < 0 || nf > n || nb < 0 || nb > n) continue;
			if (visit[nf] != MAX) continue;
			visit[nf] = cnt;

			if (nf == 0) return;
			pq.push({ -cnt,nf });
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'H') fnt++;
		else bk++;
	}
	if (fnt == 0) {
		cout << 0;
		return 0;
	}
	for (size_t i = 0; i <= n; i++)
		visit[i] = MAX;
	solve();
	cout << (visit[0] == MAX ? -1 : visit[0]);
}