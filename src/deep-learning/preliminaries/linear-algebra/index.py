'''
Linear Algebra
'''

import torch

# Scalars are single numbers
#Scalars are represented using lowercase letters
x = torch.tensor(3.0)
y = torch.tensor(2.0)
print(x + y, x - y, x * y, x / y)

# Vectors are arrays of numbers for the purpose of linear algebra. Ecah vector has a scalar component and each scaler component contains information. For example, we can represent the patient history as a vector.
#Vectors are represented using bold lowercase letters
u = torch.tensor([1.0, 0.0])
print(u[0], u[1])
print(u.shape[0])

# Matrices are 2nd order tensors. By order we mean the number of dimensions. Dimensionality means the number of elements in each dimension. 
# They are represented using bold uppercase letters.
X = torch.arange(6).reshape(3, 2)
print(X, X.shape)
# Transpose of a matrix is the matrix with the rows and columns interchanged. It is represented using a prime symbol.
Xt = X.T;
print(Xt, Xt.shape)

# General Tensors are nth order tensors. With images there are 3 dimension to it, height, width and channels.
print(torch.arange(24).reshape(2, 3, 2, 2))

# General Arithemetic of tensors of same shape happens elementwise.
A = torch.arange(6).reshape(2, 3)
B = A.clone()
print(A, A + B, A * B)
# We can multiply scalars with tensors too.
print(A * 2)

# Reduction: This means reducing the scalar values of a tensor into one value, like a sum or mean. 
x = torch.arange(3, dtype=torch.float32)
print(x, x.sum())
print(A, A.sum())
# We can also reduce the values along a specific axis. When we reduce, the shape of the tensor changes to the axis we reduce along.
print(A.shape, A.sum(axis=0).shape)

# Non-reduction sum: Sometimes we do not want to change the shape of the tensor. We can do this by using keepdim.
sum_A = A.sum(axis=0, keepdim=True)
print(sum_A, sum_A.shape, A.shape)

# We can calculate dot product of two vectors.
x = torch.tensor([1.0, 2.0, 3.0])
y = torch.tensor([4.0, 5.0, 6.0,])
print(x.dot(y))
# A good example of dot product is the weighted sum of values.
scores = torch.tensor([90, 67, 85], dtype=torch.float32)
weights = torch.tensor([0.3, 0.4, 0.3], dtype=torch.float32)
print(scores.dot(weights))

# We can also calculate the product of a matrix and a vector. Suppose we have an mxn matrix and a vector of size n. Then the product of the matrix and the vector is a vector of size m.
# An intuitive example is rotation of a vector in 2D space. Think of mv as a transformation happening on a vector usiing the matrix where each matrix value encodes some information.
v = torch.tensor([1.0, 2.0], dtype=torch.float32)
R = torch.tensor([[0, -1], [1, 0]], dtype=torch.float32)
mv = torch.mv(R, v)
print(v.shape, R.shape, mv.shape, mv)

# We can calculate the product of a matrix and a matrix. Suppose we have an mxn matrix and a nxp matrix. Then the product of the matrix and the matrix is a mxp matrix.
# Leading by the same example, two matrices X and Y can be thought of as a transformation happening on a matrix X using the matrix Y where each matrix value encodes some information. After the matrix multiplication, we get a new matrix that encodes the transformed information which can then be applied to say a vector v.
X = torch.arange(1, 7).reshape(2, 3)
Y = torch.arange(1, 13).reshape(3, 4)
print(X.shape, Y.shape, torch.mm(X, Y).shape, torch.mm(X, Y))

# Norms are a measure of the size of a vector or a matrix. Norms are essentially used in optimisation algorithms.
u = torch.tensor([3.0, 4.0])
print(u.norm())
print(torch.norm(torch.ones(2, 3)))