
#include "pokedex.h"
#include <iostream>

using namespace std;

// Default constructor for Pokedex, creates empty Pokedex
Pokedex::Pokedex() {}

// Returns the size of the Pokedex
int Pokedex::size() const { return msize; }

// Returns the maximum size/capacity of Pokedex
int Pokedex::max_size() { return MAX; }

// Returns true if the Pokedex is empty
bool Pokedex::empty() const { return msize == 0; }

// Returns pokemon at given index if valid, returns first element if not
// Index is invalid if less than zero or greater than or equal to Pokedex size
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot access element at " << n << endl;
    return pokemons[0];
  }
  return pokemons[n];
}

// Returns pokemon at the front, alphabetically first one
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front for empty Pokedex" << endl;
  }
  return pokemons[0];
}

// Returns pokemon at the back, alphabetically last one
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back for empty Pokedex" << endl;
  }
  return pokemons[msize - 1];
}

// Inserts pokemon to Pokedex according to alphabetical order
// Pokemon is not inserted if Pokedex is already full
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
    cerr << "Error: Cannot insert to a full Pokedex" << endl;
  }
  if (empty()) {
    msize++;
    pokemons[0] = pokemon;
  } else {
    int index = -1;
    for (int i = 0; i < msize; i++) {
      if (pokemon < pokemons[i]) {
        index = 0;
        break;
      }
    }
    if (index == -1) {
      pokemons[msize] = pokemon;
      msize++;
    } else {
      msize++;
      for (int j = msize; j > index; j--) {
        pokemons[j] = pokemons[j - 1];
      }
      pokemons[index] = pokemon;
    }
  }
}

// Deletes last element if pokedex is not empty
void Pokedex::pop_back() {
  if (empty()) {
    cerr << "Error: Cannot pop_back for empty Pokedex" << endl;
  } else {
    msize -= 1;
  }
}

// Erases element at location and moves other elements as needed
// No changes are made if given index is invalid: no element at index
void Pokedex::erase(int n) {
  if (n < 0 || n > MAX - 1 || n > msize) {
    cerr << "Error: Cannot erase element at " << n << endl;
  } else {
    for (int i = n; i < msize - 1; i++) {
      pokemons[n] = pokemons[n + 1];
    }
    msize -= 1;
  }
}

// Insertion operator allows for pokedex to be output using "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  int index = 0;
  out << "[";
  for (index = 0; index < pdx.size(); index++) {
    out << pdx.at(index);
    if (index != pdx.size() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}
