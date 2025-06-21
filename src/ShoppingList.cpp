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

bool ShoppingList::rimuoviOggetto(const std::string& nomeOggetto) {
    auto it = std::remove_if(oggetti.begin(), oggetti.end(),
                             [&](const Item& i) { return i.getNome() == nomeOggetto; });

    if (it != oggetti.end()) {
        oggetti.erase(it, oggetti.end());
        notificaObservers();
        return true;
    }

    return false;
}



bool ShoppingList::segnaOggettoComeAcquistato(const std::string& nomeOggetto) {
    for (auto& item : oggetti) {
        if (item.getNome() == nomeOggetto && !item.isAcquistato()) {
            item.segnaComeAcquistato();
            notificaObservers();
            return true;
        }
    }
    return false;
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

void ShoppingList::aggiungiObserver(std::shared_ptr<Observer> obs) {
    observers.push_back(obs);
}

void ShoppingList::rimuoviObserver(std::shared_ptr<Observer> obs) {
    observers.erase(
        std::remove_if(observers.begin(), observers.end(),
                       [&](const std::shared_ptr<Observer>& o) { return o == obs; }),
        observers.end()
    );
}

void ShoppingList::notificaObservers() const {
    for (const auto& obs : observers) {
        obs->aggiorna(*this);
    }
}
