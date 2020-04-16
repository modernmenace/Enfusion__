#ifndef ENFUSION___INVENTORY_H
#define ENFUSION___INVENTORY_H

#include "../Component.h"
#include "../../Misc/Item.h"
#include <map>

#define INVENTORY_SIZE 24
#define INVENTORY_FULL 255

/*
 *  Inventory Component
 *
 *  Core of inventory system
 *
 *
 */

class Inventory : public Component {

private:
    Item*   inv_items  [INVENTORY_SIZE];
    int     inv_amounts[INVENTORY_SIZE];

    int     lastItemActivated;

    int nextEmptySlot();

public:
    Inventory();
    void initialize() override;

    //TODO: Add multiple items
    template<class It>
    bool add(It* item, uint16_t amount = 1)
    {
        if (item == nullptr) return false;

        for(uint16_t i = 0; i < amount; i++) {
            std::vector<int> existingStacks;
            for (uint8_t i = 0; i < INVENTORY_SIZE; i++)
                if (inv_items[i] != nullptr)
                    if (inv_items[i]->id() == item->id())
                        existingStacks.push_back(i);

            if (existingStacks.size() == 0) {
                //item not found
                int slot = nextEmptySlot();
                if (slot == INVENTORY_FULL) return false;
                inv_items[slot] = item;
                inv_amounts[slot] = 1;
            } else {
                int currentStack = 0;
                for (;;) {
                    if (inv_amounts[existingStacks[currentStack]]
                        < inv_items[existingStacks[currentStack]]->stackSize()) {
                        inv_amounts[existingStacks[currentStack]]++;
                        break;
                    } else {
                        if (currentStack == existingStacks.size() - 1) {
                            uint8_t slot = nextEmptySlot();
                            if (slot == INVENTORY_FULL) return false;

                            inv_items[slot] = item;
                            inv_amounts[slot] = 1;
                            break;
                        }
                        currentStack++;
                    }
                }
            }
        }
        return true;
    }

    //returns amount of item in inventory
    template <class It>
    int contains()
    {
        int amt = 0;
        for(int i = 0; i < INVENTORY_SIZE; i++)
        {
            auto ptr2 = inv_items[i];
            if (dynamic_cast<It*>(ptr2)) amt += inv_amounts[i];
        }

        return amt;
    }

    void remove(Item* item, uint16_t amount);

    inline Item* item(uint8_t id) { return inv_items[id];   }
    inline int amount(uint8_t id) { return inv_amounts[id]; }
    inline void activated(int id) { lastItemActivated = id; }
};


#endif //ENFUSION___INVENTORY_H
