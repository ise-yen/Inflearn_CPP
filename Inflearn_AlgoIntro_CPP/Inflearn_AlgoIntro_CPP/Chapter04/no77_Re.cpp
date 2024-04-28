#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;

int N{}, M{}; /// �л� ��ȣ, ģ������� ����
int t1{}, t2{};
string answer;

vector<int> friends[MAX];

int unf[MAX]; // ���� ��ȣ

/// v�� ���� ��ȣ ã��
int Find(int v) {
	// �ڱ��ڽ��� ���չ�ȣ��� �ڱ��ڽ��� ����
	if (v == unf[v]) return v;
	
	// �ڱ��ڽ� ���ڿ� �ٸ� ���չ�ȣ �Ҽ��̶�� : ��� Ž��
	unf[v] = Find(unf[v]); // �޸������̼� + ���
	return unf[v];
}

/// a�� b�� ���� �������� ����
void Union(int a, int b) {
	// ���չ�ȣ Ž��
	a = Find(a); // a�� ���չ�ȣ
	b = Find(b); // b�� ���չ�ȣ

	// ���� ������ �ƴϸ� �������� ��ġ��
	if (a != b) unf[a] = b;
}

void MakeFriend() {
	// ģ���� �ֵ� �Է�
	for (int i = 0; i < M; i++) {
		int a{}, b{};
		cin >> a >> b;
		Union(a, b); // a�� b�� ģ���ϱ� ���� ��������
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		unf[i] = i; // �ڱ� ��ȣ�� �ʱ�ȭ
	}

	MakeFriend();

	int a{}, b{};
	cin >> a >> b;
	if (Find(a) == Find(b)) answer = "YES";
	else answer = "NO";

	cout << answer;
	return 0;
}




/*
i =  1 2 3 4 5 6 7 8 9
unf: 5 5 5 5 5 9 9 9 9

1=1=2 2=2
2=2=3 3=3
3=3=4 4=4
4=4=5 5=5
6=6=7 7=7
7=7=8 8=8
8=8=9 9=9
3=4=5 8=9
 */