from nltk.tree import Tree
import sympy as sp
from icecream import ic

sqampls_file = "data.nosync/QED_amplitudes_TreeLevel_2to2.txt"


# the amplitudes are already in hybrid prefix notation since I exported them like this from MARTY.
# GOAL: Convert to
# - tree
# - prefix
# Since I think it easier to first go to the tree and then prefix, I'll do the tree here.

# basis functions and how many arguments
basis_functions = {
                  "ee": 3,
                  "ee^(*)": 3
}

operators = {
        "Prod": 2,
        "Prod(": -1,
        "Mul": 2,
        "Mul(": -1,
        "Pow": 2,
}

def ampl_to_tree(arr):
    if len(arr) == 1:
        return arr[0]

    op_pos = rightmost_operator_pos(arr)
    return 0


def rightmost_operator_pos(expr, pos=-1):
    # operators = list(operators_inv.keys()) + ["s+", "s-"] + variables
    if expr[pos] in operators.keys():
        return len(expr) + pos
    else:
        return rightmost_operator_pos(expr, pos-1)


def gamma_to_tree(arr):
    """take array [gamma, idx1, idx2, idx3] and return tree"""
    gam = arr[0]
    indices = arr[1:]
    return Tree(gam, indices)


if __name__ == "__main__":
    with open(sqampls_file) as f:
        ampls = f.readlines()

    print(ampls[0])
