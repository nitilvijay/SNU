fruits = [
    "apple", "banana", "mango", "grape", "orange", 
    "strawberry", "blueberry", "pineapple", "watermelon"
]

def similarity_score(word1, word2):
    """Calculate a similarity score between two words based on character matches."""
    word1, word2 = word1.lower(), word2.lower()
    matches = sum(1 for a, b in zip(word1, word2) if a == b)
    return matches / max(len(word1), len(word2))  # Normalized similarity

def autocomplete(user_input):
    """Return matching fruit suggestions based on user input."""
    user_input = user_input.lower().strip()
    
    if len(user_input) == 1:
        # If a single letter is typed, return all fruits containing that letter
        matches = [fruit for fruit in fruits if user_input in fruit]
    elif user_input in fruits:
        # If input exactly matches a fruit, return it alone
        matches = [user_input]
    else:
        # Find the closest match using similarity scoring
        best_match = ""
        best_score = 0.0
        
        for fruit in fruits:
            score = similarity_score(user_input, fruit)
            if score > best_score and score > 0.5:  # Threshold for matching
                best_match = fruit
                best_score = score
        
        matches = [best_match] if best_match else ["No match found"]
    
    return matches

if __name__ == "__main__":
    while True:
        query = input("Type a fruit name (or part of it): ")
        
        if query.lower() == "exit":
            break  # Exit the loop
        
        results = autocomplete(query)
        print("Suggestions:", results)
