#include <iostream>
#include <string>
using namespace std;

//LSC
//������ ���ڰ� ����� �밢�� �밢�������� �� +1
//�ٸ��� ��,���� �� �� ū ��

int arr[1002][1002];

int main() {
	string a, b;
	cin >> a >> b;

	int aLen = a.size();
	int bLen = b.size();

	for (int i = 0; i < aLen; i++)
	{
		for (int j = 0; j < bLen; j++)
		{
			if (a[i] == b[j]) {
				arr[i + 1][j + 1] = arr[i][j]+1;
			}
			else {
				arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);
			}
		}
	}

	//LCS ���ϱ�
	//���������� ����� �ݴ��, �밢�� ���� �۾����� ���� �߰�
	/*int tmp1 = arr[a.size()][b.size()];
	int tmp2 = tmp1 - 1;

	string rst = "";
	for (int i = a.size(); i >0 ; i--)
	{
		for (int j = b.size(); j > 0; j--)
		{
			if (arr[i][j] == tmp1 && arr[i - 1][j] == tmp2 && arr[i - 1][j - 1] == tmp2 && arr[i][j - 1] == tmp2) {
				rst = a[i-1]+rst;
				tmp1--;
				tmp2--;
				i--;
			}
		}
	}*/

	cout << arr[aLen][bLen];
}