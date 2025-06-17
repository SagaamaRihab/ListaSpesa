#include "ShoppingList.h"
#include <algorithm>

ShoppingList::ShoppingList(const std::string& nome) : nome(nome) {}

std::string ShoppingList::getNome() const {
    return nome;
}

void ShoppingList::aggiungiOggetto(const Item& item) {
    oggetti.push_back(item);
    notificaObservers();
}

void ShoppingList::rimuoviOggetto(const std::string& nomeOggetto) {
    oggetti.erase(
        std::remove_if(oggetti.begin(), oggetti.end(),
                       [&](const Item& i) { return i.getNome() == nomeOggetto; }),
        oggetti.end()
    );
    notificaObservers();
}

void ShoppingList::segnaOggettoComeAcquistato(const std::string& nomeOggetto) {
    for (auto& item : oggetti) {
        if (item.getNome() == nomeOggetto) {
            item.segnaComeAcquistato();
            break;
        }
    }
    notificaObservers();
}

int ShoppingList::contaOggettiDaAcquistare() const {
    int count = 0;
    for (const auto& item : oggetti) {
        if (!item.isAcquistato()) count++;
    }
    return count;
}

std::vector<Item> ShoppingList::getOggettiDaAcquistare() const {
    std::vector<Item> daAcquistare;
    for (const auto& item : oggetti) {
        if (!item.isAcquistato()) daAcquistare.push_back(item);
    }
    return daAcquistare;
}

std::vector<Item> ShoppingList::getTuttiGliOggetti() const {
    return oggetti;
}

void ShoppingList::aggiungiObserver(Observer* obs) {
    observers.push_back(obs);
}

void ShoppingList::rimuoviObserver(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ShoppingList::notificaObservers() const {
    for (auto* obs : observers) {
        obs->aggiorna(*this);
    }
}
