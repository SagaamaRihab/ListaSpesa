#include "FileObserver.h"
#include "ShoppingList.h"

FileObserver::FileObserver(const std::string& filename) : filename(filename) {}

void FileObserver::aggiorna(const ShoppingList& lista) {
    std::ofstream file(filename, std::ios::app);  // Modalità append
    if (file.is_open()) {
        file << "🔔 Lista \"" << lista.getNome() << "\" aggiornata. Totale oggetti da acquistare: "
             << lista.contaOggettiDaAcquistare() << std::endl;
        file.close();
    }
}
