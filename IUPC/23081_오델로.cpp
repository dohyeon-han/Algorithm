#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 모든 .을 검색
// 재귀 함수로 검은 돌이 나올 때까지 찾고
// 검은 돌이 있다면 return 하면서 cnt의 개수를 늘린다.

int n, cnt, rst = 0, rx, ry;
pair<int, int > dir[8] = { {1,0},{1,1},{0,1},{-1,1}, {-1,0},{-1,-1}, {0,-1},{1,-1} };
char arr[501][501];
queue<pair<int, int>> q;

bool chk(int y, int x, int d) {
	if (y < 0 || x < 0 || y >= n || x >= n) return false;
	if (arr[y][x] == '.') return false;
	if (arr[y][x] == 'B') return true;

	//W
	if (chk(y + dir[d].first, x + dir[d].second, d)) {
		cnt++;
		return true;
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '.') q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt = 0;
		for (size_t i = 0; i < 8; i++)
		{
			chk(y + dir[i].first, x + dir[i].second, i);
		}
		if (cnt > rst) {
			rx = x;
			ry = y;
			rst = cnt;
		}
	}
	if (rst == 0) cout << "PASS";
	else cout << rx << ' ' << ry << '\n' << rst;
}