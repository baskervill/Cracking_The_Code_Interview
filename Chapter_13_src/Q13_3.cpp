#include <iostream>
using namespace std;
class Shape{
    public:
        int edge_length;
        virtual int circumference(){
            cout<<"Circumference of Base Class\n";
            return 0;
        }
};
class Triangle: public Shape{
    int circumference(){
        cout<<"Circumference of Triangle Class\n";
        return 0;
    }
};
int main(){
    Shape *x = new Shape();
    x->circumference();
    Shape *y = new Triangle();
    y->circumference();
    return 0;
}