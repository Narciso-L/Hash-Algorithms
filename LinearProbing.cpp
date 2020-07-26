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
#include "LinearProbing.h"


// returns whether the map container is empty
bool LinearProbing::empty(){
    return my_map.empty();
}


// returns the number of elements in the map container
int LinearProbing::size(){
    return my_map.size();
}


int LinearProbing::hashFunction1( string key,int n) {
    int value = 0;
    for ( int i = 0; i < key.length(); i++ )
        value += key[i];
    return value % n;
}


// inserts an element into a map
void LinearProbing::insertar(string k, int v){

    int size = my_map.size();
    v = hashFunction1(k, size);

    if (my_map[v] == "" || my_map[v] == "AVAILABLE") {
      /*  cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;
        cout << "position " << my_map[v] << endl;*/
        my_map[v] = k;
    } else {
       /* cout << "COLISION" << endl;
        cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;*/

        while (my_map[v] != "" || my_map[v] == "AVAILABLE")
            v = (v+1) % size;
   //     cout << "la colision pasa a: " << v << endl;
        my_map[v] = k;
        collisions++;

    }

   // cout << "Number of collisions: " << collisions << endl;
    cout << endl;
}


// inserts an element into a map
void LinearProbing::rehashing(string k, int v){

    int size = my_map2.size();
 // cout << "size es " << size << endl;
    v = hashFunction1(k, size);


    if (my_map2[v] == "" || my_map2[v] == "AVAILABLE") {
       /* cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;
        cout << "position " << my_map2[v] << endl;*/
        my_map2[v] = k;
    } else {
        /*cout << "COLISION" << endl;
        cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;*/


        while (my_map2[v] != "" || my_map2[v] == "AVAILABLE")
            v = (v + 1) % size;
       // cout << "la colision pasa a: " << v << endl;
        my_map2[v] = k;
        collisions2++;
    }
}

// searches the container for an element with a key equivalent to k and returns it if found
int LinearProbing::atEncontrar(string k) {

    int size = my_map.size();
    int hash1 = hashFunction1(k, size);

    int count = 0;

    if (my_map[hash1] == k){
        cout << "Encontrado LP: " << my_map[hash1] << endl;
        return hash1;
    }

    else {
        while (my_map[hash1] != "" || my_map[hash1] != "AVAILABLE") {
            hash1 = (hash1 + 1) % size;
        //    cout << "hash1 es dentro: " << hash1 << endl;
            if (my_map[hash1] == k) {
                cout << "Encontrado LP: " << my_map[hash1] << endl;
                return hash1;
            }
            else count++;
            if(count == my_map.size()){
                cout << "Value NOT FOUND" << endl;
                return 0;
            }
        }
    }
}


// removes from the map container a single element
void LinearProbing::eraseBorrar(string k) {
    int size = my_map.size();
    int hash1 = hashFunction1(k, size);
    cout << "BORRAR" << endl;

    int count = 0;

    if(my_map[hash1] == k){
        my_map[hash1] = "AVAILABLE";
        cout << "Borrado 1: " << my_map[hash1] << endl;}

    else {
        while (my_map[hash1] != "" || my_map[hash1] != "AVAILABLE") {
            hash1 = (hash1 + 1) % size;
            cout << "hash1 es dentro: " << hash1 << endl;
            if (my_map[hash1] == k) {
                cout << "Econtrado: " << my_map[hash1] << endl;
                my_map[hash1] = "AVAILABLE";
                cout << "Econtrado: " << my_map[hash1] << endl;
                break;
            }
            else count++;
            if(count == my_map.size()){
                cout << "Value NOT DELETED" << endl;
                break;
            }
        }
    }
}


void LinearProbing::showMap1(){
    for(int i = 0; i< my_map.size();i++){
        if(my_map[i] == "") cout << "posicion vacia" << " posicion " << i << endl;
        else cout << "String: " << my_map[i] << " posicion " << i << endl;
    }
    cout << "Nº de colisiones: " << collisions<< endl;
}


void LinearProbing::showMap2(){
  //  for(int i = 0; i< my_map2.size();i++){
    //    if(my_map2[i] == "") cout << "posicion vacia" << " posicion " << i << endl;
     //   else cout << "String: " << my_map2[i] << " posicion " << i << endl;
  //  }
   cout << "Nº de colisiones: " << collisions2<< endl;
}


