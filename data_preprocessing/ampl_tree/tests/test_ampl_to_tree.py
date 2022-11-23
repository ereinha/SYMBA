import sys
import os
from icecream import ic 
import numpy as np
import sympy as sp
from nltk.tree import Tree

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

import sympy as sp
from source.ampl_to_tree import ampl_to_tree, rightmost_operator_pos, func_to_tree


def test_func_to_tree():
    arr = ["gamma", "alpha1", "alpha2", "alpha3"]
    res = func_to_tree(arr)
    res_test = Tree("gamma", ["alpha1", "alpha2", "alpha3"])
    assert res == res_test
    arr = ["Prod", "a", "b"]
    res = func_to_tree(arr)
    res_test = Tree("Prod", ["a", "b"])
    assert res == res_test


def test_finished():
    arr = [Tree("gamma", ["alpha1", "alpha2", "alpha3"])]
    assert ampl_to_tree(arr) == arr[0]


def test_rightmost_operator_pos():
    arr = ["Prod(", "-1/2", "i", "Pow", "e", "2", ")"]
    res = rightmost_operator_pos(arr)
    assert res == 3
    arr = ["Sum(", "Pow", "m_e", "2","Prod", "-1", "s_13" ,"Prod", "1/2","reg_prop", ")"]
    res = rightmost_operator_pos(arr)
    assert res == 7


def test_hybrid():
    arr = ["Prod(", "-1/2", "a", "b", ")"]  # )
    res = ampl_to_tree(arr)
    assert res == Tree("Prod(", ["-1/2", "a", "b"])  # )

    arr = ["Prod(", "-1/2", "a", "b", "Pow", "e", "2", ")"]  # )
    res = ampl_to_tree(arr)
    ic(res)
    res.pretty_print()
    assert res == Tree("Prod(", ["-1/2", "a", "b", Tree("Pow", ["e", "2"])])  # )


def test_ampl_to_tree():
    arr = ["Prod", "-1/2", "Pow", "e", "2"]
    res = ampl_to_tree(arr)
    assert res == Tree("Prod", ["-1/2", Tree("Pow", ["e", "2"])])

    arr = ["Prod", "-1/2", "Sum", "e", "2"]
    res = ampl_to_tree(arr)
    assert res == Tree("Prod", ["-1/2", Tree("Sum", ["e", "2"])])

    arr = ["Prod", "-1/2", "Prod", "e", "2"]
    res = ampl_to_tree(arr)
    ic(res)
    assert res == Tree("Prod", ["-1/2", Tree("Prod", ["e", "2"])])

    arr = ["Prod", "-1/2", "gamma", "alpha_1", "alpha_2", "alpha_3"]
    res = ampl_to_tree(arr)
    ic(res)
    assert res == Tree("Prod", ["-1/2", Tree("gamma", ["alpha_1", "alpha_2", "alpha_3"])])

    arr = ["Prod", "Pow", "i", "-1/2", "gamma", "alpha_1", "alpha_2", "alpha_3"]
    res = ampl_to_tree(arr)
    ic(res)
    res.pretty_print()
    # assert res == Tree("Prod", ["-1/2", Tree("gamma", ["alpha_1", "alpha_2", "alpha_3"])])

