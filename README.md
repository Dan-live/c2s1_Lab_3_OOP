# k2s1_Lab_3_OOP
A mathematical vector of any dimension and with any type of
element (specified by the template parameters).
Implement the following operations:
 Constructing a vector: by default, copying, by
repeating the specified value (and, optionally, others).

2
 Convert (construct) a vector from another vector of the same
size, but with a different type of element.
 Access by index to an element for reading and writing. At the same time
allow negative indices, which means access to elements from the
from the end. For example, for a vector of 10 elements, v[-1] == v[9],
v[-2] == v[8], etc.
 Getting the size of a vector (number of elements).
 Operations of addition, subtraction, multiplication and division of all elements
of a vector (using operator overloading) by some single
value (scalar), as well as another vector of the same size
(elementwise). Provide for the possibility of using values of
of another type (implement as templates). To get
the maximum score independently (without using library
functions) to implement the correct output of the result type (selecting the
the broadest type).
 Templates of methods for changing the dimension of a vector (the value is set
as a parameter of the template), converting the type of the vector (the type is specified as
as a template parameter). When increasing the size, all new elements
are filled with default values. The result is a new
vector. For example: v.resize<20>() and v.convert<float>().
 A method template that implements getting a "slice" of a vector, ie,
a vector containing elements of the original vector from a certain range of
of indices. The start and end indices are set by the parameters
parameters of the template. At the same time, to get the maximum score, you should
negative indices are allowed, which means access to elements from the
end, as well as the reverse order of the indices, which should lead to
"reversal" of the vector. The result is a new vector. For example:
let the vector v contain 7 elements: 1, 2, 3, 4, 5, 6, 7, then
v.slice<2, 4>() will generate a vector of 3 elements: 3, 4, 5;

3

v.slice<1, -2>() will generate a vector of 5 elements: 2, 3, 4, 5, 6;
v.slice<5, 2>() generates a vector of 4 elements: 6, 5, 4, 3.
 The weighted sum of elements of vectors of the same size. You are given two
vectors and their corresponding weighting factors (α, β). The result is
a new vector whose elements contain the values:
x = αx1 + βx2, where x1 and x2 are the values of the elements of the first and
of the second vector, respectively. Provide for the possibility of using vectors with
values of different types (implement as a template).
Example: v = weighted_sum(v1, 0.7, v2, 3.2).
 Concatenation of two vectors, which gives rise to a larger vector
which includes elements of the first and then the second vector.
Provide for the possibility of concatenating vectors with different types of
of elements. To get the maximum score independently (without
using library functions) to implement the correct output of the
of the result type (selecting the widest type).
 As an additional task (for extra points)
the possibility of concatenating an arbitrary number of
vectors by calling a single function. Example:
auto a = concat(v2, v4);
auto b = concat(v1, v2, v3, v4);
 As an additional task (for extra points)
you can also implement the function of constructing a vector for a given
set of values, for example:
v = make_vector<int>(1, 2, 3, 4, 5) - a vector with elements of type int, or
v = build_vector(1, 2,.0f, 3.0) - automatically displays the type of
of the element.
 The function names are given as an example only and can be
changed at the discretion of the developer.
#
![image](https://github.com/Dan-live/k2s1_Lab_3_OOP/assets/109356212/291289c5-ae4a-4849-a4f8-04dad92b2d2a)
