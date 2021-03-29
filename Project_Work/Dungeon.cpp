#include "Dungeon.hpp"

Dungeon::Dungeon() {
    this->_map = new char [_width * _height]; // create a fixed dungeon
    //create layout for the dungeon
    int count = 0; //To count the number of symbols on 1 line.
    for (int i = 0; i < _width * _height; i++) {
        if (count == _width) { //if the max width reached -> reset count
            count = 0;
        }
        if (i >= _width && i < _width * _height - _width) //print X....X
        {
            if (count == 0 || count == _width - 1)
            {
                _map[i] = CONSTANT::getWall();
            }
            else
            {
                _map[i] = CONSTANT::getSpot();
            }
        }
        else
        {
            _map[i] = CONSTANT::getWall(); //printXXXXX on upper and lower
        }

        count++;
    }
}

void Dungeon::setLevel(int level, vector<Gem>& g_arr, vector<Monster>& m_arr, vector<Apple>& a_arr) {
    int count = 0;
    //first reset the dungeon to its default.
    for (int i = 0; i < _width * _height; i++) {
        if (count == _width) { //if the max width reached -> reset count
            count = 0;
        }
        if (i >= _width && i < _width * _height - _width) //print X....X
        {
            if (count == 0 || count == _width - 1)
            {
                _map[i] = CONSTANT::getWall();
            }
            else
            {
                _map[i] = CONSTANT::getSpot();
            }
        }
        else
        {
            _map[i] = CONSTANT::getWall(); //printXXXXX on upper and lower
        }

        count++;
    }
    //create a map for each level
    switch (level) {
        case 1:
        {
            Wall w(0, 0);
            push(w);
            w.setPosition(1, 0);
            push(w);
            w.setPosition(8, 2);
            push(w);
            w.setPosition(9, 2);
            push(w);
            w.setPosition(10, 2);
            push(w);
            w.setPosition(2, 4);
            push(w);
            w.setPosition(3, 4);
            push(w);
            break;
        }
        case 2:
        {
            Wall w(5, 0);
            push(w);
            w.setPosition(6, 0);
            push(w);
            w.setPosition(8, 1);
            push(w);
            w.setPosition(9, 1);
            push(w);
            w.setPosition(10, 1);
            push(w);
            w.setPosition(2, 2);
            push(w);
            w.setPosition(2, 3);
            push(w);
            w.setPosition(2, 4);
            push(w);
            w.setPosition(3, 4);
            push(w);
            w.setPosition(4, 4);
            push(w);
            w.setPosition(5, 4);
            push(w);
            w.setPosition(6, 4);
            push(w);
            break;
        }
        case 3:
        {
            Wall w(0, 2);
            push(w);
            w.setPosition(1, 2);
            push(w);
            w.setPosition(2, 2);
            push(w);
            w.setPosition(3, 2);
            push(w);
            w.setPosition(5, 0);
            push(w);
            w.setPosition(5, 1);
            push(w);
            w.setPosition(7, 3);
            push(w);
            w.setPosition(8, 3);
            push(w);
            w.setPosition(9, 3);
            push(w);
            w.setPosition(10, 3);
            push(w);
            w.setPosition(5, 4);
            push(w);
            w.setPosition(5, 5);
            push(w);
            break;
        }
        case 4:
        {
            Wall w(0, 1);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(0, 4);
            push(w);
            w.setPosition(1, 4);
            push(w);
            w.setPosition(1, 5);
            push(w);
            w.setPosition(3, 3);
            push(w);
            w.setPosition(4, 3);
            push(w);
            w.setPosition(5, 3);
            push(w);
            w.setPosition(7, 0);
            push(w);
            w.setPosition(7, 3);
            push(w);
            w.setPosition(7, 4);
            push(w);
            w.setPosition(8, 4);
            push(w);
            w.setPosition(9, 4);
            push(w);
            w.setPosition(10, 4);
            push(w);
            break;
        }
        case 5:
        {
            Wall w(0, 0);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(2, 2);
            push(w);
            w.setPosition(3, 3);
            push(w);
            w.setPosition(2, 5);
            push(w);
            w.setPosition(3, 5);
            push(w);
            w.setPosition(5, 4);
            push(w);
            w.setPosition(7, 5);
            push(w);
            w.setPosition(8, 5);
            push(w);
            w.setPosition(7, 3);
            push(w);
            w.setPosition(8, 2);
            push(w);
            w.setPosition(9, 1);
            push(w);
            w.setPosition(10, 0);
            push(w);
            w.setPosition(4, 0);
            push(w);
            w.setPosition(6, 0);
            push(w);
            w.setPosition(4, 1);
            push(w);
            w.setPosition(6, 1);
            push(w);
            break;
        }
        case 6:
        {
            Wall w(0, 1);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(2, 1);
            push(w);
            w.setPosition(3, 1);
            push(w);
            w.setPosition(4, 1);
            push(w);
            w.setPosition(5, 1);
            push(w);
            w.setPosition(6, 1);
            push(w);
            w.setPosition(7, 1);
            push(w);
            w.setPosition(7, 2);
            push(w);
            w.setPosition(0, 3);
            push(w);
            w.setPosition(1, 4);
            push(w);
            w.setPosition(5, 3);
            push(w);
            w.setPosition(5, 4);
            push(w);
            w.setPosition(7, 4);
            push(w);
            w.setPosition(6, 4);
            push(w);
            w.setPosition(8, 4);
            push(w);
            w.setPosition(9, 4);
            push(w);
            w.setPosition(10, 4);
            push(w);
            break;
        }
        case 7:
        {
            Wall w(1, 0);
            push(w);
            w.setPosition(7, 0);
            push(w);
            w.setPosition(8, 0);
            push(w);
            w.setPosition(9, 0);
            push(w);
            w.setPosition(10, 0);
            push(w);
            w.setPosition(0, 1);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(5, 1);
            push(w);
            w.setPosition(10, 1);
            push(w);
            w.setPosition(3, 3);
            push(w);
            w.setPosition(6, 3);
            push(w);
            w.setPosition(10, 3);
            push(w);
            w.setPosition(3, 4);
            push(w);
            w.setPosition(7, 4);
            push(w);
            w.setPosition(10, 4);
            push(w);
            w.setPosition(8, 5);
            push(w);
            w.setPosition(9, 5);
            push(w);
            w.setPosition(10, 5);
            push(w);
            break;
        }
        case 8:
        {
            Wall w(5, 0);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(0, 1);
            push(w);
            w.setPosition(5, 1);
            push(w);
            w.setPosition(9, 1);
            push(w);
            w.setPosition(10, 1);
            push(w);
            w.setPosition(2, 2);
            push(w);
            w.setPosition(8, 2);
            push(w);
            w.setPosition(2, 3);
            push(w);
            w.setPosition(3, 3);
            push(w);
            w.setPosition(4, 3);
            push(w);
            w.setPosition(6, 3);
            push(w);
            w.setPosition(7, 3);
            push(w);
            w.setPosition(8, 3);
            push(w);
            w.setPosition(0, 4);
            push(w);
            w.setPosition(4, 4);
            push(w);
            w.setPosition(6, 4);
            push(w);
            w.setPosition(10, 4);
            push(w);
            w.setPosition(1, 5);
            push(w);
            w.setPosition(9, 5);
            push(w);
            break;
        }
        case 9:
        {
            Wall w(3, 0);
            push(w);
            w.setPosition(7, 0);
            push(w);
            w.setPosition(1, 1);
            push(w);
            w.setPosition(5, 1);
            push(w);
            w.setPosition(9, 1);
            push(w);
            w.setPosition(0, 2);
            push(w);
            w.setPosition(5, 2);
            push(w);
            w.setPosition(10, 2);
            push(w);
            w.setPosition(3, 3);
            push(w);
            w.setPosition(4, 3);
            push(w);
            w.setPosition(5, 3);
            push(w);
            w.setPosition(6, 3);
            push(w);
            w.setPosition(7, 3);
            push(w);
            w.setPosition(1, 4);
            push(w);
            w.setPosition(9, 4);
            push(w);
            w.setPosition(2, 5);
            push(w);
            w.setPosition(8, 5);
            push(w);
            break;
        }
        case 10:
        {
            Wall w(0, 4);
            push(w);
            w.setPosition(1, 4);
            push(w);
            w.setPosition(2, 4);
            push(w);
            w.setPosition(3, 4);
            push(w);
            w.setPosition(4, 4);
            push(w);
            w.setPosition(5, 4);
            push(w);
            w.setPosition(6, 4);
            push(w);
            w.setPosition(7, 4);
            push(w);
            w.setPosition(8, 4);
            push(w);
            w.setPosition(9, 4);
            push(w);
            w.setPosition(10, 4);
            push(w);
            break;
        }
        default:
            break;
    }
    //number of gems, apples, monsters depends on level it is ranged from 1 to level
    //generates Gem
    srand((unsigned int)time(0));
    int gem_num = rand() % level + 1;
    for (int i = 0; i < gem_num; i++) {
        int x = 0;
        int y = 0;
        //loop until find available spot to push object into.
        do {
            x = rand() % 11; //random from 0 to 10
            y = rand() % 6; //random from 0 to 5
        } while (at(x, y) != CONSTANT::getSpot());
        Gem g(x, y);
        g_arr.push_back(g);
        push(g);
    }
    
    //generates Monster
    int mon_num = rand() % level + 1;
    for (int i = 0; i < mon_num; i++) {
        int x = 0;
        int y = 0;
        int strength = 0;
        //random strength
        strength = rand() % 101; //random from 0 to 100;
        //loop until find available spot to push object into.
        do {
            x = rand() % 11; //random from 0 to 10
            y = rand() % 6; //random from 0 to 5
        } while (at(x, y) != CONSTANT::getSpot());
        Monster m(x, y, strength);
        m_arr.push_back(m);
        push(m);
    }
    
    //generates Monster
    int app_num = rand() % level + 1;
    for (int i = 0; i < app_num; i++) {
        int x = 0;
        int y = 0;
        int energy = 0;
        //random strength
        energy = rand() % 101; //random from 0 to 100;
        //loop until find available spot to push object into.
        do {
            x = rand() % 11; //random from 0 to 10
            y = rand() % 6; //random from 0 to 5
        } while (at(x, y) != CONSTANT::getSpot());
        Apple a(x, y, energy);
        a_arr.push_back(a);
        push(a);
    }

}

