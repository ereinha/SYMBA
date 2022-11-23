from nltk.tree import Tree
import sympy as sp
from icecream import ic

sqampls_file = "data.nosync/QED_amplitudes_TreeLevel_2to2.txt"


# the amplitudes are already in hybrid prefix notation. Now writing a script to convert them to a tree is kind
# of stupid, because I had them as trees before I converted them.
# Sadly there are so many steps in between and I don't want to change them now.
# GOAL: Convert to
# - tree
# - prefix
# Since I think it easier to first go to the tree and then prefix, I'll do the tree here.


operators = {
        "ee": 3,
        "ee^(*)": 3,
        "Prod": 2,
        "Prod(": -1,  # )
        "Pow": 2,
        "gamma": 3,
        "Sum": 2,
        "Sum(": -1,  # )
}


def ampl_to_tree(arr):
    """convert hybrid prefix amplitude to nltk.Tree"""

    if len(arr) == 1:
        return arr[0]

    op_pos = rightmost_operator_pos(arr)
    if (op_pos == -1) | (op_pos == len(arr)):
        print("something went wrong, operator should not be at end of array")

    op = arr[op_pos]
    number_of_args = operators[op]
    if number_of_args == -1:
        bracket_pos = next_bracket_pos(arr, op_pos)
        func_and_args = arr[op_pos:bracket_pos]
        foo = func_to_tree(func_and_args)
        arr_new = arr[:op_pos] + [foo] + arr[bracket_pos+1:]
    else:
        foo = func_to_tree(arr[op_pos:op_pos+number_of_args+1])
        arr_new = arr[:op_pos] + [foo] + arr[op_pos+number_of_args+1:]
    return ampl_to_tree(arr_new)


def next_bracket_pos(expr_arr, op_pos):
    pos = op_pos + 1
    x = expr_arr[pos] 
    while x != ")":
        pos = pos + 1
        x = expr_arr[pos]
        if pos > len(expr_arr):
            print("Error in next_bracket_pos")
            return -1
    return pos


def rightmost_operator_pos(expr, pos=-1):
    """
    from expression get the rightmost operator position.
    The operators are in the global dictionary `operators`.

    Notes:
        - if `expr[pos]` is already a Tree, then checking if it's in `operators.keys()` fails,
        thus first check if it's a tree. (Tree not hashable)
    """
    if isinstance(expr[pos], Tree):
        return rightmost_operator_pos(expr, pos-1)
    if expr[pos] in operators.keys():
        return len(expr) + pos
    else:
        return rightmost_operator_pos(expr, pos-1)


def func_to_tree(arr):
    func = arr[0]
    args = arr[1:]
    return Tree(func, args)


if __name__ == "__main__":
    with open(sqampls_file) as f:
        ampls = f.readlines()

    print(ampls[0])
