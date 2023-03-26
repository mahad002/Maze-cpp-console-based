# Maze-cpp-console-based
An efficient console based maze which covers formulas and calculations to take steps, and automatically tell whether a maze is possible or not.

You first have to build a maze using the input file “maze.txt” with the following attributes:
1) No. of Rows and No. of Columns (2D Array) separated with space.
2) No. of Hurdles in that particular maze.
3) Indices on which you have to mark hurdles, Rows and Columns separated with space.
4) Starting point will always be (0, 0).
5) Exit point will always be last index of 2D Array. It will be calculated by you
according to rows and columns of Maze given in the text document.
NOTE: Your code should be generic and should build a maze using any file with similar
format!
For Example: A maze of 5 rows, 5 columns, and 7 hurdles. Indices containing hurdles are
(0,3),(1,4),(2,2),(3,1),(4,0),(1,1),(2,4).
Starting point is (0, 0) and exit point in this case is (4, 4)
1 shows the hurdles; you can use any character for hurdles. S shows the starting point and E
shows the exit point.

Once the maze is created you have to find the path from starting point to the exit point using
STACKS linked list-based implementation(no recursion).
You should compute a path that leads you from starting point (row 0, column 0) to the exit.
If no such path exists, your program should be able to tell the user that maze has no exit.
As you are using stacks so you have to push the indices of array onto stack and make sure no
indices should be repeated.
At the end when you print your stack items, it should print the path from starting point to the exit
(think of logic here). If no path exists then the program shall print that no solution exists
