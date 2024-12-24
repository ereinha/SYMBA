import torch
import torch.nn as nn
import torch.optim as optim
import os
import sys
import math
import numpy as np
import tokenizing 
from sklearn.model_selection import train_test_split
from icecream import ic
import csv

x_tokenizer = tokenizing.Tokenizer()
y_tokenizer = tokenizing.Tokenizer()

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

amplitudes_file = "../../data.nosync/QED_amplitudes_TreeLevel_1to2.txt"
sqamplitudes_file = "../../data.nosync/QED_sqamplitudes_TreeLevel_1to2_simplified_shortened_hybridprefix.txt"

amplitudes = []
with open(amplitudes_file) as f:
    reader = csv.reader(f, delimiter=",")
    for line in reader:
        amplitudes.append(line)

sqamplitudes = []
with open(sqamplitudes_file) as f:
    reader = csv.reader(f, delimiter=",")
    for line in reader:
        sqamplitudes.append(line)

X_train, X_test, y_train, y_test = train_test_split(amplitudes, sqamplitudes, test_size=0.2)
x_tokenizer.adapt(X_train)
y_tokenizer.adapt(y_train)

X_train_toc = [x_tokenizer.encode(x) for x in X_train]
X_test_toc = [x_tokenizer.encode(x) for x in X_test]
y_train_toc = [y_tokenizer.encode(y) for y in y_train]
y_test_toc = [y_tokenizer.encode(y) for y in y_test]


