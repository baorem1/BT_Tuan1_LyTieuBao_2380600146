#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

// Dùng namespace std cho code C++ hiện đại, dễ đọc hơn
using namespace std;

// 1. Lớp Cơ Sở (Base Class): Giải Phương Trình Bậc 1
class PhuongTrinhBacMot
{
protected:
    // Phương thức giải PT bậc 1: ax + b = 0
    string Giai(double a, double b)
    {
        stringstream ss;
        ss << fixed << setprecision(4);

        if (a == 0)
        {
            if (b == 0)
            {
                ss << "PT bac 1 vo so nghiem.";
            }
            else
            {
                ss << "PT bac 1 vo nghiem.";
            }
        }
        else
        {
            double x = -b / a;
            ss << "PT bac 1 co nghiem duy nhat: x = " << x;
        }
        return ss.str();
    }
};

// 2. Lớp Kế Thừa (Derived Class): Giải Phương Trình Bậc 2
// Kế thừa công khai (public inheritance)
class PhuongTrinhBacHai : public PhuongTrinhBacMot
{
public:
    // Phương thức giải PT bậc 2: ax^2 + bx + c = 0
    string Giai(double a, double b, double c)
    {
        stringstream ss;
        ss << fixed << setprecision(4);

        ss << "--- Giai PT: " << a << "x^2 + " << b << "x + " << c << " = 0 ---" << endl;

        // Trường hợp KẾ THỪA: a = 0 (Trở thành PT bậc 1)
        if (a == 0)
        {
            // Tái sử dụng phương thức Giai của lớp cha
            // base.Giai trong C++ được thay bằng PhuongTrinhBacMot::Giai(b, c) hoặc chỉ Giai(b, c)
            ss << "=> Do a=0. Chuyen thanh PT bac 1. Ket qua: " << PhuongTrinhBacMot::Giai(b, c);
            return ss.str();
        }

        // Trường hợp PT Bậc 2 (a != 0)
        double delta = b * b - 4 * a * c;

        if (delta < 0)
        {
            ss << "PT bac 2 vo nghiem thuc (Delta = " << delta << " < 0).";
        }
        else if (delta == 0)
        {
            double x = -b / (2 * a);
            ss << "PT bac 2 co nghiem kep: x1 = x2 = " << x;
        }
        else // delta > 0
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            ss << "PT bac 2 co 2 nghiem phan biet: x1 = " << x1 << ", x2 = " << x2;
        }
        return ss.str();
    }
};

// 3. Hàm Main để kiểm tra
int main()
{
    PhuongTrinhBacHai ptb2;
    double a, b, c;

    cout << "===== CHUONG TRINH GIAI PHUONG TRINH BAC 2 (OOP - C++) =====" << endl;

    // Nhập dữ liệu
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    // Giải và in kết quả chính
    cout << ptb2.Giai(a, b, c) << endl;

    cout << "\n--- KIEM TRA TINH KE THUA (a=0) ---" << endl;

    // Kiem tra ke thua (a=0, 2x - 4 = 0 => x=2)
    cout << ptb2.Giai(0, 2, -4) << endl;

    // Kiem tra ke thua (a=0, 0x + 5 = 0 => Vo nghiem)
    cout << ptb2.Giai(0, 0, 5) << endl;

    return 0;
}