#include <iostream>
#include <string>

using namespace std;
int partition(string a[], int start, int end) {//return local
	int left = start, right = end, local = start, flag = 0;
	while (flag == 0) {
		while (a[local] <= a[right] && local != right) {
			right -= 1;
		}
		if (local == right)
			flag = 1;
		else if (a[local] > a[right]) {
			swap(a[local], a[right]);
			local = right;
		}
		if (flag == 0) {
			while (a[local] >= a[left] && local != left) {
				left += 1;
			}
			if (local == left)
				flag = 1;
			else if (a[local] < a[left]) {
				swap(a[local], a[left]);
				local = left;
			}
		}
	}
	return local;
}
void quickSort(string a[], int start, int end) {
	if (start < end) {
		int loc = partition(a, start, end);
		quickSort(a, start, loc - 1);
		quickSort(a, loc + 1, end);
	}
}
int main() {
	string arr[1000];
	int count = 0;
	while (cin >> arr[count]) {
		count++;
	}
	quickSort(arr, 0, count - 1);
	cout << arr[0];
	for (int i = 1; i < count; i++) {
		cout << " " << arr[i];
	}
}