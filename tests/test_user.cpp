#include <gtest/gtest.h>
#include "User.h"

TEST(UserTest, CreaListaERecupera) {
    User utente("Rihab");
    utente.creaLista("Casa");

    auto liste = utente.getListe();
    ASSERT_EQ(liste.size(), 1);
    EXPECT_EQ(liste[0]->getNome(), "Casa");

    auto lista = utente.getListaByNome("Casa");
    ASSERT_TRUE(lista != nullptr);
    EXPECT_EQ(lista->getNome(), "Casa");
}

TEST(UserTest, ListaNonTrovata) {
    User utente("Rihab");
    EXPECT_EQ(utente.getListaByNome("NonEsiste"), nullptr);
}
