# Character Level Language Models

We are going to be building Makemore. The idea of Makemore is that we are given a dataset of text and we want to build a language model that can generate text similar to the dataset. A character level language model means that we just predict the next character based on the previous characters. 

Lets breakdown what a specific word in a dataset is telling us. Lets take example of the word 'isabella'. It gives us the following information:

1. The word 'i' is likely to come first.
2. The word 's' is likely to come after 'i'.
3. The word is likely to end with 'isabella'.

And we have multiple such words. So there is a lot of structure here that we can try and model.


## Reading the dataset


```python
words = open("names.txt", "r").read().splitlines()
words[:10]
```




    ['emma',
     'olivia',
     'ava',
     'isabella',
     'sophia',
     'charlotte',
     'mia',
     'amelia',
     'harper',
     'evelyn']




```python
print(len(words))
print(min(len(w) for w in words))
print(max(len(w) for w in words))
```

    32033
    2
    15


## Bigram Model

A bigram model is a probability distribution over pairs of characters. In Bigram we do not care about ALL the characters that come before only the last character that came before the current character. Its a very simple and weak language model, but a good starting point. These are the steps that we are doing:

1. We will be adding two tokens called `<S>` and `<E>` to mark the start and end of a word respectively.
2. Then for each pair, we are going to be creating a frequency distribution and then inspect what pairs occur the most.


```python
biagram_freq = {}

for w in words:
    chs = ['<S>'] + list(w) + ['<E>']
    for i in range(len(chs) - 1):
        biagram = (chs[i], chs[i+1])
        biagram_freq[biagram] = biagram_freq.get(biagram, 0) + 1

# Get the 5 max biagrams. These are the most likely biagrams.
print(sorted(biagram_freq.items(), key=lambda x: x[1], reverse=True)[:5])
```

    [(('n', '<E>'), 6763), (('a', '<E>'), 6640), (('a', 'n'), 5438), (('<S>', 'a'), 4410), (('e', '<E>'), 3983)]


Instead of storing the counts in a dictionary, a better way to model this is to use a multidimensional array where the first dimension is the first character and the second dimension is the second character and the value represents the count. We will create an array of 28 x 28 dimensions and initialize it to 0. Lets assume we call it N.

N[0, 0] => This means the count of the first character being 'a' and the second character being 'a'.
N[0, 1] => This means the count of the first character being 'a' and the second character being 'b'.
N[0, 26] => This means the count of the first character being 'a' and the second character being '<S>'.


This is the mapping would be.


```python
import torch

# Let us create a way to convert strings into integers.
stoi = {ch: i for i, ch in enumerate(sorted(list(set(''.join(words)))))}
stoi['<S>'] = 26
stoi['<E>'] = 27

N = torch.zeros((28, 28), dtype=torch.int32)

for w in words:
    chs = ['<S>'] + list(w) + ['<E>']
    for i in range(len(chs) - 1):
        N[stoi[chs[i]], stoi[chs[i+1]]] += 1

stoi
N[0, 27]
```




    tensor(6640, dtype=torch.int32)



With this current structure, the issue is that we have the row S and column E which will always be 0s. Also instead of using 2 tokens, we can use 1 token to represent start and end and then recreate the dataset better.


```python
# Let us create a way to convert strings into integers.
stoi = {ch: i + 1 for i, ch in enumerate(sorted(list(set(''.join(words)))))}
itos = {i: s for s, i in stoi.items()}
stoi['.'] = 0

N = torch.zeros((27, 27), dtype=torch.int32)

for w in words:
    chs = ['.'] + list(w) + ['.']
    for i in range(len(chs) - 1):
        N[stoi[chs[i]], stoi[chs[i+1]]] += 1

stoi
N[:, 0] # Letters ending with the character.
N[0, :] # Letters starting with the character.

#Everything else will be in between.
```




    tensor([   0, 4410, 1306, 1542, 1690, 1531,  417,  669,  874,  591, 2422, 2963,
            1572, 2538, 1146,  394,  515,   92, 1639, 2055, 1308,   78,  376,  307,
             134,  535,  929], dtype=torch.int32)



Now that we have the model of frequencies, we can sample from the model to create a word. A model often defines probability distributions over possible outputs. Sampling means drawing an example from that distribution.

Sampling from the model means randomly picking a word according to those probabilities.

- 60% chance → “cat”
- 30% chance → “dog”
- 10% chance → “car”

Let us take an example of how we sample from any probability distribution in general


```python
# Example of sampling from a probability distribution
g = torch.Generator().manual_seed(2147483647)
p = torch.rand(3, generator=g)
p = p / p.sum()

# We use this method from pytorch to sample from the probability distribution.
torch.multinomial(p, num_samples=20, replacement=True, generator=g)
```




    tensor([1, 1, 2, 0, 0, 2, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1])



