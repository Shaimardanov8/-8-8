#include <iostream>
#include <ctime>
using namespace std;
void zap(int* a, int n, int from, int to) {
	for (int i = 0; i < n; i++) {
		int x = rand() * rand();
		a[i] = x % (to - from + 1) + from;
	}
	cout<< endl;
}
void sort(int* a, int n, int k) {
	int m = n, l;
	for (int i = 0; i < m - 1; i++) { // ����� 1 �������
		int x = 1;
		for (int j = i + 1; j < m; j++) { // ����� 2 �������
			if (a[i] == a[j]) // ���� ��� ����� , �� ����������� ������� �
				x++;
			if (x >= k) { // ���� ������� ����� �� �, ��
				int t = a[i];
				for (int h = i; h < m; h++) { // ������� ��� �������� ������ ����, ������� ����������� � ���
					if (a[h] == t) {
						l = h;
						while (l < m) { // ��������� ��� � �����
							a[l] = a[l + 1];
							l++;
						}
						m--; // ��������� ������
						h--; // ������������ � �����������
					}
				}
				i--;
				break;
			}

		}
		//x = 1; // ���������� ������� � ��������� ���������
	}
	cout<< endl;
	for (int i = 0; i < m; i++) {
		cout << a[i] << "; ";
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n, k;
	cin >> n;//���������� ���������
	cin >>k;//������� �������� ���������
	if (k == 1) {
		cout <<"0" << endl;
	}
	if (k > 1) {
		int* a = new int[n];
		zap(a, n, -10, 10);
		for (int i = 0; i < n; i++) {
			cout << a[i] << "; ";
		}
		sort(a, n, k);
	}
	
	
}

