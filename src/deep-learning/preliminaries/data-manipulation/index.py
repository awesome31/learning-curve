'''
    Libraries Like Pytorch or Tenserflow use GPU instead of CPU for computations.
'''
import torch

x = torch.arange(12, dtype=torch.float32);
print("Create a vector.")
print(x)
print(x.numel())
print(x.shape)
print("\n")

print("Reshape a vector to a matrix.")
X = x.reshape(3, 4)
print(X)
print("\n")

print("Tensors of all 0s or 1s.")
zeros = torch.zeros([2, 3, 4])
ones = torch.ones([1, 1])
print(zeros, ones)
print("\n")

print("Tensor with random values.")
randoms = torch.randn(2, 3)
print(randoms)
print("\n")

print("Create Tensor with specific values.")
specific = torch.tensor([[1, 2, 3], [1, 2, 3]])
print(specific)
print("\n")

print("Slice and get data out of the tensor.")
slice = X[1:3]
print(slice)
print("\n")


print("Unary Operators on tensors")
print(torch.exp(x))
print("\n")

print("Binary Operators on tensors. These operations can happen only if the shape of tensors are same and happens elementwise.")
first = torch.arange(12, dtype=torch.float32).reshape(3, 4)
second = torch.tensor([[1, 2, 3, 4], [1, 2, 3, 4], [1, 2, 3, 4]])
print(first, second, first + second)
print("\n")

print("With broadcasting, we can perform operations on tensors of different shapes.")
first = torch.arange(12, dtype=torch.float32).reshape(3, 4)
second = torch.tensor([1, 2, 3, 4])
print(first + second)
print("\n")

print("We can save memory by using slices")
memory = torch.tensor([1, 2, 3, 4])
before = id(memory)
memory += 2;
after = id(memory)
print(before, after, before == after)

print("Excercise")
print("Run the code in this section. Change the conditional statement X == Y to X < Y or X > Y, and then see what kind of tensor you can get.")

X = torch.arange(12, dtype=torch.float32).reshape((3,4))
Y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
print(X == Y)
print(X < Y)
print(X > Y)

a = torch.arange(12).reshape((2, 1, 6))
b = torch.arange(4).reshape((1, 4, 1))
print(a, b, a + b)