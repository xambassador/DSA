class ComplexNumbers {
    public:
    int real;
    int imaginary;

    ComplexNumbers(int real, int imaginary) {
        this -> real = real;
        this -> imaginary = imaginary;
    }

    void plus(ComplexNumbers const &c2) {
        int x,y;
        x = real + c2.real;
        y = imaginary + c2.imaginary;
        real = x;
        imaginary = y;
    }

    void multiply(ComplexNumbers const &c2) {
        int x,y,z,w;
        x = real * c2.real;
        y = real * c2.imaginary;
        z = imaginary * c2.real;
        w = imaginary * c2.imaginary * (-1); //square
        real = x + w;
        imaginary = y + z;
    }

    void print() {
        cout << real << " " << "+" << " " << "i" << imaginary << endl;
    }
};