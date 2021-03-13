#include <iostream>
#include <vector>
using namespace std;
//���� ���������� dp�� ��ƴ�,,,

//Knapsack
//�� ���Ժ��� ������ �ظ� �� ���Ǿ� ���ư��� ������Ʈ
//O(n*k) ����*����

int main() {
	cin.tie(NULL);
	cout.tie(NULL);	
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> dp(k+1);
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;//����, ��ġ

		for (int j = k; j >= w; j--) {//�ִ빫��~���繫��
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}