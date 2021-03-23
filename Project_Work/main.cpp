#include "Dungeon.hpp"
#include "GameObject.hpp"
int main() {
    Dungeon d;
    //d.printDungeon();
    GameObject b('$');
    d.push(b, 10, 5);
    d.printDungeon();
    return 0;
}
