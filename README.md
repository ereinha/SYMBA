# SYMBA

This project aims to solve common mathematical problems in physics and other fields using modern machine learning techniques such as transformers, genetic progrmaming, Kolmorogov-Arnold networks, and more.

## Directory Structure

```
|-Projects
|---SYMBA-HEP - Calculating squared amplitudes of feynman diagrams
|---SYMBA-REG - Symbolic regression models for physics and beyond
```

## SYMBA-HEP (Symbolic calculation of squared amplitudes for high-energy physics)

In high energy physics, computing squared amplitudes from amplitudes of Feynman diagrams ia key calculation step required to compare experimental observations to theory. This project aims to accelerate this process using techniques derived from LLM language-translation techniques to do this critical computation step by "translating" the amplitudes to their sqaured amplitudes.

The physics models explored are subdivided into quantum electrodynamics (QED), quantum chromodynamics (QCD), and electroweak (EW).

### Previous contributions are included below:

| Project Title | Author | Year |
| :------------ | ------ | ---: |
| Original Data Gen.+Transformers | Abdulhakim Alnuqaydan | 2022 |
| Engine+Longformer | Neeraj Anand | 2023 |
| Engine/Data Update+SKANFormer | Ritesh Bhalerao | 2024 |
| KANFormer+Tensor Product | Ayush Mishra | 2025 |
| Foundation Model | Miche Maral | 2025 |
| State-Space Models | Karaka Prasanth Naidu | 2025 |

### Related papers:

https://iopscience.iop.org/article/10.1088/2632-2153/acb2b2
https://ml4physicalsciences.github.io/2023/files/NeurIPS_ML4PS_2023_183.pdf
https://ml4physicalsciences.github.io/2024/files/NeurIPS_ML4PS_2024_118.pdf

### Data sources:
https://arxiv.org/pdf/2205.15786

## SYMBA-REG (Symbolic regression of numerical data)

At the intersection of experimental and theoretical physics is the step of taking real world observations and data and constructing useful and simple functions to model the observed data. Symbolic regression involves using LLM-style techniques to predict simple and accurate symbolic mathematical expressions that represent numerical data.

### Previous projects have generally used the AI Feynman dataset.

| Project Title | Author | Year |
| :------------ | ------ | ---: |
| Genetic Programming | Ayramaan Thakur | 2024 |
| DPO + PGIP Reinforcement | Samyak Jha | 2024 |
| Symbolic GPT | Krish Malik | 2025 |

### Related papers:

https://ml4physicalsciences.github.io/2024/files/NeurIPS_ML4PS_2024_115.pdf

### Data sources:

https://www.science.org/doi/10.1126/sciadv.aay2631
https://arxiv.org/pdf/2006.10782