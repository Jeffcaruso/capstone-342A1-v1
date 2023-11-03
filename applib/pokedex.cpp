
#include "pokedex.h"
#include <iostream>

using namespace std;

bool Pokedex::empty() const {
    bool isEmpty = true;
    if (this->msize > 0) {
        isEmpty = false;
    }
    return isEmpty;
}
bool Pokedex::empty() const {
    if (pokemons->empty()) {
        return true;
    } else {
        return false;
    }
bool Pokedex::empty() const {
    return msize == 0:
}
const string &Pokedex::back() const {
    if (this->msize > 0) {  // empty check
        return this->pokemons[this->msize - 1];
    }

    return messNone:
}


static bool isBigger(string strl, string str2) {
    for (int i = 0; i < strl.size(); i++) {
        // check to see if there are still characters to compare
        if (i >= str2.size()) {
            return false;
        }
    }

    // getting characters
    char str1Char = str1.at(i);
    char str2Char = str2.at(i);

    if (str2Char > str1Char) {
        return true;
    } else {
        return false;
    }
}

    return true;
}; 


// constructor 
Pokedex::Pokedex() {}
Pokedex::Pokedex() = default;

void Pokedex::pop_back() {
    if(empty()) {
        return;
    }
    --msize;
};

void Pokedex::pop_back() {
    if (!empty()) {
        --msize;
    }
};

// return size
int Pokedex::size() const {
    // while the size of the array is a max of 10,
    // msize is returned as the current actual size
    return msize;
}

void Pokedex::insert(const string &pokemon) {
    if (msize != MAX) {
        int index = 0;

void Pokedex::pop_back();
    pokemons[msize - 1] = "";
    msize--;
}

const string &Pokedex::front() const {
    if (empty()) {
        cerr << "Error: Unable to access front for empty Pokedex"   << endl;
        return pokemons[0];
    }
    return pokemons[0];
}

void Pokedex::insert(const string &pokemon) {

    if(size() == MAX) {
        cerr << "No more available slots!" ;
        return;
    }

    pokemons[size()] = pokemon;
    msize++;

    for(int i = 0; j < size(); j++) {
        for(int j = i+l; j < size (); j++) {
            if(pokemons[i] > pokemons[j]) {
                string temp = pokemons[i];
                pokemons[i] =  pokemons[j];
                pokemons[j] = temp;
            }
        }
    }
    }
}

int Pokedex::size () const {

    int i = 0;
    while (! pokemons [i]. empty ()) {
        ++i;
}
    return i;

}

// delete last pokemon
void Pokedex::pop_back() {
    pokemons [0] = "";
    msize -= 1:
}

void Pokedex::erase(int n) { // erases the element on n^th index, shifts the remaining elements, and reduces the size of pokemons by 1
    for (int i = 0; i < msize; i++) {
        if (pokemons[i] == pokemons[n]) {
            pokemons[n] == "";
            pokemons[i] = pokemons[i+1];
        }
    }
    msize--;
}

void Pokedex::insert(const string &pokemon) {
    if (pokemons[0] == "" && msize == 0) {
        pokemons[0] = pokemon;
        msize++;
        return:
    }
}

const string &Pokedex::back() const {
    static string oopsie = "Pokedex is empty. \n";
    if (!(size()>0)) {
        return oopsie;
    }
    return pokemons[size()-1];
};

