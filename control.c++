#include <iostream>
#include <vector>
#include "tf.h"
using namespace std;

int main() {
    vector<int> num = {1,23,3};
    vector<int> den = {1,2,5,7,8};
    trans_func func(num,den);
    func.Display();
    return 0;
}