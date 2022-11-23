from nltk.tree import Tree
import sympy as sp
from icecream import ic
import copy

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
        "b": 3,
        "b^(*)": 3,
        "A": 3,
        "A^(*)": 3,
        "Prod": 2,
        "Prod(": -1,  # )
        "Pow": 2,
        "gamma": 3,
        "Sum": 2,
        "Sum(": -1,  # )
}


def ampl_to_tree(arr, remove_hybrid_parentheses=False):
    """convert hybrid prefix amplitude to nltk.Tree
    Hybrid prefix is either normal prefix or prefix where there are products/sums with
    arbitrary number of arguments. They work like this:
        ["Prod(", "a1", "a2", "a3", ")"]
    Watch out, if you `remove_hybrid_parentheses` and then do the round-trip with
    `tree_to_prefix` with `hybrid=False`, then the result is wrong, because
    there will be things like [Prod(, 1, 2, 3, )] --> [Prod, 1, 2, 3]
    """

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
        if remove_hybrid_parentheses:
            func_and_args[0] = func_and_args[0][:-1]
        foo = func_to_tree(func_and_args)
        arr_new = arr[:op_pos] + [foo] + arr[bracket_pos+1:]
    else:
        foo = func_to_tree(arr[op_pos:op_pos+number_of_args+1])
        arr_new = arr[:op_pos] + [foo] + arr[op_pos+number_of_args+1:]
    return ampl_to_tree(arr_new, remove_hybrid_parentheses=remove_hybrid_parentheses)


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


def tree_to_prefix(tree, hybrid=False):
    """converts a tree to an array in prefix notation.
    Automatically detects hybrid prefix if an operator is like `Prod(` )
    If operators don't have parentheses, you can still go to hybrid prefix with
    `hybrid=True`. Default is `False`
    """
    arr = []
    node = tree.label()
    if hybrid and (node in ["Sum", "Prod"]) and (len(tree)>2):
        node = node + "("  # )
    arr.append(node)
    for i in range(len(tree)):
        if isinstance(tree[i], Tree):
            arr = arr + tree_to_prefix(tree[i], hybrid=hybrid)
        else:
            arr.append(tree[i])

    if node[-1] == "(":  # )
        arr.append(")")
    return arr


def expand_tree(tree):
    """
    If the tree has Prod or Sum nodes with more than 2 arguments
    --> expand them to only have 2
    """
    if not isinstance(tree, Tree):
        return tree
    node = tree.label()
    nodes_considered = ["Sum", "Sum(", "Prod", "Prod("]  # ))
    if node[-1] == "(":  # )
        node = node[:-1]
        tree.set_label(node)
    if (node in nodes_considered) and (len(tree) > 2):
        leaves = [expand_tree(t) for t in tree[1:]]
        tree[0] = expand_tree(tree[0])
        tree[1] = expand_tree(Tree(node, leaves))
        del tree[2:]
    else:
        tree[0:] = [expand_tree(t) for t in tree[0:]]
    return tree


def contract_tree(tree, runs=0, add_opening_bracked=True):
    """inverse of `expand_tree`, not fully tested.

    Note: This implementation is not fully tested and probably not working 100%.
    One problem was that it didn't work at all depths.
    Right now my workaround is that I just run it three times and hope all
    cases are caught, but I don't think so.
    """

    if runs>2:
        return tree
    if not isinstance(tree, Tree):
        return tree
    node = tree.label()
    nodes_considered = ["Sum", "Sum(", "Prod", "Prod("]  # ))
    if (node in nodes_considered) and (isinstance(tree[1], Tree)) and (tree[1].label() == node):
        node = node + "("  # )
        tree.set_label(node)
        subtree = contract_tree(tree[1])
        # del[tree[1:]]
        tree[0:] = tree[0:1] + subtree[0:]
    else:
        tree[0:] = [contract_tree(t) for t in tree[0:]]
    return contract_tree(tree, runs=runs+1)


if __name__ == "__main__":
    with open(sqampls_file) as f:
        ampls = f.readlines()

    print(ampls[0])
    print(ampls[100])
    print(ampls[-1])
    print(ampls[-20])
