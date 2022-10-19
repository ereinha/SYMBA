# Problem
I think the hybrid prefix format is not good.
Also, I want to try tree2tree or graph2graph models.
For this I need a better setup.

# Setup
I cannot have the amplitudes and the squared amplitudes in the exact same format,
since the amplitudes have Lorentz indices etc.
Thus I have the following plan:

## Amplitudes
Should be in an easy to use format where I can quickly get the tree and then work with it.
Each model should then do the preprocessing itself.

Right now I only have hybrid prefix format, which I cannot parse.

## Squared Amplitudes
They have to be simplified with sympy, but then not further modified.
Then I need functions to convert sympy to prefix and hybrid prefix notation.
Later I will need a function to convert sympy to tree.
