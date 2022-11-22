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
from source.ampl_to_tree import ampl_to_tree, gamma_to_tree, rightmost_operator_pos


def test_gamma():
    arr = ["gamma", "alpha1", "alpha2", "alpha3"]
    res = gamma_to_tree(arr)
    res_test = Tree("gamma", ["alpha1", "alpha2", "alpha3"])
    print(arr)
    print(res)
    assert res == res_test


def test_finished():
    arr = [Tree("gamma", ["alpha1", "alpha2", "alpha3"])]
    assert ampl_to_tree(arr) == arr[0]


def test_rightmost_operator_pos():
    arr = ["Prod(", "-1/2", "i", "Pow", "e", "2"]
    res = rightmost_operator_pos(arr)
    assert res == 3
    arr = ["Sum(", "Pow", "m_e", "2","Prod", "-1", "s_13" ,"Prod", "1/2","reg_prop", ")"]
    res = rightmost_operator_pos(arr)
    assert res == 7
