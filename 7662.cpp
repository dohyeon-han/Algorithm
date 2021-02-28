#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	map<int, int> m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int k;
		m.clear();
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int num;
			char c;
			cin >> c >> num;
			if (c == 'I') {
				m[num]++;//key = num, value++;
			}
			else {
				if (m.empty()) continue;
				if (num == -1) {
					if (m.begin()->second == 1) {
						m.erase(m.begin());
					}
					else {
						m.begin()->second--;
					}
				}
				else {
					if (prev(m.end())->second == 1) {
						m.erase(prev(m.end()));
					}
					else {
						prev(m.end())->second--;
					}
				}
			}
		}
		if (m.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << prev(m.end())->first << ' ' << m.begin()->first << '\n';
		}
	}
	

	//for (int i = 0; i < t; i++)
	//{
	//	int n, cnt = 0;
	//	priority_queue<long long> max_pq;
	//	priority_queue<long long,vector<long long>,greater<long long>> min_pq;
	//	map<long long, long long> m;

	//	cin >> n;
	//	for (int j = 0; j < n; j++)
	//	{
	//		char c;
	//		long long num;
	//		cin >> c >> num;

	//		if (c == 'I') {
	//			max_pq.push(num);
	//			min_pq.push(num);
	//			m[num]++;
	//			cnt++;
	//		}
	//		else {
	//			if (cnt == 0) {//√ ±‚»≠
	//				priority_queue<long long> max_empty;
	//				priority_queue<long long, vector<long long>, greater<long long>> min_empty;
	//				max_pq = max_empty;
	//				min_pq = min_empty;
	//				continue;
	//			}
	//			if (num == 1) {
	//				while (!m.empty()) {
	//					if (m[max_pq.top()] != 0) {
	//						break;
	//					}
	//					max_pq.pop();
	//				}
	//				m[max_pq.top()]--;
	//				max_pq.pop();
	//			}
	//			else {
	//				while (1) {
	//					if (m[min_pq.top()] != 0) {
	//						break;
	//					}
	//					min_pq.pop();
	//				}
	//				m[min_pq.top()]--;
	//				min_pq.pop();
	//			}
	//			cnt--;
	//		}
	//	}
	//	while (1) {
	//		if (m[max_pq.top()] != 0) {
	//			break;
	//		}
	//		max_pq.pop();
	//	}
	//	while (1) {
	//		if (m[min_pq.top()] != 0) {
	//			break;
	//		}
	//		min_pq.pop();
	//	}
	//	m[max_pq.top()]--;
	//	max_pq.pop();
	//	if (cnt == 0) {
	//		cout << "EMPTY\n";
	//	}
	//	else {
	//		cout << max_pq.top() << ' ' << min_pq.top() << '\n';
	//	}
	//}
}
