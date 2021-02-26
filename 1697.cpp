#include <iostream>
#include <queue>
using namespace std;

//dfs
//queue에 *2,+1,-1의 경우를 저장, pop했을때 now와 hide가 같으면 거리cnt 출력
//0포함이 안되는 줄 알고 헤멤;;
struct S {
	int now, hide, cnt;
};

int visit[100002];
queue<S> q;

void search(queue<S> q) {//해당 배열까지의 최단 시간 저장
	while (!q.empty()) {
		S s = q.front(); q.pop();

		if (s.now < 0 || s.now>100000) continue;
		if (visit[s.now] != -1) continue;
		if (s.now == s.hide){//dfs이므로 가장 먼저 같은 것이 가장 빠름
			cout << s.cnt;
			return;
		}
		visit[s.now] = s.cnt;

		S tmp = s;
		tmp.cnt = s.cnt + 1;
		for (int i = 0; i < 3; i++)
		{
			if (i == 1) {
				tmp.now = s.now * 2;
			}
			else {
				tmp.now = s.now - 1 + i;
			}
			q.push(tmp);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	S s;
	cin >> s.now >> s.hide;
	s.cnt = 0;
	
	for (int i = 0; i <= 100001; i++)
	{
		visit[i] = -1;
	}
	q.push(s);
	search(q);//now->hide로가는 최단시간
}