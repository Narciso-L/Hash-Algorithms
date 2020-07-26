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

#include <iostream>
#include "SeparateChaining.h"


// returns whether the map container is empty
bool SeparateChaining::empty(){
    return my_map.empty();
}


// returns the number of elements in the map container
int SeparateChaining::size(){
    return my_map.size();
}


int SeparateChaining::hashFunction1( string key,int n) {
    int value = 0;
    for ( int i = 0; i < key.length(); i++ )
        value += key[i];
    /*    cout << "VALUE ES: " << value << endl;
    cout << "N ES: " << n << endl;
    cout << "RETURN VALUE ES: " << value %n << endl;*/
    return value % n;
}


// inserts an element into a map
void SeparateChaining::insertar(string k, int v){

    int size = my_map.size();
    v = hashFunction1(k, size);
    int i = 0;

    if(my_map[v][i] == ""){
       /* cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;
        cout << "position " << v << endl;*/
        my_map[v][i] = k;
    }

    else{
        /*cout << "COLISION" << endl;
        cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;*/
      //  collisions++;
        for(int j=1;j<10 ;j++){
            if(my_map[v][j] == "") {
                my_map[v][j] = k;

                /*cout << "hash dentro del for: " << v << endl;
                cout << "la colision pasa a la pos: " << j << endl;*/
                break;
            }
        }
    }



    cout << endl;
}


// inserts an element into a map
void SeparateChaining::rehashing(string k, int v){

    int size = my_map2.size();//SIZE2;//my_map2[v].size();
//    cout << "Size es: " << size << endl;
    v = hashFunction1(k, size);
//    cout << "v es: " << v << endl;
    int i = 0;

    if(my_map2[v][i] == ""){
        /*cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;
        cout << "position " << v << endl;*/
        my_map2[v][i] = k;
    }

    else{
        /*cout << "COLISION" << endl;
        cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;*/
       // collisions++;
        for(int j=1;j<10;j++){
            if(my_map2[v][j] == "") {
                my_map2[v][j] = k;

                /*cout << "hash dentro del for: " << v << endl;
                cout << "la colision pasa a la pos: " << j << endl;*/
                break;
            }
        }
    }



    cout << endl;
}

// searches the container for an element with a key equivalent to k and returns it if found
int SeparateChaining::atEncontrar(string k) {

    int size = my_map.size();
    int v = hashFunction1(k, size);
    int i = 0, j = 0;

  //  cout << "V es buscando: " << v << endl;
    if(my_map[v][j] == k){

    //    cout << "Encontrado SP: " << my_map[v][j] << endl;
        return v;
    }
    else{
       // for(int i = 0;i< 503;i++){
            for (int j = 1; j < 10; j++) {
                if (my_map[v][j] == k) {
                 //   cout << "Encontrado SP: " << my_map[v][j] << endl;
                    return v;
                }
            }
       // }
    }
}


// removes from the map container a single element
void SeparateChaining::eraseBorrar(string k) {
    int size = my_map.size();
    int v = hashFunction1(k, size);
    int i = 0, j = 0;

    if(my_map[v][i] == k){

        my_map[v][i] = "";
    }

    else{
        for(int i = 0;i< 11;i++){
            for (int j = 0; j < 10; j++) {
                if (my_map[i][j] == k) {
                    my_map[i][j] = "";
                }
            }
        }
    }
}


void SeparateChaining::showMap1(){
    int i =0, j=0;
    for(int i = 0; i< 503;i++) {
        if (my_map[i][j] == "") cout << "Posicion " << i << " VACIA";
        for (int j = 0; j < 10; j++) {
            if (my_map[i][j] != "")
                cout << " Posicion " << j << " "
                     << my_map[i][j];//else cout << "String: " << my_map[i].ge << " posicion " << i << endl;
        }

        cout << endl;
    }

    cout << "Nº de colisiones: " << collisions<< endl;
}


void SeparateChaining::showMap2(){
    /*int i =0, j=0;
    for(int i = 0; i< 101;i++){
        if(my_map2[i][j] == "") cout << "Posicion " << i << " VACIA";
        for(int j = 0; j< 10;j++) {
            if(my_map2[i][j] != "")
                cout<<" Posicion " << j << " " << my_map2[i][j];//else cout << "String: " << my_map[i].ge << " posicion " << i << endl;
        }

        cout << endl;
    }*/

    cout << "Nº de colisiones: " << collisions<< endl;
}

void SeparateChaining::countCollisions() {
    int i =0, j=0;
    for(int i = 0; i< 503;i++){

        for(int j = 0; j< 10;j++) {
            if(my_map[i][j] != "" && my_map[i][j+1] != "") {
                collisions++;
                break;
            }

        }

        cout << endl;
    }

    cout << "Nº de colisiones en CONTAR2: " << collisions<< endl;
}

void SeparateChaining::countCollisions2() {
    int i =0, j=0;
    for(int i = 0; i< 1009;i++){

        for(int j = 0; j< 10;j++) {
            if(my_map2[i][j] != "" && my_map2[i][j+1] != "") {
                collisions++;
                break;
            }

        }

        cout << endl;
    }

    cout << "Nº de colisiones en CONTAR2: " << collisions<< endl;
}