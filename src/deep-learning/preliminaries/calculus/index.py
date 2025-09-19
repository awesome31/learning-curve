'''
Calculus
'''

import numpy as np
from matplotlib_inline import backend_inline
from d2l import torch as d2l

# Derivative is the rate of change of function. Formally it means that if we have a function f(x), then the derivative of f(x) at x = a is defined as the limit of the difference quotient as h approaches 0. Lets take an example.

# f(x) = 3x^2 - 4x Then f'(1) = 6 - 4 = 2
def f(x):
    return (3 * (x ** 2)) - (4 * x);

print(f(1))
for h in 10.0**np.arange(-1, -6, -1):
    print(f'h={h:.5f}, numerical limit={(f(1+h)-f(1))/h:.5f}')

# Derivatives always give the slope of the tangent line.