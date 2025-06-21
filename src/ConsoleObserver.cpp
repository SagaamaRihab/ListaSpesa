#include "ConsoleObserver.h"
#include "ShoppingList.h"

void ConsoleObserver::aggiorna(const ShoppingList& lista) {
    std::cout << "🔔 [Observer] La lista \"" << lista.getNome()
              << "\" è stata aggiornata: "
              << lista.contaOggettiDaAcquistare()
              << " oggetti da acquistare.\n";
}
