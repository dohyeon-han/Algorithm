#include <iostream>
using namespace std;

#define INF 987654321

//�÷��̵� ����
//middle - from - to ����
//from - to - middle �� ��� 125 135 145 ó�� 1->5�� ��� ����� �� ����Ŭ�� �ع����� 1245�� ���� ��� ����� �ȵ�

int rst[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int city, bus;
	cin >> city >> bus;
	
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city ; j++)
		{
			rst[i][j] = INF;
		}
	}

	for (int i = 0; i < bus; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		rst[a][b] = min(t,rst[a][b]);
	}
	
	for (int i = 1; i <= city; i++)//�߰�
	{
		for (int j = 1; j <= city; j++)//��
		{
			if (i == j) continue;
			for (int k = 1; k <= city; k++)//ó��
			{
				if (k == i || k == j) continue;
				if (rst[j][i] + rst[i][k] < rst[j][k]) {
					rst[j][k] = rst[j][i] + rst[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j||rst[i][j]==INF) {//a->a �Ǵ� �� �� ���� ��
				cout << "0 ";
			}
			else cout << rst[i][j] << ' ';
		}
		cout << '\n';
	}
}