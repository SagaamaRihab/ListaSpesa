#include <iostream>
#include "item.h"
#include "shopping_list.h"

int main() {
    Item pane("Pane", "Panetteria", 2);
    Item latte("Latte", "Latticini", 1);
    Item uova("Uova", "Freschi", 6);

    ShoppingList lista("Spesa del Sabato");
    lista.addItem(pane);
    lista.addItem(latte);
    lista.addItem(uova);

    uova.markAsPurchased();  // attenzione: modifica solo la copia locale (esempio)

    lista.printList();

    std::cout << "Oggetti da acquistare: " << lista.countUnpurchasedItems() << std::endl;

    lista.removeItem("Latte");
    lista.printList();

    return 0;
}
