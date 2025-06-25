#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "Observer.h"
#include <fstream>

class FileObserver : public Observer {
private:
    std::string filename;

public:
    explicit FileObserver(const std::string& filename);
    void aggiorna(const ShoppingList& lista) override;
};

#endif
