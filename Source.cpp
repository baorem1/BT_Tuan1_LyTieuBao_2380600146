#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;


class PhuongTrinhBacMot
{
protected:
  
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

class PhuongTrinhBacHai : public PhuongTrinhBacMot
{
public:
    
    string Giai(double a, double b, double c)
    {
        stringstream ss;
        ss << fixed << setprecision(4);

        ss << "--- Giai PT: " << a << "x^2 + " << b << "x + " << c << " = 0 ---" << endl;

        if (a == 0)
        {
            ss << "=> Do a=0. Chuyen thanh PT bac 1. Ket qua: " << PhuongTrinhBacMot::Giai(b, c);
            return ss.str();
        }

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
        else 
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            ss << "PT bac 2 co 2 nghiem phan biet: x1 = " << x1 << ", x2 = " << x2;
        }
        return ss.str();
    }
};

int main()
{
    PhuongTrinhBacHai ptb2;
    double a, b, c;

    cout << "===== CHUONG TRINH GIAI PHUONG TRINH BAC 2 (OOP - C++) =====" << endl;

    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    cout << ptb2.Giai(a, b, c) << endl;

    cout << "\n--- KIEM TRA TINH KE THUA (a=0) ---" << endl;

    cout << ptb2.Giai(0, 2, -4) << endl;

    cout << ptb2.Giai(0, 0, 5) << endl;

    return 0;
}