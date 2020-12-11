/* Наслідування дозволяє визначити клас у термінах іншого класу, що полегшує створення та підтримку програми.
При створенні класу, замість написання абсолютно нових членів даних і методів, можна
призначити, що новий клас повинен успадковувати члени і методи існуючого класу.
Цей існуючий клас називається базовим класом (батьківським класом), а новий клас називається похідним класом (класом -нащадком).

Віртуальними методами є функції членів класу, які можуть бути перевизначені в будь-якому класі,
отриманому від того, де вони були оголошені.
Тіло методу потім замінюється новим набором реалізації в похідному класі.

Віртуальний деструктор не перевизначається при перевизначенні в похідному класі,
визначення для кожного деструктора є накопичувальними,
і вони починаються з останнього похідного класу до першого базового класу
важливо пам'ятати про визначення віртуального деструктора, навіть якщо він порожній у будь-якому базовому класі,
оскільки помилка в ньому може створити проблеми з деструктором, створеним за замовчуванням, який не буде віртуальним.

Абстрактний клас, концептуально, клас, який не може бути створений і зазвичай реалізується як клас,
який має одну або більше чистих віртуальних (абстрактних) функцій.
Для позначення чистої віртуальної функції замість реалізації ми просто додаємо "= 0" після оголошення функції.

Раннє зв’язування – пов’язане з формуванням коду на етапі компіляції. При ранньому зв’язуванні, програмний код формується на основі відомої інформації про тип (клас) посилання.
Як правило, це посилання на базовий клас в ієрархії класів.
Пізнє зв’язування – пов’язане з формуванням коду на етапі виконання.
Якщо вієрархії класів зустрічається ланцюг віртуальних методів (з допомогою слів virtual, override),
то компілятор будує так зване пізнє зв’язування. При пізньому зв’язуванні виклик методу відбувається на основі типу об’єкту, а не типу посилання на базовий клас.
Пізнє зв’язування використовується, коли потрібно реалізувати поліморфізм.
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
