#include <iostream>
#include <queue>
using namespace std;

//dfs
//queue�� *2,+1,-1�� ��츦 ����, pop������ now�� hide�� ������ �Ÿ�cnt ���
//0������ �ȵǴ� �� �˰� ���;;
struct S {
	int now, hide, cnt;
};

int visit[100002];
queue<S> q;

void search(queue<S> q) {//�ش� �迭������ �ִ� �ð� ����
	while (!q.empty()) {
		S s = q.front(); q.pop();

		if (s.now < 0 || s.now>100000) continue;
		if (visit[s.now] != -1) continue;
		if (s.now == s.hide){//dfs�̹Ƿ� ���� ���� ���� ���� ���� ����
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
	search(q);//now->hide�ΰ��� �ִܽð�
}