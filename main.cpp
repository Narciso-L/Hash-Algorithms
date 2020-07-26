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
#include <ctime>
#include <vector>
#include "MapHash.h"
#include "LinearProbing.h"
#include "SeparateChaining.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    vector<string> V;
    string line;
    int i = 0;
    ifstream filein (argv[1]);
    if (filein.is_open())
    {
        while ( getline (filein,line) )
        {
         //   cout << line << '\n';
            V.push_back(line);
        }
        filein.close();
    }
    else cout << "Unable to open file";

    //vector<string> V = {"to","be","or","not","cau","been","by","me"};//,"u","puxi","saru","tobi","nano","kk","ff","we","qw","fr","kiki","hhh","ooo","pwe","rf"};//,"gg","tre","muei","cait","fic","andrea"};//}; //

    MapHash* hashtable = new MapHash() ;
 //    LinearProbing* hashtable = new LinearProbing() ;
  //  SeparateChaining* hashtable = new SeparateChaining();


    int load_factor = 0;
    int elements = 0;

 //   cout << "V size: " << V.size() << endl;
  //  cout << "SIZE HASHTABLE: " << hashtable->size() << endl;

    clock_t clk = clock();


    for(int i = 0;i<V.size();i++){

        load_factor = (elements/(hashtable->size()));    //load factor equals to number of elements in hash table divided with TABLE_SIZE
     //   cout << "SIZE HASHTABLE: " << hashtable->size() << endl;
        if(load_factor < 1){
            hashtable->insertar(V[i],i);
            elements++;
            // cout << " " << V[i];
        }
        else{ //rehashing
       //     cout << "************************REHASHING*********************************" << endl;
        //    cout << "SIZE HASHTABLE: " << hashtable->size() << endl;
         /*   table_size = hashtable->size();
            cout << "HASH T SIZE: " << table_size << endl;
            table_size = table_size*2; //double size of hashtable
            cout << "HASH T SIZE x 2: " << table_size << endl;
            next_prime = hashtable->primeNumber(table_size);   // look for next prime
            cout << "NEXT PRIME: " << next_prime << endl;
            table_size = next_prime;*/
            for(int i = 0;i<V.size();i++) {
                hashtable->rehashing(V[i], i);
            }
            break;
        }

    }

    cout<< "Tiempo total: "<< (double)(clock() - clk)/ CLOCKS_PER_SEC << " "<<endl;

    hashtable->showMap1();

    cout << "TABLA 2" << endl << endl;
 //   hashtable->showMap2();

    cout << endl;
//    hashtable->countCollisions();
    cout << endl;
    cout << endl;
 //   hashtable->countCollisions2();

    cout << endl;
    clk = clock();

    //Primeros 5            //METERLO EN UN VECTOR!!
    int valor = hashtable->atEncontrar("abrico");
    valor = hashtable->atEncontrar("abri");
    valor = hashtable->atEncontrar("aah");
    valor = hashtable->atEncontrar("abac");
    valor = hashtable->atEncontrar("abs");
    //10 valores
    valor = hashtable->atEncontrar("abreid");
    valor = hashtable->atEncontrar("abreuvoir");
    valor = hashtable->atEncontrar("abreast");
    valor = hashtable->atEncontrar("abray");
    valor = hashtable->atEncontrar("abr");
    //15 valores
    valor = hashtable->atEncontrar("abox");
    valor = hashtable->atEncontrar("abow");
    valor = hashtable->atEncontrar("above");
    valor = hashtable->atEncontrar("aboulic");
    valor = hashtable->atEncontrar("abote");
    //20 valores
    valor = hashtable->atEncontrar("abort");
    valor = hashtable->atEncontrar("abolla");
    valor = hashtable->atEncontrar("abdominocystic");
    valor = hashtable->atEncontrar("abdom");
    valor = hashtable->atEncontrar("abby");
    //25 valores
    valor = hashtable->atEncontrar("abbreviates");
    valor = hashtable->atEncontrar("abbozzo");
    valor = hashtable->atEncontrar("abbotnullius");
    valor = hashtable->atEncontrar("abbeystede");
    valor = hashtable->atEncontrar("abbatical");
    //30 valores
    valor = hashtable->atEncontrar("abba");
    valor = hashtable->atEncontrar("abaxile");
    valor = hashtable->atEncontrar("abattoirs");
    valor = hashtable->atEncontrar("abatjour");
    valor = hashtable->atEncontrar("abalienation");

   // cout << "Valor " << valor <<endl;
    cout<< "Tiempo total: "<< (double)(clock() - clk)/ CLOCKS_PER_SEC << " "<<endl;

 /*   cout << "BORRAR " << endl;
    hashtable->eraseBorrar("me");


    int valor2 = hashtable->atEncontrar("me");
    cout << "Valor " << valor2 <<endl <<endl;

    cout << "MOSTAR FINAL" << endl;
    hashtable->showMap1();*/

   /* int valor3 = hashtable->atEncontrar("by");  //cau para linear
    cout << "Valor " << valor3 <<endl;

    hashtable->eraseBorrar("by");


    int valor4 = hashtable->atEncontrar("by");
    cout << "Valor no encontrado " << valor4 <<endl << endl;

    hashtable->eraseBorrar("by");

    hashtable->showMap1();*/

    return EXIT_SUCCESS;
}