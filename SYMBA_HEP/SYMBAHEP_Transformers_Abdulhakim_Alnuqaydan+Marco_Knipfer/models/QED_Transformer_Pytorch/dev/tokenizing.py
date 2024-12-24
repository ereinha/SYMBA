import sys
import os
from icecream import ic 
import csv
from icecream import ic
import csv
from tokenizers import Tokenizer
from collections import Counter

class Tokenizer():
    """
    Enumerate the words in order of how often they appear.
    The first n will however be the `special_words`.
    """

    def __init__(self, special_words = ["[START]", "[END]", "[UNK]"]):
        self.start_token = special_words[0]
        self.end_token = special_words[1]
        self.unkn_token = special_words[2]
        self.special_words = special_words
        self.id2word = {}
        self.word2id = {}

    def adapt(self, amplitudes_list):
        counter = Counter(self.flatten(amplitudes_list))
        words = list(counter.keys())
        words = self.special_words + words 
        self.id2word = {i: s for i, s in enumerate(words)}
        self.word2id = {s: i for i, s in enumerate(words)}

    def flatten(self, l):
        return [item for sublist in l for item in sublist]

    def encode(self, arr):
        return [self.word2id.get(word, self.unkn_token) for word in arr]

    def decode(self, arr):
        return [self.id2word.get(id) for id in arr]

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

amplitudes_file = "../../data.nosync/QED_amplitudes_TreeLevel_1to2.txt"
sqamplitudes_file = "../../data.nosync/QED_sqamplitudes_TreeLevel_1to2_simplified_shortened_hybridprefix.txt"

if __name__=="__main__":
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
    # ic(amplitudes[0])
    # ic(sqamplitudes[0])


    tokenizer_x = Tokenizer()
    tokenizer_x.adapt(amplitudes)
    # ic(tokenizer_x.id2word)

    tokenizer_y = Tokenizer()
    tokenizer_y.adapt(sqamplitudes)
    # ic(tokenizer_y.id2word)

    enc0 = tokenizer_x.encode(amplitudes[0])
    ic(enc0)
    dec0 = tokenizer_x.decode(enc0)
    ic(dec0)
    assert amplitudes[0] == dec0
