l = input("Enter the contents of the list seperated by space:\n").split(" ")
print('Palidrome' if  all([ l[i] == l[len(l)-i-1] for i in range(len(l)//2) ]) else 'Not Palindrome')