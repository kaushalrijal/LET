#include <iostream>

template <typename T>
class let {
private:
    T value;

public:
    let() = default;
    let(const char* val) : value(std::string(val)) {}   // Convert const char to string
    let(T val) : value(val) {}

    void show() {
        std::cout << value;
    }

    let& operator=(const T& newValue) {
        value = newValue;
        return *this;
    }

    friend std::istream& operator>>(std::istream& input, let<T>& obj) {
        if constexpr (std::is_same_v<T, std::string>) {
            std::getline(input, obj.value);
        } else {
            input >> obj.value;
        }
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const let<T>& obj) {
        output << obj.value;
        return output;
    }
};

// Class template argument deduction guides
let(int) -> let<int>;
let(double) -> let<double>;
let(const char*) -> let<std::string>;
let(std::string) -> let<std::string>;
