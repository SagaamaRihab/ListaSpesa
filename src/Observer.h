#ifndef OBSERVER_H
#define OBSERVER_H

class ShoppingList;  // Forward declaration

class Observer {
public:
    virtual void aggiorna(const ShoppingList& lista) = 0;
    virtual ~Observer() = default;
};

#endif
