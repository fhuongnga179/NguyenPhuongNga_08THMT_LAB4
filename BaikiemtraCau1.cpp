#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Nhập số nguyên n (5<n<100): " << endl;
    cin >> n;
    if (n < 5 || n > 100)
    {
        cout << "Nhập n không hơp lệ!" << endl;
        return 1;
    }
    int result = 0;
    int factorial = 1;

    for (int i = 1; i <= n; ++i)
    {
        factorial *= i;
        result += factorial;
    }

    cout << "Giá trị biểu thức s là: " << result << endl;
}
