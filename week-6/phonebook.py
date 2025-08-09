# USING LIST

# people = [
#     {"name": "Jareer", "number": "12345"},
#     {"name": "Khan", "number": "125999"},
#     {"name": "Osama", "number": "777745"},
# ]

# name = input("Name: ")
# for person in people:
#     if person["name"] == name:
#         number = person["number"]
#         print(f"Found {number}")
#         break
# else:
#     print("Not Found")    

# USING DICT
people = {
    "Jareer" : "12345",
    "Khan" : "125999",
    "Osama" : "777745",
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found.")