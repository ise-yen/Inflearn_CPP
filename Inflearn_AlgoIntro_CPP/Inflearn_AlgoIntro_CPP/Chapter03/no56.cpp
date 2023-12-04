#include<iostream>

using namespace std;

void Recursive(int n) {
	if (n == 0) return;
	Recursive(n - 1);
	cout << n << " ";
}

int main() {
	int N{};

	cin >> N;

	Recursive(N);
	return 0;
}


/*
< ����� ���� ������ >
���������� : ���α׷��� ����� ��, �Լ��� ȣ��Ǹ� ȣ�� ������ ����ϴ� ��


- ���������� Recursive(int n=0) : �Ű�����, ��������, ������ �ּ�
- ���������� Recursive(int n=1) : �Ű�����, ��������, ������ �ּ�
- ���������� Recursive(int n=2) : �Ű�����, ��������, ������ �ּ�(Recursive(int n=3)���� Recursive(n-1);�� �ۼ��� ��ġ)
- ���������� Recursive(int n=3) : �Ű�����, ��������, ������ �ּ�(main�Լ����� Recursive(N);�� �ۼ��� ��ġ)
- ���������� main() : �Ű�����, ��������, ������ �ּ� ���� ����

*/