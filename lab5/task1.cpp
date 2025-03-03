#include<iostream>

using namespace std;

class Square{
    float side_length, area;
    static float all_areas;

public:
    Square(){
        side_length = 0;
        area = 0;
    }

    Square(float side_length){
        this->side_length = side_length;
        area = 0;
    }

    void calculate_area(){
        area = side_length * side_length;
        all_areas += area;
    }

    float get_side_length(){
        return side_length;
    }

    void set_side_length(float length){
        side_length = length;
    }

    float get_area(){
        return area;
    }

    static float get_all_areas(){
        return all_areas;
    }
};

float Square::all_areas = 0;

int main(){
    Square square1(5);
    Square square2(3.5);
    Square square3(7);


    square1.calculate_area();
    cout << "Square 1 Area: " << square1.get_area() << endl;
    cout << "Total Area: " << Square::get_all_areas() << endl;

    square2.calculate_area();
    cout << "Square 2 Area: " << square2.get_area() << endl;
    cout << "Total Area: " << Square::get_all_areas() << endl;

    square3.calculate_area();
    cout << "Square 3 Area: " << square3.get_area() << endl;
    cout << "Total Area: " << Square::get_all_areas() << endl;

}
