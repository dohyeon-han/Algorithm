#include<iostream>
#include<vector>
using namespace std;

//재귀 전위를 받아 트리를 만들고 후위를 출력

struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

vector<Node*> v;

void insert(Node* par, int now) {
	if (par->data > v[now]->data) {
		if (par->left == NULL) {
			par->left = v[now];
		}
		else insert(par->left, now);
	}
	else {
		if (par->right == NULL) {
			par->right = v[now];
		}
		else insert(par->right, now);
	}
}

void print(Node* n) {
	if (n->left != NULL)
		print(n->left);
	if (n->right != NULL)
		print(n->right);

	cout << n->data << '\n';
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int data;
	while (true) {
		cin >> data;
		if (cin.eof()) {
			break;
		}
		Node* n = new Node();
		n->data = data;
		v.push_back(n);
	}
	for (int i = 1; i < v.size(); i++)
	{
		insert(v[0],i);
	}
	print(v[0]);
}