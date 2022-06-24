#include<iostream>
#include<vector>
#include<>
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
        vector< vector<int> > function;
        vector<int> numerator;
        vector<int> denominator;
    public:
        trans_func(){

        }
        trans_func(const vector<int> & num){ 
            numerator = num;
            denominator = {1};
            function.push_back(numerator);
            function.push_back(denominator);
        }

        trans_func(const vector<int> & num, const vector<int> & deno){ 
            numerator = num;
            denominator = deno;
            function.push_back(numerator);
            function.push_back(denominator);
        }

        trans_func operator/ (trans_func & b){
            
        }

        trans_func operator* (trans_func & b){
            trans_func tf;
            tf.numerator = vector_multiply(this->numerator,b.numerator);
            tf.denominator = vector_multiply(this->denominator,b.denominator);
            tf.function.push_back(tf.numerator);
            tf.function.push_back(tf.denominator);
            return tf;
        }
        
        trans_func operator+ (trans_func & b){
            //addition in numerator and multiplying the denominator
            trans_func tf;
            tf.numerator = vector_addition(this->numerator,b.numerator);
            tf.denominator = vector_multiply(this->denominator,b.denominator);
            tf.function.push_back(tf.numerator);
            tf.function.push_back(tf.denominator);
            return tf;
        }   


        void Display(){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < function[i].size()-1; j++){
                    cout << function[i][j] << "s^" << function[i].size()-1 << "+";
                }   
                cout << function[i][function[i].size()-1] << endl;
                if( i == 0){
                    cout << "-------------" <<endl;
                }
            }
        }    
};
static vector<int> vector_addition( vector<int>  a , vector<int>  b){
    if(a.size() >= b.size()){
        for(vector<int>::reverse_iterator i = a.rbegin(), j = b.rbegin() ; i != a.rend(), j != b.rend();i++, j++ ){
            *i += *j;
        }
        return a;
    }
    else{
        for(vector<int>::reverse_iterator i = a.rbegin(), j = b.rbegin() ; i != a.rend(), j != b.rend();i++, j++ ){
            *j += *i;
        }
        return b;
    }
}
static vector<int> vector_multiply(vector<int> a, vector<int> b){
    vector<int> result(a.size()+b.size()-1, 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            result[(a.size()-1 - i)+(b.size()- 1 - j)] = a[i]*b[j];
        }
    }
}