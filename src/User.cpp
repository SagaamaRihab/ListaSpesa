#include "User.h"

User::User(const std::string& nome) : nome(nome) {}

std::string User::getNome() const {
    return nome;
}

void User::creaLista(const std::string& nomeLista) {
    liste.push_back(std::make_shared<ShoppingList>(nomeLista));
}

std::vector<std::shared_ptr<ShoppingList>> User::getListe() const {
    return liste;
}

std::shared_ptr<ShoppingList> User::getListaByNome(const std::string& nomeLista) {
    for (auto& lista : liste) {
        if (lista->getNome() == nomeLista) {
            return lista;
        }
    }
    return nullptr;
}

void User::condividiLista(std::shared_ptr<User> altroUtente, const std::string& nomeLista) {
    auto lista = getListaByNome(nomeLista);
    if (lista) {
        altroUtente->aggiungiListaCondivisa(lista);
    }
}

void User::aggiungiListaCondivisa(std::shared_ptr<ShoppingList> lista) {
    liste.push_back(lista);
}

