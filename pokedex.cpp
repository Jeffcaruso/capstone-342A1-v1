/**
 * Pokedex class
 * Pokemon are represented as string objects
 * Add, remove, and print Pokemon in sorted alphabetical order
 *
 * Functions called with invalid parameters return first element in Pokedex
 **/

#include "pokedex.h"
#include <iostream>

using namespace std;

// Constructor initializes Pokedex to empty strings and size to 0
Pokedex::Pokedex() {
  for (int i = 0; i < MAX; i++) {
    pokemons[i] = "";
  }
  msize = 0;
}

// Returns current size of Pokedex
int Pokedex::size() const { return msize; }

// Returns maximum capacity of Pokedex
int Pokedex::max_size() { return MAX; }

// Returns true if Pokedex is empty, otherwise false
bool Pokedex::empty() const { return msize == 0; }

// Returns Pokemon at a given index
// Prints error message if given index is < 0 or > max size and returns the
// first element
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot access element at index " << n << endl;
    return pokemons[0];
  }
  return pokemons[n];
}

// Returns Pokemon at the front, alphabetically the first
// Prints error message if Pokedex if empty and returns the first element
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front of empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[0];
}

// Returns Pokemon at the back, alphabetically the last
// Prints error message if Pokedex is empty and returns the first element
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back of empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[msize - 1];
}

// Inserts Pokemon in alphabetically sorted order
// Prints error message if Pokedex is full
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
    cerr << "Error: Cannot insert on a full Pokedex" << endl;
    return;
  }

  int index = msize;
  while (index > 0 && pokemon < pokemons[index - 1]) {
    pokemons[index] = pokemons[index - 1];
    index--;
  }
  pokemons[index] = pokemon;
  msize++;
}

// Deletes Pokemon at the last index
// Prints error message if Pokedex is empty
void Pokedex::pop_back() {
  if (empty()) {
    cerr << "Error: Cannot delete on an empty Pokedex" << endl;
    return;
  }

  msize--;
  pokemons[msize] = "";
}

// Removes Pokemon at a given index
// Prints error message if invalid index is given
void Pokedex::erase(int n) {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot erase element at index " << n << endl;
    return;
  }

  for (int i = n; i < msize - 1; i++) {
    pokemons[i] = pokemons[i + 1];
  }
  pokemons[msize - 1] = "";
  msize--;
}

// Prints Pokemon names, separated by commas and enclosed with square
// brackets []
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  for (int i = 0; i < pdx.size(); i++) {
    out << pdx.at(i);
    if (i < pdx.size() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}