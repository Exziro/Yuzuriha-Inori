    # include <iostream>  
    using namespace std;  
    class my_complex {  
    private:  
        int real;  
        int imag;  
    public:  
        my_complex();  
        my_complex(int real, int imag);  
        ~my_complex();  
        my_complex(const my_complex& rhs);  
        my_complex& operator=(const my_complex& rhs);  
        my_complex& operator+(const my_complex& rhs);  
        bool operator==(const my_complex& rhs);  
        friend ostream &operator<<(ostream& output, const my_complex &rhs);  
    };  
    my_complex::my_complex() :  
        real(0), imag(0) {  
    }  
    my_complex::my_complex(int real, int imag) :  
        real(real), imag(imag) {  
    }  
    my_complex::my_complex(const my_complex& rhs) {  
        real = rhs.real;  
        imag = rhs.imag;  
    }  
    my_complex& my_complex::operator +(const my_complex& rhs) {  
        real = rhs.real + real;  
        imag = rhs.imag + imag;  
        return *this;  
    }  
    my_complex& my_complex::operator =(const my_complex& lhs) {//重载等号  
        real = lhs.real;  
        imag = lhs.imag;  
        return *this;  
    }  
    bool my_complex::operator ==(const my_complex& rhs) {  
        return real == rhs.real && imag == rhs.imag;  
    }  
    my_complex::~my_complex() {  
      
    }  
    ostream& operator<<(ostream& output, const my_complex &rhs) {  
        output << rhs.real;  
        if (rhs.imag > 0) {  
            std::cout << "+";  
        }  
        std::cout << rhs.imag << "i";  
        return output;  
    }  
    int main() {  
        my_complex c1(1, 5);  
        my_complex c2(c1); //等价于 my_complex c2 = c1;  
        my_complex c3(2, 3);  
        bool flag(c1 == c2);  
        c1 = c1 + c2;  
        cout << c1 << endl;  
        cout << c2 << endl;  
        cout << c3 << endl;  
        cout << flag << endl;  
    }  