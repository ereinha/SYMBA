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
from source.ampl_to_tree import ampl_to_tree, rightmost_operator_pos, func_to_tree, tree_to_prefix, expand_tree, contract_tree, get_tree, ampl_raw_tree_to_nltk
from source.ampl_to_tree import has_subscript, subscripts_to_subtree, is_basis_func, basis_function_to_subtree, nltk_tree_expand_subscripts, p_sub_to_tree


def test_tree():
    tree_raw = ['Prod', '-1/2', 'i', ['Pow', 'e', '2'], ['Pow', ['Sum', ['Pow', 'm_e', '2'], ['Prod', '-1', 's_13'], ['Prod', '1/2', 'reg_prop']], '-1'], 'gamma_{+%\\sigma_126,%eps_36,%del_171}', 'gamma_{%\\sigma_126,%eta_132,%del_172}', 'e_{i_3,%del_171}(p_1)_u', 'e_{k_3,%del_172}(p_2)_u', 'e_{l_3,%eps_36}(p_3)_u^(*)', 'e_{i_5,%eta_132}(p_4)_u^(*)']
    tree = ampl_raw_tree_to_nltk(tree_raw)
    ic(tree)
    tree.pretty_print(abbreviate=True, unicodelines=True)

def test_indices():
    tree_raw = ['Prod', '-1/2', 'i', ['Pow', 'e', '2'], ['Pow', ['Sum', ['Pow', 'm_e', '2'], ['Prod', '-1', 's_13'], ['Prod', '1/2', 'reg_prop']], '-1'], 'gamma_{+%\\sigma_126,%eps_36,%del_171}', 'gamma_{%\\sigma_126,%eta_132,%del_172}', 'e_{i_3,%del_171}(p_1)_u', 'e_{k_3,%del_172}(p_2)_u', 'e_{l_3,%eps_36}(p_3)_u^(*)', 'e_{i_5,%eta_132}(p_4)_u^(*)']
    tree = ampl_raw_tree_to_nltk(tree_raw)
    # tree.pretty_print(abbreviate=True, unicodelines=True)
    assert has_subscript("asdf") == False
    assert has_subscript("asdf_{a, b, c}") == True
    assert has_subscript("p_mu") == True
    assert has_subscript("e_{i_3,%del_171}(p_1)_u") == True


def test_subscripts_to_subtree():
    expr_1 = "gamma_{a, b, c}"
    expr_2 = "gamma_{%\\sigma_126,%eta_132,%del_172}"
    expr_3 = "e_{i_3,%del_171}(p_1)_u"
    ret_1 = subscripts_to_subtree(expr_1)
    ret_2 = subscripts_to_subtree(expr_2)
    ret_3 = subscripts_to_subtree(expr_3)
    ic(ret_1)
    ret_1.pretty_print(unicodelines=True, abbreviate=True)
    ret_2.pretty_print(unicodelines=True, abbreviate=True)
    ic(ret_2)
    ic(ret_3)


def test_is_basis_func():
    expr_1 = "gamma_{a, b, c}"
    expr_2 = "gamma_{%\\sigma_126,%eta_132,%del_172}"
    expr_3 = "e_{i_3,%del_171}(p_1)_u"
    expr_4 = 'e_{i_5,%eta_132}(p_4)_u^(*)'
    ret_1 = is_basis_func(expr_1)
    assert ret_1 == False
    ret_2 = is_basis_func(expr_2)
    assert ret_2 == False
    ret_3 = is_basis_func(expr_3)
    assert ret_3 == True
    ret_4 = is_basis_func(expr_4)
    assert ret_4 == True

def test_basis_func_to_subtree():
    print("-------")
    print("basis_func_to_subtree")
    expr_1 = "gamma_{a, b, c}"
    expr_2 = "gamma_{%\\sigma_126,%eta_132,%del_172}"
    expr_3 = "e_{i_3,%del_171}(p_1)_u"
    expr_4 = 'e_{i_5,%eta_132}(p_4)_u^(*)'
    # ret_1 = is_basis_func(expr_1)
    # ret_2 = is_basis_func(expr_2)
    ic(expr_3)
    ic(expr_4)
    ret_3 = basis_function_to_subtree(expr_3)
    ret_4 = basis_function_to_subtree(expr_4)
    ic(ret_3)
    ic(ret_4)
    ret_3.pretty_print(unicodelines=True)
    ret_4.pretty_print(unicodelines=True)


def test_nltk_tree_expand_subscripts():
    tree_raw = ['Prod', '-1/2', 'i', ['Pow', 'e', '2'], ['Pow', ['Sum', ['Pow', 'm_e', '2'], ['Prod', '-1', 's_13'], ['Prod', '1/2', 'reg_prop']], '-1'], 'gamma_{+%\\sigma_126,%eps_36,%del_171}', 'gamma_{%\\sigma_126,%eta_132,%del_172}', 'e_{i_3,%del_171}(p_1)_u', 'e_{k_3,%del_172}(p_2)_u', 'e_{l_3,%eps_36}(p_3)_u^(*)', 'e_{i_5,%eta_132}(p_4)_u^(*)']
    tree = ampl_raw_tree_to_nltk(tree_raw)
    ic(tree_raw)
    ic(tree)
    tree.pretty_print(unicodelines=True, abbreviate=True)
    tree_expanded = nltk_tree_expand_subscripts(tree)
    tree_expanded.pretty_print(unicodelines=True) #, abbreviate=True)
    

