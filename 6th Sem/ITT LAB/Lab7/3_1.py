import sqlite3

# create a connection and a cursor object
try:
    connection = sqlite3.connect('test.db')
    print("Opened Database Successfully")
    cursor = connection.cursor()
    print("Opened Cursor Successfully")
except Exception as e:
    print("Error occured", e)


# create the table if it does not exist
cursor.execute('''
    CREATE TABLE IF NOT EXISTS STUDENT(
    ID PRIMARY KEY NOT NULL,
    REGNO INT NOT NULL,
    BRANCH TEXT,
    SEMESTER INT,
    SECTION CHARACTER(1),
    CGPA REAL,
    EMAIL TEXT,
    CHECK (SEMESTER BETWEEN 1 AND 8)
    CHECK (CGPA < 10.0) );
    ''')


# storing the data in a python list
students = [
    (1, 180911111, 'IT', 3, 'A', 9.2, 'test1@test.com'),
    (2, 180911112, 'CSE', 3, 'B', 7.2, 'test2@test.com'),
    (3, 180911113, 'CHEM', 6, 'B', 6.1, 'test3@test.com'),
    (4, 180911114, 'ECE', 1, 'A', 9.1, 'tes4@test.com'),
    (5, 180911115, 'IT', 7, 'B', 8.86, 'test5@test.com'),
]


# Inserting data into the db
cursor.executemany("INSERT INTO STUDENT VALUES (?, ?, ?, ?, ?, ?, ?)", students)


# Displaying all rows
print("Inserted Data:")
for row in cursor.execute("SELECT * FROM STUDENT"):
    print(row)


# Searching for the student with regno = 180911111
print("Query:")
for row in cursor.execute("SELECT * FROM STUDENT WHERE REGNO = (?)", (180911111,)):
    print(row)