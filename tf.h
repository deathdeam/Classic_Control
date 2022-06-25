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
        std::vector<int> numerator;
        std::vector<int> denominator;
    public:
        trans_func(){};
        trans_func(const std::vector<int> & num){};
        trans_func(const std::vector<int> & num, const std::vector<int> & deno){};
        trans_func operator/ (trans_func & b){};   
        trans_func operator* (trans_func & b){};
        trans_func operator+ (trans_func & b){};
        void Display(){};
};