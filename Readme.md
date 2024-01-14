# Creating a c++ python module using pybind11
The following small example demonstrates how a class in c++ can be exposed as a python module.
The example is kept small and concise and shows the implementation of a very simple Calculator that is able to add and subtract to 
an initial number that is provided in the constructor call of the object.


## Install Prerequisites
Install pybind11 using apt

```console
sudo apt install pybind11-dev
```


## Compiling the example project
Apply the following steps in your console to compile the project

```console
mkdir build
cd build
cmake ..
make
```

The shared library is wrapping the implementation of the simple Calculator class 

The contents of the calculator.cpp can be seen below.

```cpp
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

```


## Running the example script
In order for the library loader to find the shared library you will need to run 
the python script from the same location as the shared library.

So in this case copy the shared library object from the build output folder to the same location as your python script

For example like
```console
cp build/Calculator.cpython-310-x86_64-linux-gnu.so ./
```

Run the python script from the console
```console
python3 myscript.py
```
The contents of myscript.py can be seen below.

```python
import Calculator

# Create an instance of the Calculator class
calculator = Calculator.Calculator(10)

# Call its methods
calculator.add(5)
print("Value after addition:", calculator.getValue())

calculator.subtract(3)
print("Value after subtraction:", calculator.getValue())

```

This should give the following output in the console
```console
Value after addition: 15
Value after subtraction: 12
```
For distribution of the module consider adding a setup.py that can create a python distribution package that can be installed using pip
