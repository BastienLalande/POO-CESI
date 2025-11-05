#include <iostream>
#include <cmath>

class cercle {
    public:
        float x;
        float y;
        float r;
        cercle(float _x, float _y, float _r){
            x = _x;
            y = _y;
            r = _r;
        }
        double perimeter(){
            return 2 * M_PI * this->r;
        }
};

class rect {
    public:
        //Position of the top left corner
        double x;
        double y;

        double w; //width
        double h; //height
        rect();
        rect(double _x, double _y,double _w,double _h){
            this->x = _x;
            this->y = _y;
            this->w = _w;
            this->h = _h;
        }
        double perimeter() {
            return 2*(this->w+this->h);
        }
};

int main(){
    cercle c{0.0, 0.0, 5.0};
    rect r{0,0,10,5};
    std::cout << "peri cercle "<< c.perimeter() << std::endl;
    std::cout << "peri rect "<< r.perimeter() << std::endl;
    return 0;
}