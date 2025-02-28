fruits = [
    "apple", "banana", "mango", "grape", "orange", 
    "strawberry", "blueberry", "pineapple", "watermelon"
]

def matchscore(word):
    best_score = 0
    best_match = ""

    for a in fruits:
        count = 0  # Reset count for each word comparison

        for i in range(min(len(word), len(a))):  # Avoid index errors
            if a[i] == word[i]:
                count += 1

        score = count / max(len(a), len(word))  # Calculate score properly

        if score > best_score and score > 0.5:
            best_match = a
            best_score = score

    return best_match  # Return best match instead of printing inside loop

def autocomplete(word):
    match = []

    if len(word) == 1:
        for i in fruits:
            if word in i:
                print(i)

    elif word in fruits:
        print(word)

    else:
        best_match = matchscore(word)  # Use the fixed matchscore function
        if best_match:
            print(f"Is it ṭ: {best_match}?")
        else:
            print("No close match found.")

while True:
    word = input("Enter the word: ").strip().lower()

    if word == "exit":
        break
    
    autocomplete(word)
