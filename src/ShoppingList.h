#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Item.h"
#include "Observer.h"

class ShoppingList {
private:
    std::string nome;
    std::vector<Item> oggetti;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    ShoppingList(const std::string& nome);

    std::string getNome() const;
    void aggiungiOggetto(const Item& item);
   bool rimuoviOggetto(const std::string& nomeOggetto);
    bool segnaOggettoComeAcquistato(const std::string& nomeOggetto);

    int contaOggettiDaAcquistare() const;
    std::vector<Item> getOggettiDaAcquistare() const;
    std::vector<Item> getTuttiGliOggetti() const;

    // Observer
    void aggiungiObserver(std::shared_ptr<Observer> obs);
    void rimuoviObserver(std::shared_ptr<Observer> obs);
    void notificaObservers() const;
};

#endif
