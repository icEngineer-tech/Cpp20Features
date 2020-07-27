We can create a span from arrays or vectors since they're respresented in a contigious memory. A span is cheap to copy as to construct. we can use span to change the value of a
vector or an array. So we can create a span from a vector or an array. the span references a one of these containers, it doesn't own them. all we know that the size of a vector 
can change so we say that the span has a dynamic extent. we can also create a fixed-size span from a fixed-size array.
