```text
ai-systems-architect-lab/
│
├── 01_AI_Foundations/
│   ├── Session_01_AI_Basics.ipynb
│   ├── Session_02_Embeddings.ipynb
│   ├── Session_03_Vector_DB.ipynb
│   └── Session_04_RAG.ipynb
│
├── 02_RAG_Projects/
│
├── 03_Agents/
│
├── 04_MCP/
│
├── 05_Edge_AI/
│
├── 06_AI_Platform/
│
├── diagrams/
│
└── README.md
```

---

# Current File

Create:

```text
01_AI_Foundations/
    Session_01_AI_Basics.ipynb
```

---

# Session 01 Notes

Use this as your first markdown section.

## AI Evolution

```text
Artificial Intelligence (AI)
        |
        +---- Machine Learning (ML)
                    |
                    +---- Deep Learning (DL)
                                |
                                +---- Generative AI
                                            |
                                            +---- Large Language Models (LLMs)
```

---

### Artificial Intelligence (AI)

Definition:

Machines performing tasks that normally require human intelligence.

Examples:

* Speech Recognition
* Image Recognition
* Language Understanding
* Recommendation Systems

---

### Machine Learning (ML)

Traditional Programming

```text
Rules + Data
      ↓
   Output
```

Machine Learning

```text
Data + Output
      ↓
 Learn Rules
```

Key Idea:

System learns patterns from data.

---

### Deep Learning

Subset of Machine Learning.

Uses:

```text
Artificial Neural Networks
```

Characteristics:

* Large datasets
* Multiple hidden layers
* High computational requirements

Applications:

* Vision
* Speech
* NLP

---

### Generative AI

Purpose:

Generate new content.

Examples:

```text
Text
Image
Audio
Code
Video
```

---

### Large Language Model (LLM)

Definition:

A Deep Learning model trained to predict the next token.

Examples:

* ChatGPT
* Gemini
* Claude

Important:

```text
LLM ≠ Knowledge Base

LLM = Language Generator
```

---

# LLM Architecture View

```text
User Question
      ↓
Prompt
      ↓
LLM
      ↓
Generated Answer
```

Problem:

LLM may not know company-specific information.

---

# Why RAG Exists

Problem:

```text
LLM
  ↓
Does not know
my latest resume
my company documents
my private data
```

Solution:

```text
Retrieve
     +
Augment
     +
Generate
```

RAG = Retrieval Augmented Generation

---

# RAG High-Level Architecture

```text
Documents
      ↓
Retrieval
      ↓
Relevant Context
      ↓
LLM
      ↓
Answer
```

---

# Embeddings

Definition:

Numerical representation of semantic meaning.

Example:

```text
"Network Management System"

↓

[0.21, -0.54, 0.88, ...]
```

Important:

Embeddings capture meaning, not exact words.

---

### Why Embeddings

Keyword Search

```text
NMS
```

may not match

```text
Network Management Platform
```

---

Embedding Search

```text
Meaning
      ↓
Similarity
      ↓
Match
```

---

# Vector Database

Purpose:

Store embeddings and perform similarity search.

Examples:

* FAISS
* ChromaDB
* Qdrant
* Pinecone

---

# Retriever

Definition:

Component responsible for finding relevant information.

Architecture:

```text
Question
    ↓
Retriever
    ↓
Vector Database
    ↓
Relevant Chunks
```

---

# Complete Enterprise RAG Architecture

This is the most important diagram of Session 1.

```text
User Question
       ↓
Retriever
       ↓
Vector Database
       ↓
Relevant Chunks
       ↓
Prompt Builder
       ↓
LLM
       ↓
Generated Answer
```

---