void Dungeon::printDungeon() {
    int count = 0;

    //print table of . in 2-dimension
    for (size_t i = 0; i < _width * _height; i++)
    {
        if (count == this->_width)
        {
            count = 0;
            cout << endl;
        }

        cout << this->_map[i];
        count++;
    }
    cout << endl;
}

//This function push an object into the dungeon on purpose of creating a dungeon based on level
//or setPosition of player when player is moving.
//The dimension will be from left to right and from upper to lower as x, y increase.
//The position is used inner of the dungeon(inside the X)
void Dungeon::push(GameObject &obj) {
    Position temp_pos = obj.getPosition();
    //The dungeon is the 1-dimension array.
    //The available position will be where the '.' placed in the origin dungeon.
    //pos_x <= 10 && pos_y <= 5
    //->pos >= _width && pos < _width * _height - _width
    //We have to get rid of the X in this field
    //We can use 'count' to know when we are at X place.
    
    //First do some boundchecking
    if (temp_pos.getX() < 0 || temp_pos.getX() > 10 || temp_pos.getY() < 0 || temp_pos.getY() > 5) {
        throw "Error: In push(), Position out of bound.";
    }
    
    //Use count to spot X place
    int count = 0;
    int vir_y = 0; // position y in dungeon
    //now find where to put the obj.
    for (int i = _width; i < _width * _height - _width; i++) {
        if (count == _width) {
            count = 0; //reset count when count == _width;
            vir_y++; //the position y increases after going through 1 line
        }
        //check if position in the dungeon matches the input y_pos
        if (vir_y == temp_pos.getY()) {
            int temp = i + 1;//find x pos from this point
            int vir_x = 0; // this is the position x of dungeon
            while (vir_x != temp_pos.getX()) {
                temp++;
                vir_x++;
            }
            //After finding the exact position we want to place the object. We have to make sure we won't replace some other objects.
            //=> check if the symbol is '.'
            if (this->_map[temp] == CONSTANT::getSpot())
            {
                this->_map[temp] = obj.getSymbol(); //this is the position of the gameobject.
                return;
            }
            else {
                //if we can't push in that position, then find another position
                
                int count_1 = 0;
                for (int j = temp; j < _width * _height - _width; j = (++j) % (_width * _height - _width)) // this will make sure it will always find a place to push.
                {
                    if (count_1 >= _width * _height - _width)
                    {
                        throw "Error: The dungeon is full.";
                    }
                    
                    if (this->_map[j] == CONSTANT::getSpot())
                    {
                        this->_map[j] = obj.getSymbol();
                        return;
                    }
                    count_1++;
                }
            } 
        }
        count++;
    }
}

