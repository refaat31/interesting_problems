# Dark or Light? (My Approach)

**Assumptions made**:
* The queries are independent of each other.

**Input**:
* N - size of grid
* noOfLamps 
* noOfQueries

**Output**:
* Dark or Light?

### Approach explained :

First of all, for each queried position, I copy the original given lamp array.

***Weeding out Lamps***

Then, I check the adjacent positions of the queried position. 
If it contains a lamp, then I set that position to {-1,-1}, meaning I am pretending that the lamp does not exist. 
Watch out for query position == lamp position. If such a case is found, we should ignore that lamp too.

***The Final Check***

Then, all I have to do is see if the queried position matches any of the remaining lamps' columns/rows/diagonals.
If it does, then the answer is 'LIGHT', else 'DARK'.




[Home](../README.md)

[Problem Statement](./problem_statements/Dark_or_Light.md)

[My Solution (code)](../solutions/Dark_or_Light.cpp)