#include <iostream>
#include <map>
#include <memory>
#include "User.h"
#include "Item.h"
#include "ShoppingList.h"

void mostraMenuPrincipale();
void mostraMenuUtente(std::shared_ptr<User> utente);

int main() {
    std::map<std::string, std::shared_ptr<User>> utenti;
    bool esci = false;

    while (!esci) {
        mostraMenuPrincipale();
        int scelta;
        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                std::string nome;
                std::cout << "Inserisci il tuo nome utente: ";
                std::cin >> nome;
                if (utenti.count(nome)) {
                    std::cout << "⚠️  Utente già esistente.\n";
                } else {
                    utenti[nome] = std::make_shared<User>(nome);
                    std::cout << "✅ Registrazione completata!\n";
                }
                break;
            }

            case 2: {
                std::string nome;
                std::cout << "Nome utente: ";
                std::cin >> nome;
                if (utenti.count(nome)) {
                    mostraMenuUtente(utenti[nome]);
                } else {
                    std::cout << "❌ Utente non trovato.\n";
                }
                break;
            }

            case 0:
                esci = true;
                break;

            default:
                std::cout << "Scelta non valida.\n";
        }
    }

    std::cout << "👋 Uscita dal programma.\n";
    return 0;
}

void mostraMenuPrincipale() {
    std::cout << "\n╔════════════════════════╗\n";
    std::cout << "║   🛒 LISTA DELLA SPESA  ║\n";
    std::cout << "╚════════════════════════╝\n";
    std::cout << "[1] Registrati\n";
    std::cout << "[2] Accedi\n";
    std::cout << "[0] Esci\n";
    std::cout << ">> ";
}

void mostraMenuUtente(std::shared_ptr<User> utente) {
    bool tornaIndietro = false;

    while (!tornaIndietro) {
        std::cout << "\n👤 Utente: " << utente->getNome() << "\n";
        std::cout << "[1] Crea una nuova lista\n";
        std::cout << "[2] Aggiungi oggetto a una lista\n";
        std::cout << "[3] Visualizza oggetti da acquistare\n";
        std::cout << "[0] Logout\n";
        std::cout << ">> ";

        int scelta;
        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                std::string nomeLista;
                std::cout << "Nome della nuova lista: ";
                std::cin >> nomeLista;
                utente->creaLista(nomeLista);
                std::cout << "✅ Lista creata!\n";
                break;
            }

            case 2: {
                std::string nomeLista;
                std::cout << "Nome della lista: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    std::string nome, categoria;
                    int quantita;
                    std::cout << "Nome oggetto: ";
                    std::cin >> nome;
                    std::cout << "Categoria: ";
                    std::cin >> categoria;
                    std::cout << "Quantità: ";
                    std::cin >> quantita;
                    lista->aggiungiOggetto(Item(nome, categoria, quantita));
                    std::cout << "🛒 Oggetto aggiunto!\n";
                } else {
                    std::cout << "❌ Lista non trovata.\n";
                }
                break;
            }

            case 3: {
                std::string nomeLista;
                std::cout << "Nome della lista: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    auto daAcquistare = lista->getOggettiDaAcquistare();
                    std::cout << "📦 Oggetti da acquistare:\n";
                    for (const auto& item : daAcquistare) {
                        std::cout << "- " << item.getNome() << " [" << item.getCategoria() << "] x" << item.getQuantita() << "\n";
                    }
                } else {
                    std::cout << "❌ Lista non trovata.\n";
                }
                break;
            }

            case 0:
                tornaIndietro = true;
                break;

            default:
                std::cout << "Scelta non valida.\n";
        }
    }
}
