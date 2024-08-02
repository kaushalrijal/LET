#include <iostream>

template <typename T>
class let {
private:
    T value;

public:
    let() = default;
    let(T val) : value(val) {}

    void show() {
        std::cout << value;
    }

    let& operator=(const T& newValue) {
        value = newValue;
        return *this;
    }

    friend std::istream& operator>>(std::istream& input, let<T>& obj) {
        input >> obj.value;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const let<T>& obj) {
        output << obj.value;
        return output;
    }
};

int main() {
    let k = 5;
    let l = 5.3;

    std::cout << "Initial value of k: " << k << std::endl;
    std::cout << "Initial value of l: " << l << std::endl;

    k = 69;
    l = 42.66;

    std::cout << "Value of k after reassignment: " << k << std::endl;
    std::cout << "Value of l after reassignment: " << l << std::endl;

    std::cout << "Enter a value for k: ";
    std::cin >> k;
    std::cout << "Enter a value for l: ";
    std::cin >> l;

    std::cout << "User input value of k: " << k << std::endl;
    std::cout << "User input value of l: " << l << std::endl;


    return 0;
}