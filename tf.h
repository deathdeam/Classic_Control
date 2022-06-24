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
        vector< vector<int> > tf;

    public:
        trans_func(const vector<int> & numerator){ 
            tf.push_back(numerator);
            tf.push_back({1});
        }

        trans_func(const vector<int> & numerator, const vector<int> & denominator){ 
            tf.push_back(numerator);
            tf.push_back(denominator);
        }

        trans_func operator/ (trans_func & a, trans_func & b){

        }

        trans_func operator* (trans_func & a, trans_func & b){

        }
        
        trans_func operator+ (){

        }


        void Display(){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < tf[i].size()-1; j++){
                    cout << tf[i][j] << "s^" << tf[i].size()-1 << "+";
                }
                cout << tf[i][tf[i].size()-1] << endl;
                cout << "-------------" <<endl;
            }
        }    
};