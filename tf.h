#include<iostream>
#include<vector>
using namespace std;
/*
Constructor(): vector<int> , vector<int> + vector<int>
    Plan: Achieved using constructor overruling
    In this case, I would like to set trans_func as a 2d vector.

Display(): The expression of the transfer function in 2s^2+1s^1 form
    Plan: Achieved using display()

Operations: Muiltiplying, addition, subtraction, Inverse Laplace, and Laplace 
    Plan: not decided
...
*/
class trans_func {
    private:
        vector< vector<int> > tf(2,vector<int>);

    public:
        trans_func(const vector<int> chara){

        }
        trans_func operator/ (trans_func & a, trans_func & b){

        }
        print(){
            for(int i = 0; i < 2; i++){

            }
        }    
};