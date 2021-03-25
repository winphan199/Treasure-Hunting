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

void Dungeon::setLevel(int level) {
    
    Wall w;
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
            push(w, 0, 0);
            push(w, 1, 0);
            push(w, 8, 2);
            push(w, 9, 2);
            push(w, 10, 2);
            push(w, 2, 4);
            push(w, 3, 4);
            break;
        }
        case 2:
        {
            push(w, 5, 0);
            push(w, 6, 0);
            push(w, 8, 1);
            push(w, 9, 1);
            push(w, 10, 1);
            push(w, 2, 2);
            push(w, 2, 3);
            push(w, 2, 4);
            push(w, 3, 4);
            push(w, 4, 4);
            push(w, 5, 4);
            push(w, 6, 4);
            break;
        }
        default:
            break;
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
void Dungeon::push(GameObject &obj, int x, int y) {
    //The dungeon is the 1-dimension array.
    //The available position will be where the '.' placed in the origin dungeon.
    //pos_x <= 10 && pos_y <= 6
    //->pos >= _width && pos < _width * _height - _width
    //We have to get rid of the X in this field
    //We can use 'count' to know when we are at X place.
    
    //First do some boundchecking
    if (x < 0 || x > 10 || y < 0 || y > 5) {
        throw "Error: Position out of bound.";
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
        if (vir_y == y) {
            int temp = i + 1;//find x pos from this point
            int vir_x = 0; // this is the position x of dungeon
            while (vir_x != x) {
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

Dungeon::~Dungeon() {
    delete []this->_map;
}


