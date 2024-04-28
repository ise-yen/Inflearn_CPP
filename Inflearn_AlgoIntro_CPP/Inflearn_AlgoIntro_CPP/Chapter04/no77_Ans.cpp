#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;

int N{}, M{};
int t1{}, t2{};
string answer;

vector<int> friends[MAX];

void myCode_Linked() {
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	cin >> t1 >> t2;


	// ������ �´ٸ�
	for (int i = 0; i < friends[t1].size(); i++) {
		if (friends[t1][i] == t2) {
			answer = "YES";
			return;
		}
	}

	// ������ �ƴ϶��
	for (int i = 0; i < friends[t1].size(); i++) {
		int t1_f = friends[t1][i]; // t1�� ģ��
		for (int j = 0; j < friends[t1_f].size(); j++) {
			int f = friends[t1_f][j]; // t1_f�� ģ��
			if (f == t1) continue; // t1�̸� �н�
			auto it = find(friends[t1].begin(), friends[t1].end(), f);
			// t1 ģ�� ��Ͽ� ������
			if (it == friends[t1].end()) {
				friends[t1].push_back(f); // ģ���߰�
			}
		}
	}

	auto it = find(friends[t1].begin(), friends[t1].end(), t2);
	if (it == friends[t1].end()) answer = "NO";
	else answer = "YES";
}

// ������Ұ� ������ ���� ����
// ������ ���μ� ����
// ���� ����� Ʈ���� ǥ��
int unf[MAX]; // ���չ�ȣ. union & find
int Find(int v) { // ���չ�ȣ ã��

	if (v == unf[v]) return v; // �ڱ��ڽ��� ���չ�ȣ��� �ڱ��ڽ��� ����
	else { // �װ� �ƴϸ� ���չ�ȣ ��� Ž��
		unf[v] = Find(unf[v]); // �޸������̼�
		return unf[v];
	}
}

int Union(int a, int b) { // ���� �������� ����
	// ���չ�ȣ Ž��
	a = Find(a);
	b = Find(b);

	// ���չ�ȣ�� ���� �ٸ��ٸ� ���� ���տ� ����
	if (a != b) unf[a] = b;
}

void answerCode() {
	// ���չ�ȣ�� �����ڽ����� �ʱ�ȭ
	// unf[�л���ȣ] = ���չ�ȣ
	for (int i = 1; i <= N; i++) unf[i] = i;

	// ģ�� �Է�
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		Union(a, b); // ģ�������� ���� �������� ����
	}

	cin >> t1 >> t2;
	if (unf[t1] == unf[t2]) answer = "YES";
	else answer = "NO";
}

int main() {
	cin >> N >> M;

	cout << answer;

	return 0;
}

