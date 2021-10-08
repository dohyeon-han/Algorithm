#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// ������ ������ �ð�(now) < ���� ���� �ð�(t)�� ��� 
// queue�� �ִ� ���μ����� ���� �� queue�� ����
// �ƴ� ��� �׳� queue�� ����

// p-t�� ū ������ ����

priority_queue<tuple<int,int,int>> pq;
int n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int now = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, p, b;
		cin >> t >> p >> b;
		while (!pq.empty() && now < t) {
			cout << -get<2>(pq.top()) << ' ';
			now += -get<1>(pq.top());
			pq.pop();
		}
		pq.push({ p - t,-b,-i });
		if (now < t) now = t;
	}
	while (!pq.empty()) {
		cout << -get<2>(pq.top()) << ' ';
		pq.pop();
	}
}