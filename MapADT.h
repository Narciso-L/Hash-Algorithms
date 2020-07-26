/*Copyright (C) <2016>  <Narciso López-López>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HASH_MAPADT_H
#define HASH_MAPADT_H

#include <string>


using namespace std;

class MapADT {
public:
    virtual bool empty() = 0;
    virtual int size() = 0;

    virtual void insertar(string k, int v) = 0;
    virtual int atEncontrar(string k) = 0;
    virtual void eraseBorrar(string k) = 0;
    virtual void showMap1() = 0;
    virtual void showMap2() = 0;
    virtual void rehashing(string k, int v) = 0;

};

#endif //HASH_MAPADT_H
