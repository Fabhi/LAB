def printMat(x):
    for i in range(len(x)):
        for j in range(len(x[i])):
            print(x[i][j], end=" ")
        print()

R, C = map(int, input("Enter the number of rows and columns: ").split())
A = [[0]*C for i in range(R)]
B = [[0]*C for i in range(R)]

print("Enter the values for matrix A: ")
for i in range(R):
    for j in range(C):
        A[i][j] = int(input("A[{0}][{1}] = ".format(i,j)))
printMat(A)

print("\nEnter the values for matrix B: ")
for i in range(R):
    for j in range(C):
        B[i][j] = int(input("B[{0}][{1}] = ".format(i,j)))
printMat(B)

new = [[0]*C for i in range(R)]
for i in range(R):
    for j in range(C):
        new[i][j] = A[i][j] + B[i][j]

print("\nSum of two matrices: ")
printMat(new) 
