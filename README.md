# 🛒 Lista della Spesa - Progetto C++ (Esame Universitario)

Questo progetto è una simulazione di un'applicazione in C++ per la gestione di liste della spesa, simile a Listonic.

## ✅ Funzionalità principali

- Gestione di più utenti
- Ogni utente può avere più liste della spesa
- Aggiunta, rimozione, modifica oggetti (nome, categoria, quantità)
- Lista condivisibile tra utenti
- Implementazione del Design Pattern Observer
- Classi con Unit Test (obbligatorio)
- Controllo di versione con Git

## 📦 Struttura del progetto

- `Item`: rappresenta un oggetto da acquistare
- `ShoppingList`: contiene la lista di oggetti e gestisce gli Observer
- `Observer`: interfaccia per osservatori di lista
- `User`: (in arrivo) rappresenta un utente con le sue liste
- `main.cpp`: interfaccia a linea di comando

## 🔧 Requisiti tecnici

- C++17
- Git (versionamento)
- Unit Testing (es. GoogleTest o Catch2)

## 🎓 Info esame

- Progetto realizzato da **Rihab Sagaama** per l’esame di Programmazione C++
- Università degli Studi di Firenze - Ingegneria Informatica

## ▶️ Come compilare e testare

Assicurati di avere `CMake` installato.

```bash
mkdir build
cd build
cmake ..
make
./UnitTests
