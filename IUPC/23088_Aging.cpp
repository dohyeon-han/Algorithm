#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 실행이 끝나는 시간(now) < 다음 실행 시간(t)인 경우 
// queue에 있는 프로세스들 실행 후 queue에 삽입
// 아닌 경우 그냥 queue에 삽입

// p-t가 큰 순서로 실행

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