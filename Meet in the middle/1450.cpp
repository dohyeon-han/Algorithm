#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, arr[31];
long long rst = 0;
vector<long long> leftWei;

void upper(long long sum) {
	int start = 0, end = leftWei.size();
	while (start < end) {
		int mid = (start + end) / 2;
		if (leftWei[mid] + sum > c ) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	rst += end;
}

void left(int idx, long long sum) {
	if (idx != n / 2) {
		left(idx + 1, sum);

		if(sum+arr[idx]<=1000000000)
			left(idx + 1, sum + arr[idx]);
	}
	else {
		leftWei.push_back(sum);
	}
}

void right(int idx, long long sum) {
	if (idx != n) {
		right(idx + 1, sum);

		if (sum + arr[idx] <= 1000000000)
			right(idx + 1, sum + arr[idx]);
	}
	else {
		upper(sum);
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	left(0, 0);
	sort(leftWei.begin(), leftWei.end());
	right(n / 2, 0);

	cout << rst;
}