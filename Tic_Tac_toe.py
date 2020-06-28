from array import *
matrix = [[' '] * 3 for i in range(3)]
winner = False

def display() :
    for i in range(3) :
        for j in range(3) :
            if j < 2 :
                print( str(matrix[i][j]) + "\t\t |",end = "")
            else :
                print(matrix[i][j],end = "")
        print()
        if i < 2 :
            print("--------------------------------")

def move(c):
    print("Choose your move (row [ 1 -3 ] and column [ 1 - 3 ] :-    ")
    row = int(input())
    column = int(input())

    row -= 1
    column -= 1

    if matrix[row][column] == 'X' or matrix[row][column] == 'O' :
        print("Are you illiterate?????? Giving you another try")
        move(c)
    else :
        matrix[row][column] = c
        display()

def check_Move(c):
    global winner
    row_count, column_count, left_diagonal_count, right_diagonal_count = 0, 0, 0, 0

    for i in range(3) :
        for j in range(3) :
            if matrix[i][j] == c :
                row_count ++ 1
            if matrix[j][i] == c :
                column_count += 1
            if i == j and matrix[i][j] == c :
                left_diagonal_count += 1
            if i == 3-j-1 and matrix[i][j] == c :
                right_diagonal_count += 1
        if row_count == 3 or column_count == 3 :
            winner = True
        else :
            row_count = 0
            column_count = 0
    if right_diagonal_count == 3 or left_diagonal_count == 3 :
        winner = True
    if winner :
        print( c + " Won....")

for i in range(1,10) :
    if not winner :
        if i%2 == 0 :
            move('O')
            check_Move('O')
        else :
            move('X')
            check_Move('X')
    else :
        print("Game over........")
        break
if not winner :
    print("Match Draw............")
