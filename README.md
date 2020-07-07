# Bandwith-Algorithm-C-

Idea and algorithm details:
We can use different approaches for this problem. Idea is to find the Max spanning tree and compare its cost with that of given matrix. More details below.
For the given situation we have to find solution. I have used the concept of max spanning tree. And used Kruskal Algorithm for this purpose. I have changed condition to greater rather than minimum. This will give us the max spanning tree.
For finding min value in matrix we can above diagonal values as both below and above diagonal values are same.
For Impossible Condition:
Created a 3d loop for comparing the matrix and checking for all the possible combinations.
But sometimes the solution may differ because MST can give different values but it doesn’t mean that the solution is false. 
If the given matrix is regenerated from the solution then it means our solution is correct. My solution has been accepted in online judge.
Running time complexity is O(E log V)
 
