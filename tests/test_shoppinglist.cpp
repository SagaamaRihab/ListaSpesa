#include <gtest/gtest.h>
#include "ShoppingList.h"
#include "Item.h"
#include "ConsoleObserver.h"

TEST(ShoppingListTest, AggiungiOggetto) {
    ShoppingList lista("SpesaCasa");
    Item latte("Latte", "Bevande", 2);
    lista.aggiungiOggetto(latte);

    auto tutti = lista.getTuttiGliOggetti();
    ASSERT_EQ(tutti.size(), 1);
    EXPECT_EQ(tutti[0].getNome(), "Latte");
}

TEST(ShoppingListTest, RimuoviOggetto) {
    ShoppingList lista("SpesaCasa");
    lista.aggiungiOggetto(Item("Latte", "Bevande", 2));
    lista.rimuoviOggetto("Latte");

    EXPECT_EQ(lista.getTuttiGliOggetti().size(), 0);
}

TEST(ShoppingListTest, ContaOggettiDaAcquistare) {
    ShoppingList lista("SpesaCasa");
    lista.aggiungiOggetto(Item("Pane", "Cibo", 1));
    lista.aggiungiOggetto(Item("Acqua", "Bevande", 3));
    lista.segnaOggettoComeAcquistato("Pane");

    EXPECT_EQ(lista.contaOggettiDaAcquistare(), 1);
}

TEST(ShoppingListTest, NotificaObserver) {
    ShoppingList lista("SpesaCasa");
    ConsoleObserver obs;
    lista.aggiungiObserver(&obs);

    // Output del test apparirà nella Run se vuoi usare std::cout
    testing::internal::CaptureStdout();
    lista.aggiungiOggetto(Item("Frutta", "Cibo", 1));
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("è stata aggiornata"), std::string::npos);
}
