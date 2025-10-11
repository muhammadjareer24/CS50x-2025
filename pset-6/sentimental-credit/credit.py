from cs50 import get_int


def checksum(number):

    total, position = 0, 0

    while number > 0:

        digit = number % 10

        if position % 2 == 0:
            total += digit
        else:
            product = digit * 2
            total += product // 10 + product % 10

        number = number // 10
        position += 1

    return total


while True:
    card_number = get_int("Number: ")
    if card_number > 0:
        break

if checksum(card_number) % 10 == 0:
    digits = len(str(card_number))
    start = int(str(card_number)[:2])

    if digits == 15 and (start == 34 or start == 37):
        print("AMEX")
    elif digits == 16 and (51 <= start <= 55):
        print("MASTERCARD")
    elif (digits == 13 or digits == 16) and (start // 10 == 4):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
