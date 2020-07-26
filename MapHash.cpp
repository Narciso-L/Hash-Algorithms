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
#include "MapHash.h"


// returns whether the map container is empty
bool MapHash::empty(){
    return my_map.empty();
}


// returns the number of elements in the map container
int MapHash::size(){
    return my_map.size();
}


int MapHash::hashFunction1( string key,int n) {
    int value = 0;
    for ( int i = 0; i < key.length(); i++ )
        value += key[i];
  //  cout << "Value es " << value << endl;
    return value % n;
}


int MapHash::hashFunction2( string key,int n) {
    // non-zero, less than array size, different from hF1
    // array size must be relatively prime to 5, 4, 3, and 2
    int hash1 = hashFunction1(key,n);
 //   cout << "hash1 es " << hash1 << endl;
  //  int previousPrime = previousPrimeNumber(n);
  //  cout << "hash2 es " << 5-(hash1 % 5) << endl;
    return  5-(hash1 % 5);  //previousPrime-(hash1 % previousPrime);
}


int MapHash::primeNumber(int n) {
    int a = 0;
    for(int i=1;i<=n;i++) {
        if(n%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
            a++;
    }

    if(a==2){//*Si al final del bucle, a vale 2, el número es primo, porque tiene solamente 2 divisores.
        return n;
    }
    else{   //buscar el primo mas proximo
        for(int i = 0;i<primes.size();i++){

            if(n<primes[i]){
                return primes[i];
            }
        }
    }
}


int MapHash::previousPrimeNumber(int n) {
    int a = 0;
    for(int i=1;i<=n;i++) {
        if(n%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
            a++;
    }

    if(a==2){//*Si al final del bucle, a vale 2, el número es primo, porque tiene solamente 2 divisores.
        return n;
    }
    else{   //buscar el primo mas proximo
        for(int i = 0;i<primes.size();i++){

            if(n<primes[i]){
                return primes[i-1];
            }
        }
    }
}

// inserts an element into a map
void MapHash::insertar(string k, int v){

    int size = my_map.size();
    v = hashFunction1(k, size);
    int hash2 = hashFunction2(k, size);

  //  int elements = 0;
  //  int load_factor = 0;
  //  int next_prime = 0;

    /*for(int i =0; i<my_map.size();i++){     //count elements in hash table
        if(my_map[i] != ""){
            elements++;
        }
    }*/

   // load_factor = (elements/my_map.size());    //load factor equals to number of elements in hash table divided with TABLE_SIZE

  //  if(load_factor<1) {
        if (my_map[v] == "") {
            cout << "key es: " << k << endl;
            cout << "Hash es " << v << endl;
            cout << "position " << my_map[v] << endl;
            my_map[v] = k;
        } else {
            cout << "COLISION" << endl;
            cout << "key es: " << k << endl;
            cout << "Hash 2 es " << hash2 << endl;
            //    my_map[hash2] = k;

            while (my_map[v] != "")
                v = (v + hash2) % size;
      //      cout << "la colision pasa a: " << v << endl;
            my_map[v] = k;
            collisions++;
        }

   /* else{      //rehashing
        table_size = table_size*2; //double size of hashtable
        next_prime = primeNumber(table_size);   // look for next prime
        table_size = next_prime;                // assign next prime to table_size

        v = hashFunction1(k);
        int hash2 = hashFunction2(k);

        if (my_map[v] == "") {
            cout << "key es: " << k << endl;
            cout << "Hash es " << v << endl;
            cout << "position " << my_map[v] << endl;
            my_map[v] = k;
        } else {
            cout << "COLISION" << endl;
            cout << "key es: " << k << endl;
            cout << "Hash 2 es " << hash2 << endl;
            //    my_map[hash2] = k;
            collisions++;
            while (my_map[v] != "")
                v = (v + hash2) % table_size;
            cout << "la colision pasa a: " << v << endl;
            my_map[v] = k;

        }
    }*/

 //   cout << "Number of collisions: " << collisions << endl;
    cout << endl;
}


// inserts an element into a map
void MapHash::rehashing(string k, int v){

    int size = my_map2.size();
  //  cout << "size es " << size << endl;
    v = hashFunction1(k, size);
    int hash2 = hashFunction2(k, size);

/*    int next_prime = 0;

    cout << "REHASHING" << endl;
    table_size = my_map2.size();
    cout << "HASH T SIZE: " << table_size << endl;
    table_size = table_size*2; //double size of hashtable
    cout << "HASH T SIZE x 2: " << table_size << endl;
    next_prime = primeNumber(table_size);   // look for next prime
    cout << "NEXT PRIME: " << next_prime << endl;
    table_size = next_prime; */

    if (my_map2[v] == "") {
        /*cout << "key es: " << k << endl;
        cout << "Hash es " << v << endl;
        cout << "position " << my_map2[v] << endl;*/
        my_map2[v] = k;
    } else {
       /* cout << "COLISION" << endl;
        cout << "key es: " << k << endl;
        cout << "Hash 2 es " << hash2 << endl;*/
        //    my_map[hash2] = k;

        while (my_map2[v] != "")
            v = (v + hash2) % size;
     //   cout << "la colision pasa a: " << v << endl;
        my_map2[v] = k;
        collisions2++;

    }
}

// searches the container for an element with a key equivalent to k and returns it if found
int MapHash::atEncontrar(string k) {

    int size = my_map.size();

    int hash1 = hashFunction1(k, size);
    int hash2 = hashFunction2(k, size);
    int count = 0;
    if(my_map[hash1] == k){
        cout << "Encontrado DH: " << my_map[hash1] << endl;
        return hash1;
    }

    else {
        while (my_map[hash1] != "") {
            hash1 = (hash1 + hash2) % size;
        //    cout << "hash1 es dentro: " << hash1 << endl;
            if (my_map[hash1] == k) {
                cout << "Encontrado DH: " << my_map[hash1] << endl;
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
void MapHash::eraseBorrar(string k) {
    int size = my_map.size();
    cout << "BORRAR" << endl;
    int hash1 = hashFunction1(k, size);
    int hash2 = hashFunction2(k, size);

    if(my_map[hash1] == k){
        my_map[hash1] = "";
        cout << "Borrado 1: " << my_map[hash1] << endl;}

    else {
        while (my_map[hash1] != "") {
            hash1 = (hash1 + hash2) % size;
            cout << "hash1 es dentro: " << hash1 << endl;
            if (my_map[hash1] == k) {
                cout << "Econtrado: " << my_map[hash1] << endl;
                my_map[hash1] = "";
                cout << "Econtrado: " << my_map[hash1] << endl;
                break;
            }
            /*else{
                cout << "Value NOT DELETED" << endl;
                break;
            }*/

        }
    }
}


void MapHash::showMap1(){
   /*for(int i = 0; i< my_map.size();i++){
       if(my_map[i] == "") cout << "posicion vacia" << " posicion " << i << endl;
       else cout << "String: " << my_map[i] << " posicion " << i << endl;
   }*/
    cout << "Nº de colisiones: " << collisions<< endl;
}


void MapHash::showMap2(){
    /*for(int i = 0; i< my_map2.size();i++){
        if(my_map2[i] == "") cout << "posicion vacia" << " posicion " << i << endl;
        else cout << "String: " << my_map2[i] << " posicion " << i << endl;
    }*/
    cout << "Nº de colisiones2: " << collisions2<< endl;
}

