#ifndef MENU_H
#define MENU_H

#include <functional>
#include <string>
#include <vector>
#include <iostream>

class Menu
{
public:
    /**
     * @brief Construct a new Menu object
     * @param options
     */
    Menu(const std::vector<std::pair<std::string, std::function<void()>>> &options);

    void display() const;
    void navigate();
    void exitOption();

private:
    std::vector<std::pair<std::string, std::function<void()>>> options;
    int option = 0;
    bool exitSelected = false;
};

#endif // MENU_H