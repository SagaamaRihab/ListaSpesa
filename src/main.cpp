#include <iostream>
#include <iomanip>
#include <map>
#include <memory>
#include "User.h"
#include "Item.h"
#include "ShoppingList.h"
#include "ConsoleObserver.h"

void mostraMenuPrincipale();
void mostraMenuUtente(std::shared_ptr<User> utente, std::map<std::string, std::shared_ptr<User>>& utenti);


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
                std::cout << "👤 Inserisci il tuo nome utente: ";
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
                std::cout << "🔑 Nome utente: ";
                std::cin >> nome;
                if (utenti.count(nome)) {
                    mostraMenuUtente(utenti[nome], utenti);
                } else {
                    std::cout << "❌ Utente non trovato.\n";
                }
                break;
            }

            case 0:
                esci = true;
                break;

            default:
                std::cout << "❗ Scelta non valida.\n";
        }
    }

    std::cout << "👋 Uscita dal programma.\n";
    return 0;
}

void mostraMenuPrincipale() {
    std::cout << "\n╔════════════════════════════════╗\n";
    std::cout << "║     🛒 LISTA DELLA SPESA CLI    ║\n";
    std::cout << "╚════════════════════════════════╝\n";
    std::cout << "[0] ❌ Esci\n";
    std::cout << "[1] ➕ Registrati\n";
    std::cout << "[2] 🔐 Accedi\n";

    std::cout << ">> ";
}

void mostraMenuUtente(std::shared_ptr<User> utente, std::map<std::string, std::shared_ptr<User>>& utenti)
{
    bool tornaIndietro = false;

    while (!tornaIndietro) {
        std::cout << "\n👤 Utente: " << utente->getNome() << "\n";
        std::cout << "[1] ➕ Crea una nuova lista\n";
        std::cout << "[2] 🛒 Aggiungi oggetto a una lista\n";
        std::cout << "[3] 📋 Visualizza oggetti da acquistare\n";
        std::cout << "[4] ✅ Segna oggetto come acquistato\n";
        std::cout << "[5] 🤝 Condividi una lista con un altro utente\n";
        std::cout << "[6] ❌ Rimuovi un oggetto da una lista\n";
        std::cout << "[0] 🔙 Logout\n";
        std::cout << ">> ";

        int scelta;
        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                std::string nomeLista;
                std::cout << "🆕 Nome della nuova lista: ";
                std::cin >> nomeLista;
                utente->creaLista(nomeLista);
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    auto observer = std::make_shared<ConsoleObserver>();
                    lista->aggiungiObserver(observer);
                }
                std::cout << "✅ Lista creata!\n";
                break;
            }

            case 2: {
                std::string nomeLista;
                std::cout << "📂 Nome della lista: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);

                if (lista) {
                    std::string nome, categoria;
                    int quantita;
                    std::cout << "📦 Nome oggetto: ";
                    std::cin >> nome;
                    std::cout << "📂 Categoria: ";
                    std::cin >> categoria;
                    std::cout << "🔢 Quantità: ";
                    std::cin >> quantita;
                    lista->aggiungiOggetto(Item(nome, categoria, quantita));
                    std::cout << "🛍️ Oggetto aggiunto!\n";
                } else {
                    std::cout << "❌ Lista non trovata.\n";
                }
                break;
            }

            case 3: {
                std::string nomeLista;
                std::cout << "🗂️ Nome della lista da visualizzare: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    auto daAcquistare = lista->getOggettiDaAcquistare();
                    std::cout << "\n🛍️  Oggetti da acquistare nella lista \"" << lista->getNome() << "\":\n";

                    if (daAcquistare.empty()) {
                        std::cout << "✅ Tutti gli oggetti sono stati acquistati!\n";
                    } else {
                        std::cout << "╔════════════════════════════════════════╗\n";
                        std::cout << "║   🧾 Nome        📦 Categoria    🔢 Qtà  ║\n";
                        std::cout << "╠════════════════════════════════════════╣\n";
                        for (const auto& item : daAcquistare) {
                            std::cout << "║ " << std::setw(12) << std::left << item.getNome()
                                      << "  " << std::setw(10) << item.getCategoria()
                                      << "    x" << item.getQuantita() << "      ║\n";
                        }
                        std::cout << "╚════════════════════════════════════════╝\n";
                        std::cout << "🔢 Totale: " << daAcquistare.size() << " oggetti da acquistare\n";
                    }
                } else {
                    std::cout << "❌ Lista non trovata.\n";
                }
                break;
            }

            case 4: {
                std::string nomeLista, nomeOggetto;
                std::cout << "📂 Nome della lista: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    std::cout << "📦 Nome dell'oggetto da segnare come acquistato: ";
                    std::cin >> nomeOggetto;
                    if (lista->segnaOggettoComeAcquistato(nomeOggetto)) {
                        std::cout << "✅ Oggetto segnato come acquistato!\n";
                    } else {
                        std::cout << "❌ Oggetto non trovato nella lista o già acquistato.\n";
                    }

                } else {
                    std::cout << "❌ Lista non trovata.\n";
                }
                break;
            }


            case 5: {
                std::string nomeLista, nomeAltroUtente;
                std::cout << "📂 Nome della lista da condividere: ";
                std::cin >> nomeLista;
                std::cout << "👤 Nome dell’altro utente: ";
                std::cin >> nomeAltroUtente;

                if (utente->getListaByNome(nomeLista) && utenti.count(nomeAltroUtente)) {
                    utente->condividiLista(utenti[nomeAltroUtente], nomeLista);
                    std::cout << "✅ Lista condivisa con " << nomeAltroUtente << "!\n";
                } else {
                    std::cout << "❌ Lista o utente non trovati.\n";
                }
                break;
            }

            case 6: {
                std::string nomeLista, nomeOggetto;
                std::cout << "📂 Nome della lista: ";
                std::cin >> nomeLista;
                auto lista = utente->getListaByNome(nomeLista);
                if (lista) {
                    std::cout << "📦 Nome dell'oggetto da rimuovere: ";
                    std::cin >> nomeOggetto;
                    if (lista->rimuoviOggetto(nomeOggetto)) {
                        std::cout << "❌ Oggetto rimosso!\n";
                    } else {
                        std::cout << "⚠️  Oggetto \"" << nomeOggetto << "\" non trovato nella lista.\n";
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
                std::cout << "❗ Scelta non valida.\n";
        }
    }
}
