#include <iostream>

using namespace std;


class Shape {   // 도형 객체
public:
    virtual int getArea() = 0;  //가상함수 getArea 선언
    ~Shape() {}
};


class Rectangle : public Shape {    // 직사각형
private:
    int width;  //직사각형 요소 너비, 높이
    int height;

public:
    Rectangle(int width, int height) {
        this->width = width;
        this->height = height;
    }

    virtual int getArea(){      //가상함수 getArea 재정의
        return width * height;
    }
};


class Square : public Shape {       //정사각형
private:
    int side;   //정사각형 요소 한 변의 길이

public:
    Square(int side) {
        this->side = side;
    }

    virtual int getArea(){  //가상함수 getArea 재정의
        return side * side;
    }
};

// 넓이 계산
class AreaCalculator {
public:
    void calculateArea(Shape& shape) {  //Shape를 상속받은 클래스를 받기 위해 참조 사용, 참조로 Shape 클래스 영역에 접근
        cout << "Area: " << shape.getArea() << endl;
    }
};

int main() {
    AreaCalculator calculator;

    Rectangle rectangle(5, 4);
    calculator.calculateArea(rectangle);

    Square square(5);
    calculator.calculateArea(square);
}