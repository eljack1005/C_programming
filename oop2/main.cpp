#include <iostream>

using namespace std;

class point {
    int x , y;
    public:
    point(){};

    point(int x , int y){
    this->x = x;
    this->y = y;
    }

    int getx(){return this->x;}
    int gety(){return this->y;}

    void display(){
    cout<<"("<<this->x<<","<<this->y<<")"<<endl;
    }
};







class rectAssociation{
public:
void draw(point& p1, point& p2){
cout<<"rect association"<<endl;
cout<<"rect using p1";
p1.display();
cout<<"rect using p2";
p2.display();

}
};


class circleAssociation{
public:
void draw(point& center, int r){
cout<<"circle association"<<endl;
cout<<"circle using p1"<<endl;
center.display();
cout<<"circle radius = "<<r<<endl;

}
};






class rectAggregation{
    point* p1;
    point* p2;

public:
    rectAggregation(point* a, point* b) {
    p1 = a;
    p2 = b;
     }
    void draw(){
    cout<<"rect aggregation "<<endl;
    p1->display();
    p2->display();
    }
};




class circleAggregation{
    point* center;
    int radius;

public:
    circleAggregation(point* a, int r) {
    center = a;
    radius = r;
    }
    void draw(){
    cout<<"circle aggregation "<<endl;
    center->display();
    cout<<"radius = "<<radius;

    }
};







class rectComposition{
point p1 , p2;
public:
    rectComposition(int x1 , int y1 , int x2 , int y2):p1(x1 , y1) , p2(x2 , y2){
    }
    void draw(){
    cout<<"rect composition"<<endl;
    p1.display();
    p2.display();
    }
};

class circleCompostion{
point center;
int raduis;
public:
    circleCompostion(int x1 , int y1 , int r):center(x1 , y1){
    raduis = r;
    }
    void draw(){
    cout<<"circle composition"<<endl;
    center.display();
    cout<<"radius = "<<raduis<<endl;
    }

};

int main()
{
    cout << "      Association      " << endl;
    point p1(2 ,4);
    point p2(6 , 8);
    rectAssociation ra;
    ra.draw(p1 , p2);

    circleAssociation ca;
    ca.draw(p1 , 5);

    cout <<endl<< "      aggregation      " << endl;
    rectAggregation rg(&p1 , &p2);
    rg.draw();

    circleAggregation cg(&p2 , 5);
    cg.draw();

    cout <<endl<<endl<< "      composition      " << endl;
    rectComposition rc(1 ,2 , 3 , 4);
    rc.draw();

    circleCompostion cc(1 , 2 , 3);
    cc.draw();

    return 0;
}