Coming back to our example above, we will use the tensor that we have created and create a word by starting from . and then sampling from our distribution to get the next word and so on and so forth. If you compare the output of uniform true, vs our bigram model, you can clearly see that the model has learned something. Although the bigram model is terrible.

Also for each iteration, instead of calculating the distribution again and again which is inefficient, we can create a probability matrix P. We should use and get comfortable with broadcasting. The broadcasting rules state that:

1. Each tensor has at least one dimension.
2. When iterating over the dimension sizes, starting at the trailing dimension, the dimension sizes must either be equal, one of them is 1, or one of them does not exist.


```python
P = N.float()
row_sums = P.sum(dim=1, keepdim=True)

print(P.shape, row_sums.shape)
P /= row_sums
```

    torch.Size([27, 27]) torch.Size([27, 1])



```python
g = torch.Generator().manual_seed(21474836337)

def generate_word(uniform=False):
    itos = {i: s for s, i in stoi.items()}

    idx = 0
    new_word = ''

    while True:
        p = P[idx]

        if uniform:
            p = torch.ones(27) / 27

        idx = torch.multinomial(p, num_samples=1, replacement=True, generator=g).item()
   
        if idx == 0:
            break
        else:
            new_word += itos[idx]
    
    return new_word

for i in range(10):
    print(generate_word())

print('---')
for i in range(10):
    print(generate_word(uniform=True))
```

    mati
    nnnneler
    w
    ghannasyso
    alorgocalin
    zume
    buio
    khr
    aly
    gejerem
    ---
    vx
    ucysgfsterduncbcq
    kcfyvvijlarcmwym
    ghoarxhrcmeruwinoddomwzqloy
    umpaedjkvhhqutljg
    lzimlzpevcodljhgbc
    jxzqqpfndgjcaabl
    xutf
    i
    dpdvhayxrdrjoeqylxuztomrzwuqdcsnzohomwqwfqrwqqomungwpuikbhazfcpzdtotjpnmbcnlp


Just to understand why keepdim is important, lets look at an example:

A = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
row_sums = A.sum(dim=1)

If we do A / row_sums, it will divide: [1, 4, 7] by [6, 6, 6], [2, 5, 8] by [15, 15, 15], [3, 6, 9] by [24, 24, 24] which is not what we want. We want rows to be divided by their respective sum and not the colums by the sum of the rows. To do that, we need to use keepdim.


```python
A = torch.tensor([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
row_sums = A.sum(dim=1)

print(row_sums)
A / row_sums
```

    tensor([ 6, 15, 24])





    tensor([[0.1667, 0.1333, 0.1250],
            [0.6667, 0.3333, 0.2500],
            [1.1667, 0.5333, 0.3750]])



### Evaluating the Bigram Model

Now that we have created a model, lets try and think through how good our model is. We want to first get the loss function. Loss function measure how good our model is based on the training data and then iteratively tries to minimize the loss. When dealing with probabilities, we usually use the maximum likelihood estimation.

Maximum likelihood estimation says that the parameters of the model that maximize the likelihood of the training data are the best parameters. In other words, we want to find the parameters that make the training data most likely. Our loss function will be the negative log likelihood. In Bigrams case, we can take the words, and take the probability of our model spitting out those words.

In the below code, we can see the probability that our model assigned for each biagram. The max likelihood estimation says that we need to take a product of all these probabilities to get the likelihood of the word. We use negative log likelihood because if we take a product of probabilities, it can become very small and we can run into underflow issues. Log has a nice property which states that log of a product is equal to sum of logs. 


```python
for w in words[:2]:
    chs = ['.'] + list(w) + ['.']
    for i in range(len(chs) - 1):
        bigram = (chs[i], chs[i + 1])
        print(f'{chs[i], chs[i + 1]}: {P[stoi[chs[i]], stoi[chs[i + 1]]]:.4f}')
```

    ('.', 'e'): 0.0478
    ('e', 'm'): 0.0377
    ('m', 'm'): 0.0253
    ('m', 'a'): 0.3899
    ('a', '.'): 0.1960
    ('.', 'o'): 0.0123
    ('o', 'l'): 0.0780
    ('l', 'i'): 0.1777
    ('i', 'v'): 0.0152
    ('v', 'i'): 0.3541
    ('i', 'a'): 0.1381
    ('a', '.'): 0.1960


Let us understand log likelihood with a small example.

1. As we can see below, the lower the probability, the lower the log likelihood.
2. The final log likelihood is the sum of log likelihoods of all the events.
3. If all were 1, the log likelihood would be 0.
4. In machine learning, we want to create a loss function, and then minimize our model's loss. Therefore instead of taking the log likelihood, we take the negative log likelihood.
5. Now our statement becomes to create a loss value that is as close to 0 as possible. 
6. Now the job of the model is to minimize the loss function.


