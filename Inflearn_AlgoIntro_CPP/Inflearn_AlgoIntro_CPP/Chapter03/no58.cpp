// ���� ��ü ���� : ���� Ʈ�� ��ȸ(no.1991)

#include <iostream>
#include <vector>

using namespace std;

int cnt{};

int findPos(char c, vector<pair<char, pair<char, char>>>* v) {
	for (int i = 0; i < v->size(); i++) {
		if (v->at(i).first == c) return i;
	}
	return -1;
}

// ���� ��ȸ
void preorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;

	cout << v->at(pos).first; // Ž�� ��ġ ���
	if (v->at(pos).second.first != '.') preorder(v, findPos(v->at(pos).second.first, v)); // ����(��) ��� Ž��
	if (v->at(pos).second.second != '.') preorder(v, findPos(v->at(pos).second.second, v)); // ����(��) ��� Ž��
}

void inorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;

	if (v->at(pos).second.first != '.') inorder(v, findPos(v->at(pos).second.first, v)); // ����(��) ��� Ž��
	cout << v->at(pos).first; // Ž�� ��ġ ���
	if (v->at(pos).second.second != '.') inorder(v, findPos(v->at(pos).second.second, v)); // ����(��) ��� Ž��
}

void postorder(vector<pair<char, pair<char, char>>>* v, int pos) {
	cnt--;
	if (cnt < 0) return;

	if (v->at(pos).second.first != '.') postorder(v, findPos(v->at(pos).second.first, v)); // ����(��) ��� Ž��
	if (v->at(pos).second.second != '.') postorder(v, findPos(v->at(pos).second.second, v)); // ����(��) ��� Ž��
	cout << v->at(pos).first; // Ž�� ��ġ ���
}

int main() {
	int N{}, pos{};
	cin >> N;
	vector<pair<char, pair<char, char>>> v; // �θ� ���, ���� ���, ������ ���

	// �Է�
	for (int i = 0; i < N; i++) {
		char node{}, left{}, right{};
		cin >> node >> left >> right;
		v.push_back({ node, {left, right}});
		if (node == 'A') pos = i;
	}

	cnt = N;
	preorder(&v, pos);

	cout << "\n";
	cnt = N;
	inorder(&v, pos);

	cout << "\n";
	cnt = N;
	postorder(&v, pos);

	return 0;
}