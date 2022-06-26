#include <iostream>
#include <vector>
#include "tf.h"
using namespace std;
void Block_diagram(){
    Input
    Controller
    Plant
    Sensor
    //How to use 1+CGH directly? 
    Total_func = Controller * Plant /(1+ Sensor* Plant * Controller);
    Output = Total_func * Input;
    Output.Display();
    //How to show the output signal... I might need to have an Inverse Laplace in trans_func in this case so that I could have
    //time varient system.

}


int main() {
    vector<int> num = {1,23,3};
    vector<int> den = {1,2,5,7,8};
    trans_func func1(num);
    trans_func func2(den);
    trans_func test1 = func1 + func2;
    trans_func test2 = func1 / func2;
    trans_func test3 = func1 * func2;
    cout << "test display" <<endl;
    
    test1.Display();
    
    test2.Display();
    test3.Display();
    return 0;
}