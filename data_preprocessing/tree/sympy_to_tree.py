from nltk.tree import Tree
import sympy as sp
from sympy.core.traversal import walk
from sympy import Min, Max
from sympy.abc import x, y, z
from sympy import srepr, pi, sin
from sympy.abc import a,x,y

operators = {
    # Elementary functions
    sp.Add: 'add',
    sp.Mul: 'mul',
    sp.Pow: 'pow',
    sp.exp: 'exp',
    sp.log: 'ln',
    sp.Abs: 'abs',
    sp.sign: 'sign',
    # Trigonometric Functions
    sp.sin: 'sin',
    sp.cos: 'cos',
    sp.tan: 'tan',
    sp.cot: 'cot',
    sp.sec: 'sec',
    sp.csc: 'csc',
    # Trigonometric Inverses
    sp.asin: 'asin',
    sp.acos: 'acos',
    sp.atan: 'atan',
    sp.acot: 'acot',
    sp.asec: 'asec',
    sp.acsc: 'acsc',
    # Hyperbolic Functions
    sp.sinh: 'sinh',
    sp.cosh: 'cosh',
    sp.tanh: 'tanh',
    sp.coth: 'coth',
    sp.sech: 'sech',
    sp.csch: 'csch',
    # Hyperbolic Inverses
    sp.asinh: 'asinh',
    sp.acosh: 'acosh',
    sp.atanh: 'atanh',
    sp.acoth: 'acoth',
    sp.asech: 'asech',
    sp.acsch: 'acsch',
    # Derivative
    sp.Derivative: 'derivative',
}


def sympy_to_tree(expr):
    if len(expr.args) > 0:
        op = expr.func
        op = operators[op]
        return Tree(op, list(map(sympy_to_tree, expr.args)))
    else: 
        return expr


if __name__ == "__main__":
    sympy_to_tree(sp.sympify("a+b*c")).pretty_print(unicodelines=True)
    sympy_to_tree(sp.sympify("a+b+c*(d + exp(e))")).pretty_print(unicodelines=True)
    sympy_to_tree(sp.sympify("exp(a+b*sin(c))")).pretty_print(unicodelines=True)


