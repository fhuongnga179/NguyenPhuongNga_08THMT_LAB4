#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhập số nguyên n (5<n<100): " << endl;
    cin >> n;
    if (n < 5 || n > 100)
    {
        cout << "Nhập n không hơp lệ!" << endl;
        return 1;
    }
    int count = 0;
    int temp = n;

    while (temp > 0) {
        temp /= 10;
        count++;
    }
    cout << "Số lượng chữ số của " << n << " là: " << count << endl;

    return 0;
}
