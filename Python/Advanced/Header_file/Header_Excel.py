import pandas as pd

k=[]
st=("def")
x=open("FUNC.py","r")
t=len( x.readlines())
x.seek(0)

for i in range(t):
  
    y=x.readline() 
    g=y.split()
    if g[0]==st:
     k.append(y)

print (k)
dict = []
for i in range(len(k)):
    dict.append({
        "func": k[i],
        "ID": f"IDx0{i}"
    })
# Create a DataFrame
df = pd.DataFrame(dict)

# Specify the Excel file name
excel_file = 'example.xlsx'

# Write the DataFrame to Excel
df.to_excel(excel_file, index=False)

print(f"Data has been written to {excel_file}")
