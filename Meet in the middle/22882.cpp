#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ans, arr[21][21], n, k;
vector<long long> v1[21], v2[21], v3[21], v4[21];

long long count(int idx) {//y가 idx인 중간 지점에서의 최대 부분합 합치기
	//투 포인터
	long long s = 0, e = (long long)v1[idx].size() - 1, ret = 0;
	while (s < v3[idx].size() && e >= 0) {//mx와 pre1+pre2가 k이하인 경로 개수
		if (v1[idx][e] + v3[idx][s] > k) e--;
		else {
			ret += e + 1;
			s++;
		}
	}
	s = 0, e = (long long)v2[idx].size() - 1;
	while (s < v4[idx].size() && e >= 0) {//mx와 pre1+pre2가 k미만인 경로 개수
		if (v2[idx][e] + v4[idx][s] > k - 1) e--;
		else {
			ret -= e + 1;
			s++;
		}
	}
	return ret;
}
void top(int y, int x, long long pre, long long mx) {//(0,0) -> 중간 바로 전까지 최대 부분합
	if (y + x == n - 1) {
		v1[y].push_back(pre);
		if (mx < k)v2[y].push_back(pre);
		return;
	}
	//최대 부분합 계산
	pre = max(pre + arr[y][x], (long long)arr[y][x]);
	if ((mx = max(pre, mx)) > k) return;

	top(y + 1, x, pre, mx);
	top(y, x + 1, pre, mx);
}

void bottom(int y, int x, long long pre, long long mx) {//중간 -> (n-1,n-1)까지 최대 부분합
	//최대 부분합 계산
	pre = max(pre + arr[y][x], (long long)arr[y][x]);
	if ((mx = max(pre, mx)) > k) return;
	if (y + x == n - 1) {
		v3[y].push_back(pre);
		if (mx < k)v4[y].push_back(pre);
		return;
	}

	bottom(y - 1, x, pre, mx);
	bottom(y, x - 1, pre, mx);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	top(0, 0, 0, -1e9);
	bottom(n - 1, n - 1, 0, -1e9);
	for (int i = 0; i < n; i++)
	{
		sort(v1[i].begin(), v1[i].end());
		sort(v2[i].begin(), v2[i].end());
		sort(v3[i].begin(), v3[i].end());
		sort(v4[i].begin(), v4[i].end());
	}
	for (int i = 0; i < n; i++)
		ans += count(i);

	cout << ans;
}