# SYMBA-Prefix

This is the repo for my Google Summer of Code project called SYMBA.
SYMBA stands for Symbolic Calculation of Squared Amplitudes (of Feynman diagrams) and builds on
[this paper](https://arxiv.org/abs/2206.08901).
I have appended "prefix" because my main goal was to extend the representation of the expressions
to prefix notation.

For a lot of information see the accompanying [blog posts](https://boggog.github.io/).

# What?
Feynman diagrams are the building blocks of calculations in Quantum Field Theory and important
for everything from theoretical research to measurements at the LHC.
Their calculation can be very time intensive even on the best computers.
A [recent paper](https://arxiv.org/abs/2206.08901) has shown that neural networks can be effective
at the calculation of the squared amplitudes of the diagrams.
The squared amplitude can be used to get the cross section of a process, which roughly amounts to the
probability of the process happening.
Through the probabilities of processes and a lot of staticstics,
physicists can evaluate experimental data e.g. from the LHC.
This is also how the Higgs boson was discovered in 2021 by [ATLAS](https://arxiv.org/abs/1207.7214) and [CMS](https://arxiv.org/abs/1207.7235).

# How?
- Data of amplitudes and squared amplitudes of Feynman diagrams in Quantum Electro Dynamics (QED) and
Quantum Chromo Dynamics (QCD) is generated using [MARTY](https://marty.in2p3.fr/).
- The data is then preprocessed including simplification, conversion to prefix notation and shortening of sequences through token-joining.
- a neural network is trained on amplitude to squared amplitudes. The task is similar to natural language processing, specifically language translation.

# What is new?
The [SYMBA paper](https://arxiv.org/abs/2206.08901) uses the expressions directly in the given infix format.
I have developed a way of transforming them to prefix notation and also developed a hybrid prefix notation
in order to get shorter sequences.

# Results?
The training of the models can be seen in the [models folder](https://github.com/BoGGoG/SYMBA-Prefix/tree/main/models).
The evaluation is in the evaluations folder, [QED](https://github.com/BoGGoG/SYMBA-Prefix/tree/main/models/QED/Evaluation) and [QCD]().

