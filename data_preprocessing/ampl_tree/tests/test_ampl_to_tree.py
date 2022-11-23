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
from source.ampl_to_tree import ampl_to_tree, rightmost_operator_pos, func_to_tree, tree_to_prefix


def test_func_to_tree():
    arr = ["gamma", "alpha1", "alpha2", "alpha3"]
    res = func_to_tree(arr)
    res_test = Tree("gamma", ["alpha1", "alpha2", "alpha3"])
    assert res == res_test
    arr = ["Prod", "a", "c"]
    res = func_to_tree(arr)
    res_test = Tree("Prod", ["a", "c"])
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
    arr = ["Prod(", "-1/2", "a", "c", ")"]  # )
    res = ampl_to_tree(arr)
    assert res == Tree("Prod(", ["-1/2", "a", "c"])  # )

    arr = ["Prod(", "-1/2", "a", "c", "Pow", "e", "2", ")"]  # )
    res = ampl_to_tree(arr)
    ic(res)
    res.pretty_print()
    assert res == Tree("Prod(", ["-1/2", "a", "c", Tree("Pow", ["e", "2"])])  # )


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


def test_full_ampls():
    arr = "Prod(,-1/2,i,Pow,e,2,Pow,Sum(,Pow,m_e,2,Prod,-1,s_13,Prod,1/2,reg_prop,),-1,gamma,alpha_4,alpha_2,alpha_0,gamma,alpha_4,alpha_3,alpha_1,ee,i_0,alpha_0,(p_1)_u,ee,i_2,alpha_1,(p_2)_u,ee^(*),i_3,alpha_2,(p_3)_u,ee^(*),i_1,alpha_3,(p_4)_u,)"
    arr = arr.split(",")
    res = ampl_to_tree(arr)
    res.pretty_print()

    arr = "Prod(,1/9,i,Pow,e,2,Pow,Sum(,Pow,m_b,2,Prod,-1,s_11,Prod,2,s_13,Prod,-1,s_33,Prod,-1,reg_prop,),-1,Sum(,Prod(,m_b,gamma,alpha_12,alpha_3,alpha_6,gamma,alpha_13,alpha_6,alpha_0,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_3,(p_1)_u,b,i_2,alpha_0,(p_2)_v,),Prod(,p_1,alpha_11,gamma,alpha_11,alpha_7,alpha_8,gamma,alpha_12,alpha_4,alpha_7,gamma,alpha_13,alpha_8,alpha_1,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_4,(p_1)_u,b,i_2,alpha_1,(p_2)_v,),Prod(,-1,p_3,alpha_11,gamma,alpha_11,alpha_9,alpha_10,gamma,alpha_12,alpha_5,alpha_9,gamma,alpha_13,alpha_10,alpha_2,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_5,(p_1)_u,b,i_2,alpha_2,(p_2)_v,),),)"
    arr = arr.split(",")
    res = ampl_to_tree(arr)


def test_tree_to_prefix():
    arr = ["Prod", "-1/2", "Pow", "e", "2"]
    tree = ampl_to_tree(arr)
    round_trip = tree_to_prefix(tree)
    assert arr == round_trip

    arr = ["Prod", "-1/2", "gamma", "alpha_1", "alpha_2", "alpha_3"]
    tree = ampl_to_tree(arr)
    round_trip = tree_to_prefix(tree)
    assert arr == round_trip

    arr = ["Prod", "Pow", "i", "-1/2", "gamma", "alpha_1", "alpha_2", "alpha_3"]
    tree = ampl_to_tree(arr)
    round_trip = tree_to_prefix(tree)
    assert arr == round_trip


    arr = "Prod(,1/9,i,Pow,e,2,Pow,Sum(,Pow,m_b,2,Prod,-1,s_11,Prod,2,s_13,Prod,-1,s_33,Prod,-1,reg_prop,),-1,Sum(,Prod(,m_b,gamma,alpha_12,alpha_3,alpha_6,gamma,alpha_13,alpha_6,alpha_0,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_3,(p_1)_u,b,i_2,alpha_0,(p_2)_v,),Prod(,p_1,alpha_11,gamma,alpha_11,alpha_7,alpha_8,gamma,alpha_12,alpha_4,alpha_7,gamma,alpha_13,alpha_8,alpha_1,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_4,(p_1)_u,b,i_2,alpha_1,(p_2)_v,),Prod(,-1,p_3,alpha_11,gamma,alpha_11,alpha_9,alpha_10,gamma,alpha_12,alpha_5,alpha_9,gamma,alpha_13,alpha_10,alpha_2,A,i_3,alpha_12,(p_3),A,i_1,alpha_13,(p_4),b^(*),i_0,alpha_5,(p_1)_u,b,i_2,alpha_2,(p_2)_v,),),)"
    arr = arr.split(",")
    tree = ampl_to_tree(arr)
    round_trip = tree_to_prefix(tree)
    assert arr == round_trip
    
