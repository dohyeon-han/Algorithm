#include <iostream>
#include <algorithm>
using namespace std;

//������ ����?
//i���� ���� ��� ���� ���� iC2 �̻��̾�� �Ѵ�.
//��� ��� ���� ���� nC2 �̴�.
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