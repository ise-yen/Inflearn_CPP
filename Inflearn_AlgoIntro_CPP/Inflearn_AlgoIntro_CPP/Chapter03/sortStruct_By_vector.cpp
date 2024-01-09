#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Loc {
	int x, y, z;

	// ������ : ������ �̸��� �Ȱ��� ����Լ�
	Loc(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}

	// ������ �����ε�
	// const (call by reference) : ���� ���輺�� �����
	// operator () const : ��� �Լ�
	// return x < b.x; ��������
	// return x > b.x; ��������
	//bool operator < (const Loc &b) const {
	//	return x < b.x;
	//}

	bool operator < (const Loc& b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		if (z != b.z) return z < b.z;
	}
};

int main() {
	vector<Loc> XY;
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));

	// ���� ��
	for (const Loc& pos : XY)
		cout << pos.x << " " << pos.y << " " << pos.z << "\n";
	cout << "\n";

	//  ����
	sort(XY.begin(), XY.end());
	for (const Loc& pos : XY)
		cout << pos.x << " " << pos.y << " " << pos.z << "\n";
	cout << "\n";

	return 0;
}
