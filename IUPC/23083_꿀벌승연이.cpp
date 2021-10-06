#include <iostream>
#include <cstring>
#define DIV 1000000007
using namespace std;

// DP
// 갈 수 있는 모든 경로의 합

int n, m, k;
long long arr[1002][1002];

long long solve(int y, int x) {
	if (y > n || x > m || y <= 0) return 0;
	if (y == n && x == m) return 1;
	if (arr[y][x] != -1) return arr[y][x];

	long long ret = 0;
	if (x % 2 == 1)
		ret = (ret + solve(y - 1, x + 1)) % DIV;
	
	else 
		ret = (ret + solve(y + 1, x + 1)) % DIV;
	
	ret = (ret + solve(y, x + 1)) % DIV;
	ret = (ret + solve(y + 1, x)) % DIV;

	return arr[y][x] = ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	memset(arr, -1, sizeof(arr));
	for (size_t i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 0;
	}
	cout << solve(1, 1);
}
