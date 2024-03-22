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

int main() {
	cin >> N >> M;

	myCode_Linked();

	cout << answer;

	return 0;
}

