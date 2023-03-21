# ft_printf

L'obiettivo di questo progetto è piuttosto chiaro. Ricodificheremo printf().

#### Perché ft_putnb()r e ft_putstr() non sono mai abbastanza

## 💡 Introduzione

**ft_printf** impareremo ad utilizzare le **variabili dinamiche** in C.
La chiave per un ft_printf di successo è un codice strutturato ed estensibile.

>   Una volta completato questo progetto, potremo aggiungere il nostro
    ft_printf() a libft così da poterlo utilizzare in tutti i nostri progetti futuri.

## 🔍 Variabili dinamiche

Le **[variabili dinamiche](https://it.wikipedia.org/wiki/Gestione_della_memoria)** 
sono utili quando si desidera allocare una quantità di memoria che non è nota a tempo di compilazione.

>   Una variabile dinamica è una variabile che viene allocata durante tutta l'esecuzione del programma.
    Una variabile dinamica viene allocata sull'heap e non viene distrutta quando la funzione termina.

## 📝 Esecuzione

Andremo a implementare le seguenti conversioni:

The prototype of ft_printf() is:

    int    ft_printf(const char *, ...);

| Comando   | Conversione                                                               |
|-----------|---------------------------------------------------------------------------|
| **%c**    | Stampa un singolo carattere.                                              |
| **%s**    | Stampa un singolo carattere.                                              |
| **%p**    | L'argomento puntatore void * deve essere stampato in formato esadecimale. |
| **%i**    | Stampa un numero intero in base 10.                                       |
| **%u**    | Stampa un numero decimale senza segno (base 10).                          |
| **%x**    | Stampa un numero in formato minuscolo esadecimale (base 16).              |
| **%X**    | Stampa un numero in formato maiuscolo esadecimale (base 16).              |
| **%%**    | Stampa un simbolo di percentuale.                                         |








