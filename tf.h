#include<vector>
#include<iostream>
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
    public:
        std::vector<int> numerator;
        std::vector<int> denominator;
        trans_func(){};
        trans_func( std::vector<int> & num);
        trans_func( std::vector<int> & num, std::vector<int> & deno);
        trans_func operator/ (trans_func & b);   
        trans_func operator* (trans_func & b);
        trans_func operator+ (trans_func & b);
        void Display();
    private:
        
        std::vector<int> vector_addition(std::vector<int> a , std::vector<int>  b);
        std::vector<int> vector_multiply(std::vector<int> a, std::vector<int> b);
};
trans_func::trans_func(std::vector<int> & num){ 
    numerator = num;
    denominator = {1};
}
trans_func::trans_func(std::vector<int> & num, std::vector<int> & deno){ 
    numerator = num;
    denominator = deno;
}
trans_func trans_func::operator/ (trans_func & b){
    trans_func tf;
    tf.numerator = vector_multiply(this->numerator, b.denominator);
    tf.denominator = vector_multiply(this->denominator, b.numerator);
    return tf;
}   
trans_func trans_func::operator* (trans_func & b){
    trans_func tf;
    tf.numerator = vector_multiply(this->numerator,b.numerator);
    tf.denominator = vector_multiply(this->denominator,b.denominator);
    return tf;
}
trans_func trans_func::operator+ (trans_func & b){
    //addition in numerator and multiplying the denominator
    trans_func tf;
    tf.numerator = vector_addition(this->numerator,b.numerator);
    tf.denominator = vector_multiply(this->denominator,b.denominator);
    return tf;
}   
void trans_func::Display(){
    /*
    This function is used to display the transfer function in three lines.
    */

    for(int i = 0; i < numerator.size()-1; i++){
        std::cout << numerator[i] << "s^" << numerator.size()-1-i << "+";
    }    
    std::cout << numerator.back() <<std::endl;
    if(denominator.size() == 1){ 
        std::cout << std::endl;
        return;
    }
    std::cout << "-------------" <<std::endl;
    for(int i = 0; i < denominator.size()-1; i++){
        std::cout << denominator[i] << "s^" << denominator.size()-1-i << "+";
    }    
    std::cout << denominator.back() <<std::endl;
    std::cout << std::endl;
    
}
std::vector<int> trans_func::vector_addition(std::vector<int> a , std::vector<int>  b){
    if(a.size() >= b.size()){
        for(std::vector<int>::reverse_iterator i = a.rbegin(), j = b.rbegin() ; i != a.rend() && j != b.rend();i++, j++ ){
            *i += *j;
        }
        return a;
    }
    else{
        for(std::vector<int>::reverse_iterator i = a.rbegin(), j = b.rbegin() ; i != a.rend() && j != b.rend();i++, j++ ){
            *j += *i;
        }
        return b;
    }
}
std::vector<int> trans_func::vector_multiply(std::vector<int> a, std::vector<int> b){
    std::vector<int> result(a.size()+b.size()-1, 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            result[i+j] += a[i]*b[j];
        }
    }
    return result;
}

/*
This Diff_func is not so useful as I realized that there are should be better way to deal with this 

Ideal idea of this one is to transfer equation of motion in time domain to transfer function in frequency domain.
This is a oversimplified version since I only consider the polynominal function for now.
Using trigonometry or t might be the next step. The reason I don't want to work on this is that I can only think of using
look-up table to deal with laplace transform which is not worth to spend time on. 

Constructor():

Display():

Operation():

*/

class Diff_func{
    public:
        Diff_func(){};
        Diff_func(std::vector<int>func, std::vector<int> in_con, int ans);
        Diff_func(std::vector<int>func,int ans);
        trans_func Laplace();
        void Display();

    private:
        std::vector<int> function;
        std::vector<int> init_condition;
        int right;
        int init_state;
    
};
Diff_func::Diff_func(std::vector<int>func, std::vector<int> in_con,int ans):function(func),init_condition(in_con),right(ans),init_state(1){
}

Diff_func::Diff_func(std::vector<int>func, int ans):function(func),init_state(0),right(ans){
}

trans_func Diff_func::Laplace(){
    if(init_state = 0){
        
    }
    else{

    }
}

void Diff_func::Display(){

}