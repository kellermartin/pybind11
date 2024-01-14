// your_cpp_library.cpp
#include <pybind11/pybind11.h>

class Calculator {
public:
    Calculator(int initialValue) : value(initialValue) {}

    void add(int x) {
        value += x;
    }

    void subtract(int x) {
        value -= x;
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

PYBIND11_MODULE(Calculator, m) {
    pybind11::class_<Calculator>(m, "Calculator")
        .def(pybind11::init<int>())
        .def("add", &Calculator::add)
        .def("subtract", &Calculator::subtract)
        .def("getValue", &Calculator::getValue);
}
