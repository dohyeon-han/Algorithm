#include <iostream>
#include <vector>
using namespace std;
//식은 간단하지만 dp는 어렵다,,,

//Knapsack
//각 무게별로 최적의 해를 한 물건씩 돌아가며 업데이트
//O(n*k) 무게*물건

int main() {
	cin.tie(NULL);
	cout.tie(NULL);	
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> dp(k+1);
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;//무게, 가치

		for (int j = k; j >= w; j--) {//최대무게~현재무게
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}