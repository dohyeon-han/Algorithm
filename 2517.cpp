//현재 위치에서 자신보다 능력치가 낮은 앞쪽의 모든 사람 수 구하기
//좌표 축소 후
//세그먼트 트리를 이용한 부분합 계산
#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[500001];//현재 등수, 능력
int tree[4 * 500001] = {};

bool cmpAb(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}
bool cmpRank(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

//부분합 구하기
int solve(int start, int end, int left, int right, int idx) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return solve(start, mid, left, right, idx * 2) + solve(mid + 1, end, left, right, idx * 2 + 1);
}

//세그먼트 트리 업데이트
void update(int start, int end, int now, int idx) {
	if (idx < start || end < idx) return;
	tree[now]++;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, now * 2, idx);
	update(mid + 1, end, now * 2 + 1, idx);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i].first = i;
		cin >> arr[i].second;
	}
	sort(arr, arr + n, cmpAb);
	//좌표 축소
	for (int i = 0; i < n; i++)
	{
		arr[i].second = i;
	}
	sort(arr, arr + n, cmpRank);
	for (int i = 0; i < n; i++)
	{
		int front = solve(0, n, 0, arr[i].second, 1);
		cout << 1 + i - front << '\n';
		update(0, n, 1, arr[i].second);
	}
}