//get symbol at a specific position
char Dungeon::at(int x, int y) {
    
    //First do some boundchecking
    if (x < 0 || x > 10 || y < 0 || y > 5) {
        throw "Error: Position out of bound";
    }
    
    //Use count to spot X place
    int pos = 0;
    int count = 0;
    int vir_y = 0; // position y in dungeon
    //now find where to put the obj.
    for (int i = _width; i < _width * _height - _width; i++) {
        if (count == _width) {
            count = 0; //reset count when count == _width;
            vir_y++; //the position y increases after going through 1 line
        }
        //check if position in the dungeon matches the input y_pos
        if (vir_y == y) {
            int temp = i + 1;//find x pos from this point
            int vir_x = 0; // this is the position x of dungeon
            while (vir_x != x) {
                temp++;
                vir_x++;
            }
            //this is the pos of what we are looking for
            pos = temp;
            break;
        }
        count++;
    }
    return _map[pos];
}

void Dungeon::remove(int x, int y) {
    //First do some boundchecking
    if (x < 0 || x > 10 || y < 0 || y > 5) {
        throw "Error: Position out of bound.";
    }
    
    //Use count to spot X place
    int pos = 0;
    int count = 0;
    int vir_y = 0; // position y in dungeon
    //now find where to put the obj.
    for (int i = _width; i < _width * _height - _width; i++) {
        if (count == _width) {
            count = 0; //reset count when count == _width;
            vir_y++; //the position y increases after going through 1 line
        }
        //check if position in the dungeon matches the input y_pos
        if (vir_y == y) {
            int temp = i + 1;//find x pos from this point
            int vir_x = 0; // this is the position x of dungeon
            while (vir_x != x) {
                temp++;
                vir_x++;
            }
            //this is the pos of what we are looking for
            pos = temp;
            break;
        }
        count++;
    }
    _map[pos] = CONSTANT::getSpot();
}
Dungeon::~Dungeon() {
    delete []this->_map;
}
