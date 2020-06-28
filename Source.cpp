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
	for (int i = 0; i < m - 1; i++) { // берем 1 элемент
		int x = 1;
		for (int j = i + 1; j < m; j++) { // берем 2 элемент
			if (a[i] == a[j]) // если они равны , то увеличиваем счетчик х
				x++;
			if (x >= k) { // если счетчик дошел до к, то
				int t = a[i];
				for (int h = i; h < m; h++) { // находим все элементы равные тому, который повтор€етс€ к раз
					if (a[h] == t) {
						l = h;
						while (l < m) { // переносим его в конец
							a[l] = a[l + 1];
							l++;
						}
						m--; // уменьшаем массив
						h--; // возвращаемс€ к предыдущему
					}
				}
				i--;
				break;
			}

		}
		//x = 1; // возвращаем счетчик в начальное положение
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
	cin >> n;//количество элементов
	cin >>k;//сколько повторов исключ€ет
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

