import numpy as np

# Prove Derivatives of E ^ x.
def e(x):
    return np.exp(x)
for h in 10.0**np.arange(-1, -6, -1):
    print(f'h={h:.5f}, numerical limit={(e(1+h)-e(1))/h:.5f}')
    
print("\n")

# Prove Derivatives of x ^ n.
def x_n(x, n):
    return x ** n

def x_n_derivative(v):
    return (x_n(v+10**-2, 3)-x_n(v, 3))/10**-2;

for v in np.arange(1, 10, 1):
    print(f'v={v:.5f}, numerical limit={x_n_derivative(v):.5f}')
    