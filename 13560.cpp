#include <iostream>
#include <algorithm>
using namespace std;

//랑주의 정리?
//i개의 팀의 경기 수의 합은 iC2 이상이어야 한다.
//모든 경기 수의 합은 nC2 이다.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, arr[10001], sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum < (i+1) * i / 2) {
			cout << "-1";
			return 0;
		}

	}
	cout << (sum == n * (n - 1) / 2 ? "1" : "-1");
}