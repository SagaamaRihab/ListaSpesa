#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string nome;
    std::string categoria;
    int quantita;
    bool acquistato;

public:
    Item(const std::string& nome, const std::string& categoria, int quantita);

    std::string getNome() const;
    std::string getCategoria() const;
    int getQuantita() const;
    bool isAcquistato() const;

    void setQuantita(int nuovaQuantita);
    void segnaComeAcquistato();
    void segnaComeNonAcquistato();
};

#endif
