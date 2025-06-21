#include <gtest/gtest.h>
#include "Item.h"
#include "User.h"


TEST(ItemTest, CostruttoreEGetter) {
    Item item("Latte", "Bevande", 2);
    EXPECT_EQ(item.getNome(), "Latte");
    EXPECT_EQ(item.getCategoria(), "Bevande");
    EXPECT_EQ(item.getQuantita(), 2);
    EXPECT_FALSE(item.isAcquistato());
}

TEST(ItemTest, ModificaQuantita) {
    Item item("Pasta", "Cibo", 1);
    item.setQuantita(3);
    EXPECT_EQ(item.getQuantita(), 3);
}

TEST(ItemTest, StatoAcquisto) {
    Item item("Zucchero", "Cibo", 1);
    item.segnaComeAcquistato();
    EXPECT_TRUE(item.isAcquistato());
    item.segnaComeNonAcquistato();
    EXPECT_FALSE(item.isAcquistato());
}

TEST(UserTest, CondivisioneLista) {
    auto utente1 = std::make_shared<User>("Ali");
    auto utente2 = std::make_shared<User>("Sara");

    utente1->creaLista("Casa");
    utente1->condividiLista(utente2, "Casa");

    auto listaCondivisa = utente2->getListaByNome("Casa");
    ASSERT_TRUE(listaCondivisa != nullptr);
    EXPECT_EQ(listaCondivisa->getNome(), "Casa");
}

