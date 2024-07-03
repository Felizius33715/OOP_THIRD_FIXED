#include <iostream>

class Figure
{
protected:
    std::string name;
    int sides_count;
public:
    Figure() {}
    Figure(int sides_count)
    {
        name = "Figure";
        this->sides_count = sides_count;
    }
    std::string get_name() { return name; }
    int get_sides_count() { return sides_count; }

    virtual void print_info()
    {
        std::cout << get_name() << ":" << std::endl;
        if (check()) { std::cout << "Correct" << std::endl; }
        else { std::cout << "Incorrect" << std::endl; }
        std::cout << "Sides count: " << get_sides_count() << std::endl;
    }

    virtual bool check()
    {
        if (sides_count == 0)
        {
            return true;
        }
        else { return false; }
    }
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;
public:
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    Triangle() {}
    Triangle(int sides_count, int a, int b, int c, int A, int B, int C)
    {
        name = "Triangle";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void print_info() override
    {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Sides: a=" << get_a()
            << " b=" << get_b()
            << " c=" << get_c() << std::endl;
        std::cout << "Angels: A=" << get_A()
            << " B=" << get_B()
            << " C=" << get_C() << std::endl;
    }

    bool check() override
    {
        if ((sides_count == 3) && (A + B + C == 180))
        {
            return true;
        }
        else { return false; }
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int sides_count, int a, int b, int c, int A, int B)
    {
        name = "Right Triangle";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        C = 90;
    }

    bool check() override
    {
        if (Triangle::check() && C == 90)
        {
            return true;
        }
        else { return false; }
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int sides_count, int a, int b, int A, int B)
    {
        name = "Isosceles Triangle";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        c = a;
        C = A;
    }

    bool check() override
    {
        if (Triangle::check() && a == c && A == C)
        {
            return true;
        }
        else { return false; }
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int sides_count, int a)
    {
        name = "Equilateral Triangle";
        this->sides_count = sides_count;
        this->a = a;
        b = c = a;
        A = B = C = 60;
    }

    bool check() override
    {
        if (Triangle::check() && b == c && c == a && A == 60 && B == 60 && C == 60)
        {
            return true;
        }
        else { return false; }
    }
};

class Quadrangle : public Triangle
{
protected:
    int d;
    int D;
public:
    Quadrangle() {}
    Quadrangle(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D)
    {
        name = "Quadrangle";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    int get_d() { return d; }
    int get_D() { return D; }

    void print_info() override
    {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Sides: a=" << get_a()
            << " b=" << get_b()
            << " c=" << get_c()
            << " d=" << get_d() << std::endl;
        std::cout << "Angels: A=" << get_A()
            << " B=" << get_B()
            << " C=" << get_C()
            << " D=" << get_D() << std::endl;

    }

    bool check() override
    {
        if (sides_count == 4 && A + B + C + D == 360)
        {
            return true;
        }
        else { return false; }
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram() {}
    Parallelogram(int sides_count, int a, int b, int A, int B)
    {
        name = "Parallelogram";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        c = a;
        d = b;
        C = A;
        D = B;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && A == C && B == D)
        {
            return true;
        }
        else { return false; }
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int sides_count, int a, int b, int A)
    {
        name = "Rectangle";
        this->sides_count = sides_count;
        this->a = a;
        this->b = b;
        this->A = A;
        c = a;
        d = b;
        B = C = D = A;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            return true;
        }
        else { return false; }
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus() {}
    Rhombus(int sides_count, int a, int A, int B)
    {
        name = "Rhombus";
        this->sides_count = sides_count;
        this->a = a;
        this->A = A;
        this->B = B;
        b = c = d = a;
        C = A;
        D = B;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && a == d && A == C && B == D)
        {
            return true;
        }
        else { return false; }
    }
};

class Square : public Rhombus
{
public:
    Square(int sides_count, int a, int A)
    {
        name = "Square";
        this->sides_count = sides_count;
        this->a = a;
        this->A = A;
        b = c = d = a;
        B = C = D = A;
    }

    bool check() override
    {
        if (Quadrangle::check() && a == c && b == d && a == d && A == 90 && B == 90 && C == 90 && D == 90)
        {
            return true;
        }
        else { return false; }
    }
};

int main()
{
    Figure figure(0);
    Triangle triangle(3, 10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(3, 10, 20, 30, 50, 40);
    IsoscelesTriangle isoscelesTriangle(3, 10, 20, 50, 80);
    EquilateralTriangle equilateralTriangle(3, 30);
    Quadrangle quadrangle(4, 10, 20, 30, 40, 60, 120, 80, 100);
    Rectangle rectangle(4, 10, 20, 90);
    Square square(4, 20, 90);
    Parallelogram parallelogram(4, 20, 30, 100, 80);
    Rhombus rhombus(4, 30, 100, 80);

    figure.print_info();
    triangle.print_info();
    rightTriangle.print_info();
    isoscelesTriangle.print_info();
    equilateralTriangle.print_info();
    quadrangle.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhombus.print_info();
    return 0;
}