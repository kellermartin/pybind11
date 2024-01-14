# Creating a c++ python module using PyBind11



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

This should give the following output in the console
```console
Value after addition: 15
Value after subtraction: 12
```
For distribution of the module consider adding a setup.py that can create a python distribution package that can be installed using pip
