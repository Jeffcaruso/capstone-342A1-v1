
#include "pokedex.h"
#include <iostream>

using namespace std;

// constructor - create empty Pokedex
Pokedex::Pokedex(){};

// Return size
int Pokedex::size() const { return msize; }

// Return maximum size, capacity of Pokedex
int Pokedex::max_size() { return MAX; }

// return true if Pokedex is empty
bool Pokedex::empty() const { return (msize == 0); }

// return pokemon at given index
// undefined behaviour for n < 0 or n >= size
const string &Pokedex::at(int n) const {
  if (n >= msize || n < 0) {
    cerr << "ERROR: Cannot access element at " << n << endl;
  } else {
    return pokemons[n];
  }
  return pokemons[0];
}

// return pokemon at the front, alphabetically first one
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "ERROR: Cannot access front for empty Pokedex" << endl;
  }
  return pokemons[0];
}

// return pokemon at the back, alphabetically last one
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "ERROR: Cannot access back for empty Pokedex" << endl;
  }
  return pokemons[msize - 1];
}

// Add pokemon to Pokedex, keep the Pokedex list sorted
// Can have multiple pokemon with the same name
// Pokemon is not inserted if Pokedex is already full
void Pokedex::insert(const string &pokemon) {
  if (msize >= MAX) {
    cerr << "ERROR: Pokedex is full, delete pokemon to add more." << endl;
    return;
  }
  int index;
  for (index = msize - 1; index >= 0 && pokemons[index] > pokemon; index--) {
    pokemons[index + 1] = pokemons[index];
  }
  pokemons[index + 1] = pokemon;
  msize++;
}

// Delete the last element
void Pokedex::pop_back() {
  if (empty()) {
    cerr << "ERROR: Cannot pop_back for empty Pokedex" << endl;
  } else {
    msize--;
  }
}

// Erase element at location, move other elements as needed
// undefined behaviour if given index is not valid
void Pokedex::erase(int n) {
  if (n >= msize || n < 0) {
    cerr << "ERROR: Cannot earse element at  " << n << endl;
    return;
  }
  for (int i = n; i < msize; i++) {
    pokemons[i] = pokemons[i + 1];
  }
  msize--;
}

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  out << pdx.pokemons[0];
  ;
  for (int i = 1; i < pdx.size(); i++) {
    out << ", " << pdx.pokemons[i];
  }
  out << "]";
  return out;
}
