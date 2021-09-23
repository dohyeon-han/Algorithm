#include <iostream>
#include <algorithm>
using namespace std;

int n, s, arr[41] = {}, lsum[4000001] = {};
long long rst = 0;

void left(int idx, int sum) {
	if (idx != n / 2) {
		left(idx+1, sum);
		left(idx + 1, sum + arr[idx]);
	}
	else {
		lsum[sum + 2000000]++;
	}
}

void right(int idx, int sum) {
	if (idx != n) {
		right(idx + 1, sum);
		right(idx + 1, sum + arr[idx]);
	}
	else {
		int f = s - sum + 2000000;
		if (f < 0 || f > 4000000) return;
		rst += lsum[f];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	left(0, 0);
	right(n / 2, 0);
	if (s == 0)rst--;
	cout << rst;
}