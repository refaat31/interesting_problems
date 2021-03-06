# Dark or Light?
Given an NxN grid with an array of lamp coordinates. Each lamp provides illumination to every square on their x-axis, every square on their y-axis, and every square that lies in their diagonal (think of the Queen in chess). Given an array of query coordinates, determine whether that point is illuminated or not.

The catch is when checking a query, all lamps adjacent to or on that query gets turned off. If you visit a coordinate/cell, turn off all lamps that are in that coordinates or adjacent. Two cells are adjacent if they share the same edge or corner.

Write a function checkLampIllumination(N, lamps, queries)
* N : size of the grid
* lamps : coordinates of a lamp
* queries : coordinates on the grid to be checked if they are lit or not


### Test Cases
* Case 1


**Input:**

    N = 8

    lamps = [
        [1,6],
        [5,6],
        [7,3],
        [3,2]
    ]

    queries = [
        [4,4],
        [6,6],
        [8,1],
        [3,2],
        [2,3]
    ]

**Output:**

    ['DARK','LIGHT','DARK','DARK','LIGHT']


* Case 2


**Input:**

    N = 8

    lamps = [
        [4,3],
        [4,4]
    ]

    queries = [
        [3,4],
        [7,6]
    ]

**Output:**

    ['DARK','LIGHT']


[Home](../README.md)

[Problem Statement source](https://stackoverflow.com/questions/52361148/finding-coordinates-on-a-grid-2d-array)

[My Solution (approach)](../approaches/Dark_or_Light_approach.md)

[My Solution (code)](../solutions/Dark_or_Light.cpp)
