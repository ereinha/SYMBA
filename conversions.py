# collection of functions to convert data from `raw_data.nosync`.
from icecream import ic
import sympy as sp
from itertools import (takewhile,repeat)
from tqdm import tqdm
import numpy as np
# from source.SympyPrefix import prefix_to_sympy, sympy_to_prefix, sympy_to_hybrid_prefix, simplify_and_prefix, simplify_sqampl
# probably worst way of doing this, but I wanted to import the package SympyPrefix that is a few folders up.
# documentation: https://docs.python.org/3/library/importlib.html#importing-a-source-file-directly
import sys
import importlib.util
spec = importlib.util.spec_from_file_location("SympyPrefix", "sympy-prefix/source/SympyPrefix.py")
SympyPrefix = importlib.util.module_from_spec(spec)
sys.modules["module.name"] = SympyPrefix
spec.loader.exec_module(SympyPrefix)
prefix_to_sympy = SympyPrefix.prefix_to_sympy
sympy_to_prefix = SympyPrefix.sympy_to_prefix
sympy_to_hybrid_prefix = SympyPrefix.sympy_to_hybrid_prefix
hybrid_prefix_to_sympy = SympyPrefix.hybrid_prefix_to_sympy

spec = importlib.util.spec_from_file_location("sp2tree", "data-preprocessing/tree/sympy_to_tree.py")
sp2tree = importlib.util.module_from_spec(spec)
sys.modules["module.name"] = sp2tree
spec.loader.exec_module(sp2tree)

def rawincount(filename):
    """count numer of lines in a file. 
    From https://stackoverflow.com/questions/845058/how-to-get-line-count-of-a-large-file-cheaply-in-python
    """
    f = open(filename, 'rb')
    bufgen = takewhile(lambda x: x, (f.raw.read(1024*1024) for _ in repeat(None)))
    return sum( buf.count(b'\n') for buf in bufgen )

def load_raw_amplitudes(filename, max_lines=-1):
    """
    Loading raw amplitudes from filename.
    
    Options:
        - `max_lines`: maximum number of lines to read
    """
    print("Loading amplitudes from "+ filename)
    if max_lines > 0:
        number_of_lines = max_lines
    else:
        number_of_lines = rawincount(filename)
    data = [0 for i in range(number_of_lines-1)]
    pbar = tqdm(total=number_of_lines)
    with open(filename) as f:
        line = f.readline()
        data.append(line)
        ctr = 0
        while line:
            line = f.readline()
            data[ctr] = line 
            pbar.update(1)
            ctr = ctr + 1
            if ctr >= number_of_lines:
                break
    pbar.close()
    return data


def load_squared_amplitudes(filename, max_lines=-1):
    """
    Loading squared amplitudes from filename and parsing into sympy.
    All squared amplitudes should be exportet from sympy and thus be readable
    without any preprocessing.

    Options:
        - `max_lines`: maximum number of lines to read

    Returns:
        list of squared amplitudes, each as a sympy expression
    """
    print("Loading squared amplitudes from "+ filename)
    if max_lines > 0:
        number_of_lines = max_lines
    else:
        number_of_lines = rawincount(filename)
    data = [0 for i in range(number_of_lines-1)]
    pbar = tqdm(total=number_of_lines)
    with open(filename) as f:
       line = f.readline()
       data.append(line)
       ctr = 0
       while line:
            line = f.readline()
            if line != "":
               line_sp = sp.sympify(line)
               data[ctr] = line_sp
            pbar.update(1)
            ctr = ctr + 1
            if ctr >= number_of_lines:
                break
    pbar.close()
    return data


def conv_sqampl_prefix(sqampl):
    """
    Convert squared amplitude (sympy expression) to prefix notation
    
    Input: sympy expression
    
    Output: [string], where each string is a "token"

    Example: a+b --> ['add', 'a', 'b']
    """
    sqampl_prefix = sympy_to_prefix(sqampl)
    return sqampl_prefix


def backconv_sqampl_prefix(sqampl_prefix_list):
    sqampl_sp = prefix_to_sympy(sqampl_prefix_list)
    return sqampl_sp


def conv_sqampl_hybrid_prefix(sqampl):
    """
    Convert squared amplitude (sympy expression) to prefix notation
    
    Input: sympy expression
    
    Output: [string], where each string is a "token"

    Example: a+b+c --> ['add(', 'a', 'b', 'c', ')']
    """
    sqampl_prefix = sympy_to_hybrid_prefix(sqampl)
    return sqampl_prefix


def backconv_sqampl_hybrid_prefix(sqampl_prefix_list):
    sqampl_sp = hybrid_prefix_to_sympy(sqampl_prefix_list)
    return sqampl_sp


def conv_sqampl_tree(sqampl):
    """
    TODO: Implement version working with NLTK
    https://www.nltk.org/index.html

    Then: Can use it for tree2tree transformer:
    https://github.com/yaushian/Tree-Transformer/blob/master/parse.py
    """
    return 0

if __name__ == "__main__":
    print("This script is to show how the 'raw' data can be preprocessed.")

    amplitudes_filename = "raw_data.nosync/QED_amplitudes_TreeLevel_2to2.txt"
    sqamplitudes_filename = "raw_data.nosync/QED_sqamplitudes_TreeLevel_2to2.txt"
    max_lines = 20
    amplitudes = load_raw_amplitudes(amplitudes_filename, max_lines=max_lines)
    sqamplitudes = load_squared_amplitudes(sqamplitudes_filename, max_lines=max_lines)
    ic(len(amplitudes))
    ic(len(sqamplitudes))

    print("----------------------------\n\n")
    print("Prefix notation: 'conv_sqampl_prefix' and 'backconv_sqampl_prefix':")
    sqamplitudes_prefix = [conv_sqampl_prefix(a) for a in sqamplitudes]
    sqamplitudes_retrieved = [backconv_sqampl_prefix(a) for a in sqamplitudes_prefix]
    print("example:")
    ic(sqamplitudes[0])
    ic(np.array(sqamplitudes_prefix[0]))
    print("Backconvertion of", max_lines, "amplitdudes working?", sqamplitudes == sqamplitudes_retrieved)
    assert sqamplitudes == sqamplitudes_retrieved

    print("----------------------------\n\n")
    print("Hybrid prefix notation: 'conv_sqampl_hybrid_prefix' and 'backconv_sqampl_hybrid_prefix':")
    sqamplitudes_prefix = [conv_sqampl_hybrid_prefix(a) for a in sqamplitudes]
    sqamplitudes_retrieved = [backconv_sqampl_hybrid_prefix(a) for a in sqamplitudes_prefix]
    print("example:")
    ic(sqamplitudes[0])
    ic(np.array(sqamplitudes_prefix[0]))
    print("Backconvertion of", max_lines, "amplitdudes working?", sqamplitudes == sqamplitudes_retrieved)
    assert sqamplitudes == sqamplitudes_retrieved
    sp2tree.sympy_to_tree(sqamplitudes[0]).pretty_print()
