# import csv 

# file = open("csv_phonebook.csv", "a")

# name = input("Name: ")
# number = input("Number: ")

# writer = csv.writer(file)
# writer.writerow([name, number])

# file.close()

# ANOTHER WAY
import csv 

name = input("Name: ")
number = input("Number: ")

with open("csv_phonebook.csv", "a") as file:

    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    
    writer.writerow({"name": name, "number": number})

