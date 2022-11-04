import sys
import os
from icecream import ic 
import csv
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from icecream import ic
import pandas as pd
import csv
from tokenizers import Tokenizer
from tokenizers.models import BPE

tokenizer = Tokenizer(BPE())

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

#
ic(len(amplitudes))
ic(len(sqamplitudes))
ic(amplitudes[0])
ic(sqamplitudes[0])

def flatten(l):
    return [item for sublist in l for item in sublist]

special_words = ["[START]", "[END]"]
words = special_words + list(np.unique(flatten(amplitudes)))
id2word = {i: s for i, s in enumerate(words)}
ic(len(words))
