'''
Execercises
'''

import torch

# Prove that transpose of a transpose of a matrix is the matrix itself
A = torch.arange(6).reshape(2, 3)
print(A.equal(A.T.T))

# Sum and Transposition commute
A = torch.arange(6).reshape(2, 3)
B = torch.arange(6).reshape(2, 3)
print((A.T + B.T).equal((A + B).T))

# Prove that addition of a matrix and its transpose is a symmetric matrix
A = torch.arange(4).reshape(2, 2)
print((A + A.T).equal((A + A.T).T))

# Length returns the number of elements in the first dimension
B = torch.arange(24).reshape(2,3, 4)
print(len(B), B)

A = torch.arange(6).reshape(2, 3)
print(A / A.sum(axis = 0))

A = torch.arange(12, dtype = torch.float32).reshape(2, 2, 3)
print(A.sum(axis = 2))
print(torch.linalg.norm(A), A)
print(torch.arange(12).square().sum().sqrt())