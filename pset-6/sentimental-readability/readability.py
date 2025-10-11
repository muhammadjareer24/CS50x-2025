
text = input("Text: ")

letters = sum(1 for ch in text if ch.isalpha())
words = len(text.split())
sentences = sum(text.count(p) for p in ".!?")


L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
