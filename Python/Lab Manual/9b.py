def arithmetic_progression(a, d, n):
    if n == 1:
        return [a]  # Base case: return the first term
    else:
        prev_terms = arithmetic_progression(a, d, n - 1)  # Recursive call
        next_term = prev_terms[-1] + d  # Compute next term
        prev_terms.append(next_term)  # Append to the list
        return prev_terms


a = 2   
d = 3   
n = 5   

print(arithmetic_progression(a, d, n))
