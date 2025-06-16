#include "Item.h"

Item::Item(const std::string& nome, const std::string& categoria, int quantita)
    : nome(nome), categoria(categoria), quantita(quantita), acquistato(false) {}

std::string Item::getNome() const {
    return nome;
}

std::string Item::getCategoria() const {
    return categoria;
}

int Item::getQuantita() const {
    return quantita;
}

bool Item::isAcquistato() const {
    return acquistato;
}

void Item::setQuantita(int nuovaQuantita) {
    quantita = nuovaQuantita;
}

void Item::segnaComeAcquistato() {
    acquistato = true;
}

void Item::segnaComeNonAcquistato() {
    acquistato = false;
}
