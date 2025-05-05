import copy
file_pointer = open('text.txt')
array = [[x for x in line.split()] for line in file_pointer]
print(array)
for i in range(0,len(array)):
    for j in range(0,len(array[i])):
        array[i][j] = int(array[i][j])

print("initial aray: ",array,'\n')

def hungarian_algorithm(cost_matrix):
    n = len(cost_matrix)
    matrix = copy.deepcopy(cost_matrix)

    
    for i in range(n):
        min_val = min(matrix[i])
        for j in range(n):
            matrix[i][j] -= min_val

    print("1: ",matrix,"\n")
    for j in range(n):
        col = [matrix[i][j] for i in range(n)]
        min_val = min(col)
        for i in range(n):
            matrix[i][j] -= min_val

    print("2 : ",matrix , '\n')

    def find_assignments(matrix):
        assigned_rows = set()
        assigned_cols = set()
        assignments = [-1] * n  
        zero_matrix = [[(matrix[i][j] == 0) for j in range(n)] for i in range(n)]
        print("zero_matrix",zero_matrix)
        print("assignments: ",assignments)
        def is_valid_assignment(row, used_cols):
            for col in range(n):
                if zero_matrix[row][col] and col not in used_cols:
                    used_cols.add(col)
                    print("used_colummns: ",used_cols)
                    if assignments[col] == -1 or is_valid_assignment(assignments[col], used_cols):
                        assignments[col] = row
                        print("assignments: ",assignments)
                        return True
            return False

        for row in range(n):
            is_valid_assignment(row, set())

        final_assignment = [(assignments[j], j) for j in range(n) if assignments[j] != -1]
        print("assignments: ",assignments,'\n')
        print("zero_matrix: ", zero_matrix,'\n')
        print("final assignment: ",final_assignment,'\n')
        return final_assignment

    assignment = find_assignments(matrix)

 
    while len(assignment) < n:
        
        row_covered = [False] * n
        col_covered = [False] * n

        marked_rows = set()
        marked_cols = set()

        assigned = [j for i, j in assignment]
        for i in range(n):
            if i not in [row for row, _ in assignment]:
                marked_rows.add(i)

        changed = True
        while changed:
            changed = False
            for i in marked_rows.copy():
                for j in range(n):
                    if matrix[i][j] == 0 and j not in marked_cols:
                        marked_cols.add(j)
                        for k in range(n):
                            if (k, j) in assignment and k not in marked_rows:
                                marked_rows.add(k)
                                changed = True

        for i in range(n):
            if i not in marked_rows:
                row_covered[i] = True
        for j in marked_cols:
            col_covered[j] = True

        print("marked_rows",marked_rows)
        print("marked_col",marked_cols)
        min_uncovered = min(
            matrix[i][j]
            for i in range(n) if not row_covered[i]
            for j in range(n) if not col_covered[j]
        )

        for i in range(n):
            for j in range(n):
                if not row_covered[i] and not col_covered[j]:
                    matrix[i][j] -= min_uncovered
                if row_covered[i] and col_covered[j]:
                    matrix[i][j] += min_uncovered

        assignment = find_assignments(matrix)
    print("assignment: ",assignment,'\n')
    return assignment





assignment = hungarian_algorithm(array)
total_cost = sum(array[i][j] for i, j in assignment)

print("Assignment (row -> column):", assignment)
print("Total Cost:", total_cost)