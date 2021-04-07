### Surveyor
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
### Input Format
String s
Array of length of string
### Output Format
Area
### Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment). <Br>
### Sample Test Case
"NWWSE" <br>
{10,3,7,10,10} <br>
Returns: 100 <br>
"NESWNWSW" <br>
{20,200,30,100,20,30,10,70} <Br>
Returns: 4700 <br>