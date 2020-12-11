/* ����������� �������� ��������� ���� � ������� ������ �����, �� ������� ��������� �� �������� ��������.
��� �������� �����, ������ ��������� ��������� ����� ����� ����� � ������, �����
����������, �� ����� ���� ������� ������������� ����� � ������ ��������� �����.
��� �������� ���� ���������� ������� ������ (����������� ������), � ����� ���� ���������� �������� ������ (������ -��������).

³���������� �������� � ������� ����� �����, �� ������ ���� ������������ � ����-����� ����,
���������� �� ����, �� ���� ���� ��������.
ҳ�� ������ ���� ���������� ����� ������� ��������� � ��������� ����.

³��������� ���������� �� ��������������� ��� ������������� � ��������� ����,
���������� ��� ������� ����������� � ����������������,
� ���� ����������� � ���������� ��������� ����� �� ������� �������� �����
������� ���'����� ��� ���������� ����������� �����������, ����� ���� �� ������� � ����-����� �������� ����,
������� ������� � ����� ���� �������� �������� � ������������, ��������� �� �������������, ���� �� ���� ����������.

����������� ����, �������������, ����, ���� �� ���� ���� ��������� � �������� ���������� �� ����,
���� �� ���� ��� ����� ������ ���������� (�����������) �������.
��� ���������� ����� ��������� ������� ������ ��������� �� ������ ������ "= 0" ���� ���������� �������.

���� ���������� � �������� � ����������� ���� �� ���� ���������. ��� �������� ���������, ���������� ��� ��������� �� ����� ����� ���������� ��� ��� (����) ���������.
�� �������, �� ��������� �� ������� ���� � �������� �����.
ϳ�� ���������� � �������� � ����������� ���� �� ���� ���������.
���� ⳺������ ����� ����������� ������ ���������� ������ (� ��������� ��� virtual, override),
�� ��������� ���� ��� ����� ��� ����������. ��� ������� ��������� ������ ������ ���������� �� ����� ���� �ᒺ���, � �� ���� ��������� �� ������� ����.
ϳ�� ���������� ���������������, ���� ������� ���������� ����������.
*/

#include <iostream>
#include <cmath>

using namespace std;

//virtual method of calculation
class Figure{
public:
    virtual double CalculateArea(){
        return 0;
    }
};

//calculating the area of the circle
class Circle : public Figure{
private:
    double radius;
public:
    explicit Circle(double r){
        if(r > 0){
            this->radius = r;
        }
        else{
            throw "Side must be > 0";
        }
    }

    double CalculateArea() override{
        double pi = 2 * acos(0.0);
        return round((pi * radius * radius * 100) / 100);
    };


};

//calculating the area of the rectangle
class Rectangle : public Figure{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h){
        if(w > 0 && h > 0){
            this->width = w;
            this->height = h;
        }
        else{
            throw "Sides must be > 0";
        }
    }

    double CalculateArea() override{
        return width * height;
    }

};

int main() {
    cout << "Circle1: ";
    double r1;
    cin >> r1;
    cout << endl;
    Circle c1 = Circle(r1);
    cout << "Circle2: ";
    double r2;
    cin >> r2;
    cout << endl;
    Circle c2 = Circle(r2);
    cout << "Circle3: ";
    double r3;
    cin >> r3;
    cout << endl;
    Circle c3 = Circle(r3);
    cout << "Circle4: ";
    double r4;
    cin >> r4;
    cout << endl;
    Circle c4 = Circle(r4);
    cout << "Rectangle: ";
    double w;
    double h;
    cin >> w >> h;
    cout << endl;
    Rectangle rect = Rectangle(w, h);
    double a1 = c1.CalculateArea();
    double a2 = c2.CalculateArea();
    double a3 = c3.CalculateArea();
    double a4 = c4.CalculateArea();
    double a5 = rect.CalculateArea();
    cout << "Summary square: " << a1 + a2 + a3 + a4 + a5 << endl;
    return 0;
}
