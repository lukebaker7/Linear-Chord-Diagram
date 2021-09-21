# Linear-Chord-Diagram
While on the course of some research about certain attributes of linear chord diagrams I thought 
it would be easier to see patterns if I could compute some of the larger values of 'n'. 
This is where the program comes in. The file LinearChordEquationV2 is a downloadable, executable 
file that will ask for a value for the amount of n (really 2n) end points and return the amount
of diagrams with 0-n short chords.

The code can be found in function.cpp. The original equation that my group found is
A_i = (2n - i)!/((2^(n-i))(n-i)!(i)!) - (sum(k=i+1 to n) (kCi) * A_k). 
The two core functions written are dealing with the subtraction term in that equation.

In the future I would like to create a big integers class, so that the 'n' could be incredibly large.
I also would like to add an analysis option so that you could test and show a weak proof of the 
research I was working on.
