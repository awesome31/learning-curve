'''
    Data Preprocessing

    Usually the data that we get is not ready-made tensors and is messy data stored in arbitrary formats. 
    Data preprocessing is the process of cleaning and preparing the data for analysis. We will list down the
    most common routines

    Data Preprocessing is an important step in the machine learning pipeline and can get very complicated.
    
    Q: How would you deal with data that has a very large number of categories? What if the category labels are all unique? Should you include the latter?
    A: If too many categories, try to manually find catgories that are common to each other and group them as one. If they’re all far too different from each other, you’re most likely out of luck, or you can take the information hit and still do the merging of categories to the extent possible

       If the categories are all unique, meaning number of categories == number of samples in dataset, just drop the column, since the column is carrying no useful information, just like a column that only has 1 value. All values are different(if all unique) or same(if all same) no matter the value of the rest of the attributes, there is no pattern to be found here
'''

import pandas as pd
import os
import torch

print("Making a new directory data and creating a new CSV File")
os.makedirs(os.path.join('..', 'data'), exist_ok=True)
data_file = os.path.join('..', 'data', 'house_tiny.csv')
with open(data_file, 'w') as f:
     f.write('''NumRooms,RoofType,Price
                NA,NA,127500
                2,NA,106000
                4,Slate,178100
                NA,NA,140000''')


print("Reading the CSV file")
df = pd.read_csv(data_file)
print(df)
print("\n")

print("There are 2 ways to handle missing values in a data frame. Imputing or Deleting.")
print("Imputing: Filling the missing values with a specific value.")
df['NumRooms'] = pd.to_numeric(df['NumRooms'], errors='coerce')
inputs, target = df.iloc[:, 0:2], df.iloc[:, 2]
inputs = pd.get_dummies(inputs, dummy_na=True)
inputs = inputs.fillna(inputs.mean())
print(inputs)
print("\n")

print("Deleting: Removing the rows with missing values.")
newDf = df.dropna()
print(newDf)
print("\n")

print("Converting it back to a tensor.")
X = torch.tensor(inputs.to_numpy(dtype=float))
y = torch.tensor(target.to_numpy(dtype=float))
print(X, y)

