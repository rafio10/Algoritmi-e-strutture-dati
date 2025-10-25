# 💻 Progetto di Algoritmi e Strutture Dati

Questo repository contiene le soluzioni implementate (principalmente in **C++**) e la documentazione analitica relativa a problemi complessi, compiti settimanali ed esercizi, coprendo argomenti chiave di Algoritmi e Programmazione Dinamica.

---

## 🥇 Problema 1: Divisione del Bottino (Knapsack Minimo)

### 📄 Documentazione e Implementazione
* **Specifiche:** `Problema 1.pdf`
* **Codice:** `main.cpp`

### Descrizione del Problema
Il problema richiede di trovare la **minima differenza positiva** di valore tra i bottini ottenuti da due ladri che si dividono un insieme di monete. Essenzialmente, si tratta di un problema di partizionamento, riconducibile a una variante del problema dello Zaino (Knapsack).

### ⚙️ Metodologia e Algoritmo
La soluzione implementata in `main.cpp` utilizza la **Programmazione Dinamica (DP)** con **Memoization**.
* **Funzione Chiave:** `int MaxValue(int arr[], int sum_1, int sum_2, int i, int nMoney)`
* **Logica:** La funzione esplora ricorsivamente tutte le possibili distribuzioni delle monete nei due gruppi (`sum_1` e `sum_2`), utilizzando un array di memoization (`memo[]`) per salvare i risultati intermedi dei sottoproblemi già risolti e prevenire ricalcoli.

### 📈 Complessità
La complessità è dominata dal numero di sottoproblemi risolti e si attesta a:
* **Singolo Caso di Test:** $O(\text{nMoney})$
* **Casi Multipli:** $O(\text{nTest} \cdot \text{nMoney})$

---

## 📚 Homework Set 2: Algoritmi Classici

Il secondo set di compiti è focalizzato su due problemi algoritmici classici, con documentazione specifica sulle metodologie utilizzate.

### Problema 2.1: Somma Massima di Sottoarray Contiguo
* **Documentazione:** `Problema 2.1.docx`
* **Obiettivo:** Trovare il sottoarray di numeri contigui (positivi/negativi) che ha la somma più grande.
* **Metodologia:** L'approccio si basa sul mantenimento di una somma corrente valida, che viene azzerata se diventa negativa. Questo è un metodo efficiente, riconducibile all'algoritmo di **Kadane**, per trovare la massima somma in tempo lineare.
* **Complessità Dichiarata:** $O(n \log m)$ (dove $n$ è il numero di elementi dell'array e $m$ il numero di test case).

### Problema 2.2: Problema delle N Regine (N-Queens)
* **Documentazione:** `Problema 2.2.docx`, `Homeworks set 2.pdf`
* **Obiettivo:** Calcolare il numero di modi possibili per posizionare $N$ regine su una scacchiera $N \times N$ in modo che nessuna possa attaccare le altre.
* **Metodologia:** Viene utilizzata la tecnica del **Backtracking**. La soluzione procede riga per riga, effettuando controlli per assicurare che la regina da inserire non sia sulla stessa riga, colonna o diagonale delle regine già posizionate.
* **Complessità:** $O(t \cdot N!)$ (dove $t$ è il numero di test case), riflettendo la natura combinatoria e fattoriale delle scelte in gioco.

---

## ✏️ Esercizi: Strutture Dati e Divide et Impera

Questa sezione contiene esercizi specifici basati su tecniche algoritmiche e l'implementazione di strutture dati avanzate.

### Esercizio 1.1: Conteggio delle Inversioni
* **Documentazione:** `1.1.pdf`
* **Obiettivo:** Risolvere un problema utilizzando la logica delle **inversioni** (coppie $(i, j)$ con $i < j$ ma $A_i > A_j$) tramite un approccio **Divide et Impera**.
* **Metodologia:** Viene impiegato l'algoritmo **MergeSort**, modificato per contare le inversioni durante la fase di *merge*.
* **Complessità:** $O(n \log n)$ per caso di test.

### Esercizio 1.2: Longest Common Prefix (LCP)
* **Documentazione:** `1.2.pdf`
* **Obiettivo:** Trovare il prefisso comune più lungo in un insieme di parole.
* **Metodologia:** L'approccio è basato sul **Divide et Impera**. Il vettore di parole viene diviso ricorsivamente fino a confrontare solo coppie, e il LCP viene ricostruito risalendo l'albero di ricorsione.
* **Complessità:** $O(n \log n)$ (dove $n$ è il numero di parole).

### Esercizio 1.3: Implementazione di Treap
* **Codice/Dettagli:** `1.3.txt`
* **Struttura Dati:** Implementazione di un **Treap** (Tree + Heap).
* **Logica:** La struttura combina le proprietà di un **Binary Search Tree (BST)** (le chiavi sono ordinate) e di un **Min-Heap** (le priorità sono ordinate). Le operazioni di `insert` mantengono queste proprietà attraverso l'uso di **rotazioni** (come `leftRotate` e `rightRotate`).

---

## ⚙️ Istruzioni per la Compilazione

Per compilare ed eseguire la soluzione al **Problema 1** (contenuta in `main.cpp`), si utilizza un compilatore C++ standard:

```bash
# Compilazione del file sorgente C++
g++ main.cpp -o problema1

# Esecuzione
./problema1
