# EQUATION SOLVER
This tool provides a solution for solving linear, quadratic and cubic equations.
Each equation is represented as pack of coefficients: 2 for linear,
3 for quadratic and 4 for cubic.

## Architecture???

Each equation is solved in following steps described below. As we have 
a set of equations, all steps are taken sequentially for each equation
until reaching the end of input data:

### 1. Get equation coefficients:
There is two ways to get coeffs for equations:
- read path to file with coeffs from command line
- read coeffs directly from the command line

File with coeffs content looks as follows, where each line refers to
one equation, and type of equation depends on number of coefficients
in the line:
```
1 2 3
4 5
6 7 8 9
....
```
Command line arguments look as follows, where *L*, *Q* and *C*
mark the type of equation - linear, quadratic and cubic relatively:
```
Q 1 2 3 L 4 5 C 6 7 8 9
```

To read coefficients the `Reader` interface is used, that has two realizations:
depending on how input data is presented (file or command line) `FileReader`
 or `CommandlineReader` class is used. The specific realization (reader) to use
is been chosen using the readers factory - `createReader` class.

Reader returns coeffs for each equation as vector of strings.

### 2. Parse equation coefficients:
Parsing of the coefficients pack is realized using the `parseCoeffs` function.
It does the following:
 - Check if the input coefficients could me converted to integer values
 - Crop zero-value from the beginning of coefficients pack if exists, 
as zero coefficient reduces equation to lower-order and we don't need
to pass it further.
 - Returns vector of int coefficients

### 3. Creating an equation object:
Equation is represented by interface `Equation` which has three realizations
based on equation type: `LinearEquation`, `QuadraticEquation` and `CubicEquation` classes.
Vector of coefficients obtained at previous step is passed to the constructor
of the Equation object.
Choosing type of equation and creating corresponding equation object
is done using equation factory - `createEquation` function.
Factory returns a unique pointer to an equation object of `LinearEquation`
or `QuadraticEquation` or `CubicEquation` class.
Equation object has fields that store coefficients as std::vector<int>, 
roots as std::vector<double> and solved/not solved status as bool.

### 4. Solving an equation:
Solving the equation is done by calling method `solve` on the `Equation` object.
As a result the roots field of the object is updated with calculated root values.
Also isSolved field is set to True.

### 5. Print result
Get roots vector from the equation object, print the result
(coefficients, roots) of the equation using `printEq` function.

## Tests
### Unit tests
Unit tests conducted using GTest library.
### Integration tests
Integration tests - Python module `test_integration.py`.
Requires setting environmental variable `EQ_EXECUTABLE` - path to the `eq_app` build


## Dependencies
 - GTest

## Repo structure
`eq_app` - main application

`eq_lib` - main application

`eq-tests` - GTest-based unit tests for eq_lib

`integration_tests` - python module for integration tests