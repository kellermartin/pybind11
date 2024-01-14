#import sys
#sys.path.append("/home/keller/pybind/build")
# your_module.py
import Calculator

# Create an instance of the Calculator class
calculator = Calculator.Calculator(10)

# Call its methods
calculator.add(5)
print("Value after addition:", calculator.getValue())

calculator.subtract(3)
print("Value after subtraction:", calculator.getValue())
