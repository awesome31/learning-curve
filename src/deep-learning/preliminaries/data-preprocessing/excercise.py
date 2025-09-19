import pandas as pd

column_names = [
    'Sex', 
    'Length', 
    'Diameter', 
    'Height', 
    'Whole weight', 
    'Shucked weight', 
    'Viscera weight', 
    'Shell weight', 
    'Rings'
]

df = pd.read_csv('abalone.data', header=None, names=column_names)
print(df.head())
print(df['Sex'])
print("The size of the data frame is", df.shape)

print("Accessing specific columns", df[['Sex', 'Length', 'Diameter']][: 20])