def test_p_sub_to_tree():
    p_expr = 'p_4_+%\\sigma_241'
    tmp = subscripts_to_subtree(p_expr)
    ic(tmp)
    ic(p_sub_to_tree(p_expr))

    expr_raw = "Prod;(;1/9;i;Pow;(;e;3;);Pow;(;Sum;(;Pow;(;m_e;2;);Prod;(;-2;s_13;);s_33;reg_prop;);-1;);Pow;(;Sum;(;Pow;(;m_e;2;);Prod;(;-2;s_13;);Prod;(;-2;s_14;);s_33;Prod;(;2;s_34;);reg_prop;);-1;);Sum;(;Prod;(;p_1_%\\sigma_244;gamma_{%\\sigma_241,%eps_157,%del_386};gamma_{+%\\sigma_241,%eta_297,%eta_330};gamma_{+%\\sigma_244,%eta_330,%eta_331};gamma_{%\\lambda_255,%eta_331,%del_387};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_386}(p_1)_u;e_{i_5,%eps_157}(p_3)_u^(*);s_{k_3,%del_387}(p_2)_u;s_{j_5,%eta_297}(p_4)_u^(*););Prod;(;-1;p_3_%\\sigma_244;gamma_{%\\sigma_241,%eps_158,%del_388};gamma_{+%\\sigma_241,%eta_300,%eta_332};gamma_{+%\\sigma_244,%eta_332,%eta_333};gamma_{%\\lambda_255,%eta_333,%del_389};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_388}(p_1)_u;e_{i_5,%eps_158}(p_3)_u^(*);s_{k_3,%del_389}(p_2)_u;s_{j_5,%eta_300}(p_4)_u^(*););Prod;(;-2;p_4_+%\\sigma_241;gamma_{%\\sigma_241,%eps_161,%del_394};gamma_{%\\lambda_255,%eta_306,%del_395};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_394}(p_1)_u;e_{i_5,%eps_161}(p_3)_u^(*);s_{k_3,%del_395}(p_2)_u;s_{j_5,%eta_306}(p_4)_u^(*);););)"
    expr_raw = expr_raw.split(";")
    ic(np.array(expr_raw))
    tree_raw = get_tree(expr_raw)
    tree = ampl_raw_tree_to_nltk(tree_raw)
    tree = nltk_tree_expand_subscripts(tree)
    tree.pretty_print(unicodelines=True)


def test_get_tree():
    expr_raw = "Prod;(;1/9;i;Pow;(;e;3;);Pow;(;Sum;(;Pow;(;m_e;2;);Prod;(;-2;s_13;);s_33;reg_prop;);-1;);Pow;(;Sum;(;Pow;(;m_e;2;);Prod;(;-2;s_13;);Prod;(;-2;s_14;);s_33;Prod;(;2;s_34;);reg_prop;);-1;);Sum;(;Prod;(;p_1_%\\sigma_244;gamma_{%\\sigma_241,%eps_157,%del_386};gamma_{+%\\sigma_241,%eta_297,%eta_330};gamma_{+%\\sigma_244,%eta_330,%eta_331};gamma_{%\\lambda_255,%eta_331,%del_387};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_386}(p_1)_u;e_{i_5,%eps_157}(p_3)_u^(*);s_{k_3,%del_387}(p_2)_u;s_{j_5,%eta_297}(p_4)_u^(*););Prod;(;-1;p_3_%\\sigma_244;gamma_{%\\sigma_241,%eps_158,%del_388};gamma_{+%\\sigma_241,%eta_300,%eta_332};gamma_{+%\\sigma_244,%eta_332,%eta_333};gamma_{%\\lambda_255,%eta_333,%del_389};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_388}(p_1)_u;e_{i_5,%eps_158}(p_3)_u^(*);s_{k_3,%del_389}(p_2)_u;s_{j_5,%eta_300}(p_4)_u^(*););Prod;(;-2;p_4_+%\\sigma_241;gamma_{%\\sigma_241,%eps_161,%del_394};gamma_{%\\lambda_255,%eta_306,%del_395};A_{k_5,+%\\lambda_255}(p_5)^(*);e_{i_3,%del_394}(p_1)_u;e_{i_5,%eps_161}(p_3)_u^(*);s_{k_3,%del_395}(p_2)_u;s_{j_5,%eta_306}(p_4)_u^(*);););)"
    expr_raw = expr_raw.split(";")
    ic(np.array(expr_raw))
    tree_raw = get_tree(expr_raw)


def test_trees():
    ampls_raw_file = "../../data.nosync/QED_amplitudes_TreeLevel_2to3_raw.txt"
    with open(ampls_raw_file) as f:
        ampls_raw = f.readlines(1000000)
        ampls_raw = [a[:-1] for a in ampls_raw]
        
    for i in [0, 1, 100, -1, -10, -100]:
        exp = ampls_raw[i]
        exp = exp.split(";")

        tree_raw = get_tree(exp)
        tree = ampl_raw_tree_to_nltk(tree_raw)
        tree = nltk_tree_expand_subscripts(tree)
        tree.pretty_print(unicodelines=True)
        # tree.pretty_print(abbreviate=True, unicodelines=True)

    for i in np.random.choice(range(len(ampls_raw)), 100):
        exp = ampls_raw[i]
        exp = exp.split(";")

        ic(i)
        tree_raw = get_tree(exp)
        tree = ampl_raw_tree_to_nltk(tree_raw)
        tree = nltk_tree_expand_subscripts(tree)
        ic(ampls_raw[i])
        tree.pretty_print(unicodelines=True)

    # ic(ampls_raw[398])
    # exp = ampls_raw[398]
    # exp = exp.split(";")
    # ic(np.array(exp))
    # 
    # tree_raw = get_tree(exp)
    # print(tree_raw)
    # tree = ampl_raw_tree_to_nltk(tree_raw)
    # tree = nltk_tree_expand_subscripts(tree)
    # tree.pretty_print(unicodelines=True)
