# Obtain the marks secured by a student in Maths, Physics, Chemistry, Computer
# Science, and English, out of 100, and calculate their average. Check the range
# within which the average mark falls and display the appropriate grade. (A+ grade -
# 90 to 100, A grade - 80 to 90, B+ grade - 70 to 80, B grade - 60 to 70, C grade - 50
# to 60, D grade - 40 to 50, F grade - less than 40)

def calc_grade(marks):
    average = sum(marks) / len(marks)
    if 90 <= average <= 100:
        grade = 'A+'
    elif 80 <= average < 90:
        grade = 'A'
    elif 70 <= average < 80:
        grade = 'B+'
    elif 60 <= average < 70:
        grade = 'B'
    elif 50 <= average < 60:
        grade = 'C'
    elif 40 <= average < 50:
        grade = 'D'
    else:
        grade = 'F'
    return average, grade

def main():
    subjects = ['Maths', 'Physics', 'Chemistry', 'Computer Science', 'English']
    marks = []
    for subject in subjects:
        mark = float(input(f"Enter marks for {subject} out of 100: "))
        marks.append(mark)
    
    average, grade = calc_grade(marks)
    print(f"Average Marks: {average}")
    print(f"Grade: {grade}")

if __name__ == "__main__":
    main()

