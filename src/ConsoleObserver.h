#ifndef CONSOLEOBSERVER_H
#define CONSOLEOBSERVER_H

#include "Observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void aggiorna(const ShoppingList& lista) override;
};

#endif
