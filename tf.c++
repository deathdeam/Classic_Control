#include"tf.h"

trans_func::trans_func(){

}
trans_func::trans_func(const std::vector<int> & num){ 
    numerator = num;
    denominator = {1};
}

trans_func::trans_func(const std::vector<int> & num, const std::vector<int> & deno){ 
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
        return;
    }
    std::cout << "-------------" <<std::endl;
    for(int i = 0; i < denominator.size()-1; i++){
        std::cout << denominator[i] << "s^" << denominator.size()-1-i << "+";
    }    
    std::cout << denominator.back() <<std::endl;
    
}


std::vector<int> vector_addition(std::vector<int> a , std::vector<int>  b){
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
std::vector<int> vector_multiply(std::vector<int> a, std::vector<int> b){
    std::vector<int> result(a.size()+b.size()-1, 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            result[(a.size()-1 - i)+(b.size()- 1 - j)] = a[i]*b[j];
        }
    }
    return result;
}