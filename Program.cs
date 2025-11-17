using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhuongTrinh
{
    // 1. Lớp Cơ Sở (Base Class): Giải Phương Trình Bậc 1
    public class PhuongTrinhBacMot
    {
        // Phương thức giải PT bậc 1: ax + b = 0. Đặt là protected để chỉ lớp con truy cập.
        protected string GiaiBacMot(double a, double b)
        {
            string format = "F4";

            if (a == 0)
            {
                if (b == 0)
                {
                    return "PT bac 1 vo so nghiem.";
                }
                else
                {
                    return "PT bac 1 vo nghiem.";
                }
            }
            else // Trường hợp a != 0
            {
                double x = -b / a;
                return $"PT bac 1 co nghiem duy nhat: x = {x.ToString(format)}";
            }
        }
    }

    // 2. Lớp Kế Thừa (Derived Class): Giải Phương Trình Bậc 2
    public class PhuongTrinhBacHai : PhuongTrinhBacMot
    {
        // Phương thức giải PT bậc 2: ax^2 + bx + c = 0
        public string Giai(double a, double b, double c)
        {
            string format = "F4";

            // Trường hợp KẾ THỪA: a = 0 (Sử dụng logic từ lớp cha)
            if (a == 0)
            {
                return "=> Do a=0, chuyen thanh PT bac 1. Ket qua: " + base.GiaiBacMot(b, c);
            }

            // Trường hợp PT Bậc 2 (a != 0)
            double delta = b * b - 4 * a * c;

            if (delta < 0)
            {
                return $"PT bac 2 vo nghiem thuc (Delta = {delta.ToString(format)} < 0).";
            }
            else if (delta == 0)
            {
                double x = -b / (2 * a);
                return $"PT bac 2 co nghiem kep: x1 = x2 = {x.ToString(format)}";
            }
            else // delta > 0
            {
                double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
                return $"PT bac 2 co 2 nghiem phan biet: x1 = {x1.ToString(format)}, x2 = {x2.ToString(format)}";
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            PhuongTrinhBacHai ptb2 = new PhuongTrinhBacHai();

            Console.WriteLine("===== CHUONG TRINH GIAI PHUONG TRINH BAC 2 (OOP - C#) =====");

            // Nhập dữ liệu
            double a = NhapHeSo("a");
            double b = NhapHeSo("b");
            double c = NhapHeSo("c");

            // Giải và in kết quả chính
            Console.WriteLine($"\n--- Giai PT: {a}x^2 + {b}x + {c} = 0 ---");
            Console.WriteLine($"Ket qua cuoi cung: {ptb2.Giai(a, b, c)}");

            Console.WriteLine("\n--- KIEM TRA TINH KE THUA (a=0) ---");

            // Kiem tra ke thua (a=0, 2x - 4 = 0 => x=2)
            Console.WriteLine($"PT (0, 2, -4): {ptb2.Giai(0, 2, -4)}");

            // Kiem tra ke thua (a=0, 0x + 5 = 0 => Vo nghiem)
            Console.WriteLine($"PT (0, 0, 5): {ptb2.Giai(0, 0, 5)}");

            Console.ReadKey();
        }

        // Hàm hỗ trợ nhập số
        static double NhapHeSo(string tenHeSo)
        {
            double so;
            Console.Write($"Nhap he so {tenHeSo}: ");
            while (!double.TryParse(Console.ReadLine(), out so))
            {
                Console.Write("Nhap khong hop le. Vui long nhap lai so: ");
            }
            return so;
        }
    }
}
