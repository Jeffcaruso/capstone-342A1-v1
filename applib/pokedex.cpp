
#include "pokedex.h"
#include <iostream>

using namespace std;

// Your code goes here

// returns the element in that index
// if the index is invalid, we return the zeroth element in the array and print an error message
const string &Pokedex::at(int n) const {
    if(msize - 1 < n || n < 0) {
        cout << "Error: Cannot access element at " << n << endl;
        return pokemons[0];
    }
    return pokemons[n];
}

// returns the last element 
// if the array is empty then output an error message and return the zeroth index because I couldn't figure out what to return
const string &Pokedex::back() const {
    if(empty()) {
        cerr << "Error: Cannot access back for empty Pokedex" << endl;
        return pokemons[0];
    }
    return pokemons[msize - 1];
}

// if the array is empty returns true otherwise false
bool Pokedex::empty() const {
    return msize == 0;
}

// erases the n'th index from the array
// if the index is invalid then we output an error message
void Pokedex::erase(int n) {
    if(msize > n && n > -1) {
        for(int i = n + 1; msize > i; i++) { // moving it to left by one
            pokemons[i - 1] = pokemons[i];
        }

        msize--; // decrease the size
    }
    else {
        cerr << "Error: Cannot erase element at " << n << endl;
    }
}

// returns the first element of the array
// if the array is empty then we output an error message and still return the zeroth element because we have to return something and I couldn't figure out what to return
const string &Pokedex::front() const {
    if(empty()) {
        cerr << "Error: Cannot access front for empty Pokedex" << endl;
    }
    return pokemons[0];
    
}

// insert the pokemon to the right spot in order, sorted
void Pokedex::insert(const string &pokemon) {
    if(msize < MAX) { // if the array is not full
        // when array is empty
        if(msize == 0) {
            pokemons[0] = pokemon;
        }
        else {
            int insInd = 0; // insert index - where the input pokemon will be inserted at
            // we find where the insertion will be for our input
            while(pokemons[insInd] < pokemon && msize > insInd) { 
                insInd++;
            }

            // adding to the front of the array
            if(insInd == 0) {
                // moving everything by one to the right starting from the end of the array
                for(int i = msize - 1; i >= 0; i--) {
                    pokemons[i+1] = pokemons[i];
                }
                pokemons[0] = pokemon;
            }

            // adding to the end of the array
            else if(insInd == msize) {
                pokemons[insInd] = pokemon;
            }

            // adding it to the middle of the array
            else {
                for(int i = msize - 1; insInd <= i; i--) {
                    pokemons[i+1] = pokemons[i];
                }
                pokemons[insInd] = pokemon;
            }

            pokemons[insInd] = pokemon; // adding our input pokemon
        }
        msize++; // size gets incremented by 1
    }
}

// operator overloading, how we pring the pokemons array
ostream &operator<<(ostream &out, const Pokedex &pdx) {
    out << "["; // start
    int pdxSize = pdx.size();
    if(pdxSize > 0) { // if there's anything in the array
        out << pdx.at(0); // for the format we do it this way
        for(int i = 1; pdxSize > i; i++) {
            out << ", " << pdx.at(i);
        }
    }
    out << "]"; // end
    return out; // print
}

// empty constructor
Pokedex::Pokedex() {

}

// if the size of the array is greater than one, erases the last one
// if the array is empty then we output an error message
void Pokedex::pop_back() {
    if(empty()) {
        cerr << "Error: Cannot pop_back for empty Pokedex" << endl;
    }
    else {
        msize--;

    }
}

// returns the size of the array by using the msize private data member
int Pokedex::size() const {
    return msize;
}