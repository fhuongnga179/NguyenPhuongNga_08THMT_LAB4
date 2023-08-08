// 0850080033_NguyenPhuongNga_08THMT
using namespace std;
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

// ==========================================================
// 1
bool laSoNguyenTo(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num <= 3)
    {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
// 2
void processArray(int arr[], int &size, int x)
{
    bool found = false;
    int count = 0;
    int newSize = 0;

    // Tìm x và đếm
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == x)
        {
            found = true;
            count++;
        }
        else
        {
            arr[newSize] = arr[i]; // Giữ lại các phần tử khác x
            newSize++;
        }
    }

    if (found)
    {
        cout << x << " có trong mảng A." << endl;
        cout << "Số lần xuất hiện của " << x << " trong mảng A là: " << count << endl;
        cout << "Đã xoá toàn bộ các phần tử " << x << " khỏi mảng A." << endl;
    }
    else
    {
        cout << x << " không có trong mảng A." << endl;
    }

    size = newSize;
}

// ===========================================================
int main()
{
    cout << "Nhập câu hỏi của bài LAB4?" << endl;

    cout << "1. Nhập mảng số nguyên n<=100 " << endl;
    cout << "2. Nhập mảng số nguyên A và một số nguyên x" << endl;
    cout << "3. Nhập số a và sắp xếp theo thứ tự  giảm dần " << endl;

    cout << "Số nhập là: ";

    int n;
    cin >> n;
    switch (n)
    {
        // =========================================
    case 1:
    {
        int n;
        cout << "Nhap vao so n: ";
        cin >> n;

        int soAm = 0;
        int soDuong = 0;
        int tongSoAm = 0;
        int tongSoDuong = 0;
        int soNguyenTo[100];
        int demSoNguyenTo = 0;
        int soChan[100];
        int demSoChan = 0;

        for (int i = n; i >= 0; --i)
        {
            if (i < 0)
            {
                tongSoAm += i;
                ++soAm;
            }
            else if (i > 0)
            {
                tongSoDuong += i;
                ++soDuong;
            }

            if (laSoNguyenTo(i))
            {
                soNguyenTo[demSoNguyenTo] = i;
                ++demSoNguyenTo;
            }

            if (i % 2 == 0)
            {
                soChan[demSoChan] = i;
                ++demSoChan;
            }
        }

        if (soAm > 0)
        {
            double tbCongSoAm = static_cast<double>(tongSoAm) / soAm;
            cout << "Trung bình cộng số âm: " << tbCongSoAm << endl;
        }
        else
        {
            cout << "Không có số âm." << endl;
        }

        if (soDuong > 0)
        {
            double tbCongSoDuong = static_cast<double>(tongSoDuong) / soDuong;
            cout << "Trung bình cộng số dương: " << tbCongSoDuong << endl;
        }
        else
        {
            cout << "KKhông có số dương." << endl;
        }

        cout << "Các số nguyên tố có trong mảng: ";
        for (int i = 0; i < demSoNguyenTo; ++i)
        {
            cout << soNguyenTo[i] << " ";
        }
        cout << endl;

        sort(soChan, soChan + demSoChan);
        cout << "Các số chẵn trong mảng khi sắp xếp tăng dần: ";
        for (int i = 0; i < demSoChan; ++i)
        {
            cout << soChan[i] << " ";
        }
        cout << endl;

        break;
    }

    case 2:
    {
        const int maxSize = 100;
        int arr[maxSize];
        int size, x;
        cout << "Nhập số phần tử của mảng: ";
        cin >> size;
        cout << "Nhập mảng số nguyên A: ";
        for (int i = 0; i < size; ++i)
        {
            cin >> arr[i];
        }
        cout << "Nhập số nguyên x: ";
        cin >> x;
        processArray(arr, size, x);
        cout << "Mảng A sau khi xử lý:";
        for (int i = 0; i < size; ++i)
        {
            cout << " " << arr[i];
        }
        break;
    }
    case 3:
    {
        const int maxSize = 100; // Số lượng phần tử tối đa
        int arr[maxSize];
        int n;

        cout << "Nhập số lượng phần tử (tối đa " << maxSize << "): ";
        cin >> n;

        if (n < 1 || n > maxSize)
        {
            cout << "Số lượng phần tử không hợp lệ!" << endl;
            return 1; // Trả về mã lỗi
        }

        cout << "Nhập các phần tử:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        cout << "Mảng sau khi sắp xếp giảm dần:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        break;
    }
    default:
    {
        cout << "Không có bài tập";
        break;
    }
    }
}
