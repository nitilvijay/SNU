fruits = [
    "apple", "banana", "mango", "grape", "orange",
    "strawberry", "blueberry", "pineapple", "watermelon"
]

def similarity_score(word1, word2):
    """Calculate similarity score by comparing characters."""
    word1 = word1.lower()
    word2 = word2.lower()

    matches = 0
    length = min(len(word1), len(word2))

    for i in range(length):
        if word1[i] == word2[i]:
            matches += 1

    score = matches / max(len(word1), len(word2))
    return score


def autocomplete(user_input):
    """Return matching fruit suggestions."""
    user_input = user_input.lower().strip()

    if len(user_input) == 1:
        # Return all fruits containing the letter
        matches = [fruit for fruit in fruits if user_input in fruit]

    elif user_input in fruits:
        # Return exact match
        matches = [user_input]

    else:
        # Find the closest match
        best_match = ""
        best_score = 0.0

        for fruit in fruits:
            score = similarity_score(user_input, fruit)

            if score > best_score and score > 0.5:
                best_match = fruit
                best_score = score

        matches = [best_match] if best_match else ["No match found"]

    return matches



while True:
    query = input("Type a fruit name (or 'exit' to quit): ")

    if query.lower() == "exit":
        print("Exiting program...")
        break

    results = autocomplete(query)
    print("Suggestions:", results)
