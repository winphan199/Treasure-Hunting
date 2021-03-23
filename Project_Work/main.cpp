#include "Dungeon.hpp"
#include "GameObject.hpp"
int main() {
    Dungeon d;
   // d.printDungeon();
    GameObject b('$');
    //d.push(b, 10, 5);
    //d.push(b, 10, 5);
    //d.push(b, 10, 5);
    d.setLevel(2);
    d.printDungeon();
    return 0;
}