```python
ps = [0.1, 0.2, 0.3, 0.4]

log_likelihood = 0.0
for i in ps:
    print(i, torch.log(torch.tensor(i)))
    log_likelihood += torch.log(torch.tensor(i))

print(-log_likelihood)
```

    0.1 tensor(-2.3026)
    0.2 tensor(-1.6094)
    0.3 tensor(-1.2040)
    0.4 tensor(-0.9163)
    tensor(6.0323)


In case of our Bigram model, the model's parameters is the probability matrix P. And we need to learn the parameters of the model, i.e. the probability matrix P in a way that the loss is as small as possible. We usually try to minimize the average negative log likelihood.


```python
def loss_function(P, words):
    log_likelihood = 0.0
    n = 0

    for w in words:
        chs = ['.'] + list(w) + ['.']
        for i in range(len(chs) - 1):
            log_likelihood += torch.log(P[stoi[chs[i]], stoi[chs[i + 1]]])
            n += 1

    return -log_likelihood/n

print(loss_function(P, words))
```

    tensor(2.4541)


If we have a biagram whose Probability in the P matrix is 0, then our loss function becomes infinite. This is not desirable and do fix this we can do **model smoothing**, which is adding a small constant to all the probabilities in the P matrix.


```python
print(loss_function(P, ["rohitjq"]))

P = (P + 1).float()
P = P / P.sum(1, keepdim=True)

loss_function(P, ["rohitjq"])

```

    tensor(inf)





    tensor(3.2875)



### Neural Net Approach for Bigram Model

Till now we have been using a lookup table to store the probability of each bigram. Instead of that we can create a neural network to learn the probability of each bigram. Let us see how we can do it. 

1. First we will create our training set, which is the first character of each biagram and y is the second character of each biagram.
2. Instead of using the stoi integer as the xs and ys, its better to one hot encode the xs and ys because neural networks usually expect continuous inputs/outputs or one hot encoded inputs/outputs.
3. Next we will neurons. In NN, a neuron takes a set of weights and examples and outputs a single number.  We will havve 27 neurons.
4. Now that we have 27 neurons, we want each neuron's otuput for each example to be probability of the second character of the bigram given the first character of the bigram. To do this we will use softmax activation function. logits are esentially log-counts.
5. Now we can calculate the loss of the inputs. Since all the operations we have done for a neuron are differentiable, we can calculate the gradient of the loss with respect to the weights of the neurons. We can then use gradient descent to update the weights of the neurons. 

What the above output tells you is that for each input, we are getting a log likelihood of how likely the model thinks the next character is. Now we want to optimise the weights of the neurons to make the log likelihood as high as possible. We can do this by using gradient descent. 


```python
import torch.nn.functional as F

# create the dataset
xs, ys = [], []
for w in words:
  chs = ['.'] + list(w) + ['.']
  for ch1, ch2 in zip(chs, chs[1:]):
    ix1 = stoi[ch1]
    ix2 = stoi[ch2]
    xs.append(ix1)
    ys.append(ix2)
xs = torch.tensor(xs)
ys = torch.tensor(ys)
num = xs.nelement()
print('number of examples: ', num)

# initialize the 'network'
g = torch.Generator().manual_seed(2147483647)
W = torch.randn((27, 27), generator=g, requires_grad=True)
```

    number of examples:  228146



```python
# gradient descent
for k in range(100):
  
  # forward pass
  xenc = F.one_hot(xs, num_classes=27).float() # input to the network: one-hot encoding
  logits = xenc @ W # predict log-counts
  counts = logits.exp() # counts, equivalent to N
  probs = counts / counts.sum(1, keepdims=True) # probabilities for next character
  loss = -probs[torch.arange(num), ys].log().mean() + 0.01*(W**2).mean() # Regularization term
  
  # backward pass
  W.grad = None # set to zero the gradient
  loss.backward()
  
  # update
  W.data += -50 * W.grad
```


```python
# finally, sample from the 'neural net' model
itos = {i: s for s, i in stoi.items()}
g = torch.Generator().manual_seed(2147483647)

for i in range(5):
  
  out = []
  ix = 0
  while True:
    
    # ----------
    # BEFORE:
    #p = P[ix]
    # ----------
    # NOW:
    xenc = F.one_hot(torch.tensor([ix]), num_classes=27).float()
    logits = xenc @ W # predict log-counts
    counts = logits.exp() # counts, equivalent to N
    p = counts / counts.sum(1, keepdims=True) # probabilities for next character
    # ----------
    
    ix = torch.multinomial(p, num_samples=1, replacement=True, generator=g).item()
    out.append(itos[ix])
    if ix == 0:
      break
  print(''.join(out))
```

    cexze.
    momasurailezityha.
    konimittain.
    llayn.
    ka.



```python

```
