import pandas as pd 
import os

data=[]
def add_employee(Name,Job,salary):
  data.append({
  'Name':Name,
  'Job':Job,
  'Salary':salary
      })

def print_data(Name):
  for i in data:
     if i.get('Name') == Name:
       print(i)

def remove_data(Name):
    for i in data:
     if i.get('Name') == Name:
       data.remove(i)

def Upadate_data(Name,job,salary):
 for i in data:
     if i.get('Name') == Name:
       i.update({'Job':job})
       i.update({'Salary':salary})


add_employee('nouran','engineer',1000)
print_data('nouran')
add_employee('noureen','doctor',1200)
print_data('noureen')
remove_data('nouran')
print_data('nouran')
add_employee('nouran','engineer',1000)
Upadate_data('nouran','doctor',500)
print_data('nouran')

# Create a DataFrame
df = pd.DataFrame(data)

# Specify the Excel file name
excel_file = 'Data.xlsx'

#check if excel file exists if not create one
if not os.path.exists(excel_file):
   # Write the DataFrame to Excel
    df.to_excel(excel_file, index=False)
    print(f"Excel file has been created and Data has been written to {excel_file}")
else :    
   df.to_excel(excel_file, index=False)
   print(f"Data has been written to {excel_file}")

