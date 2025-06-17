#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#include "Observer.h"

class ShoppingList {
private:
    std::string nome;
    std::vector<Item> oggetti;
    std::vector<Observer*> observers;

public:
    ShoppingList(const std::string& nome);

    std::string getNome() const;
    void aggiungiOggetto(const Item& item);
    void rimuoviOggetto(const std::string& nomeOggetto);
    void segnaOggettoComeAcquistato(const std::string& nomeOggetto);

    int contaOggettiDaAcquistare() const;
    std::vector<Item> getOggettiDaAcquistare() const;
    std::vector<Item> getTuttiGliOggetti() const;

    // Observer
    void aggiungiObserver(Observer* obs);
    void rimuoviObserver(Observer* obs);
    void notificaObservers() const;
};

#endif
