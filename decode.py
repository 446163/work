import csv
with open('file.csv', 'rb') as f:
    reader = csv.reader(f)
    your_list = list(reader)

array = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","5","6","7","8","9"]

for item in your_list:
    print (array[item])
