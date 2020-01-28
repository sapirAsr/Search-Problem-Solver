# milestone2
Made by: Michal Rahimi and Sapir Asras.

### Milestone 2 - Advanced Programming 1
This project implements several search algorithms and compare which one is the best in solving a problem on server side.

We used the following interfaces in order to keep our program generic and able to handle different problems easily:
- Server
- Client Handler
- Solver
- CacheManager
- Searcher
- Searchable

##### Server:
We have a server interface with 2 implementations
 one is a serial server which accepts clients one by one.
the second is a parallel server which accepts clients parallely.

##### Client Handler:
We have 2 implementations to this interface:
A client that sends strings and expects to get the string reverse
A client that sends matrix with a start point and an end point and expects to get the cheapest path in the matrix.

##### Solver:
The classes that implement this interface are solving the problem as we defined it.

##### CacheManager:
The classes that implement this interface are saving our solutions in files.

##### Searcher:
The classes that implement this interface are searching for a solution to a search problem.
The classes are: BFS, DFS, BestFirstSearch, AStar.

##### Searchable:
The classes that implement this interface are able to have a search on them.
For example: giving a matrix we can run a searcher such as BFS and get a solution.

In our program we conducted an experiment which tests which search algorithm is the best to solve our problem. We found that AStar is the best and its implementation is used in our main.

#### How to compile:
Run this command in a linux environment:

```
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
```


#### How to run:
This program requires a port for the server in the command line.
If it didn't receive a port number the program will run port 5400:
```
./a.out <port_number>
```

Link to git: https://github.com/sapirAsr/milestone2



