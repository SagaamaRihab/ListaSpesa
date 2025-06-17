#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "ShoppingList.h"

class User {
private:
    std::string nome;
    std::vector<std::shared_ptr<ShoppingList>> liste;

public:
    explicit User(const std::string& nome);

    std::string getNome() const;
    void creaLista(const std::string& nomeLista);
    std::vector<std::shared_ptr<ShoppingList>> getListe() const;
    std::shared_ptr<ShoppingList> getListaByNome(const std::string& nomeLista);
};

#endif
