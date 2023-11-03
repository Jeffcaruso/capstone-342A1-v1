
#include "pokedex.h"
#include <iostream>

using namespace std;

int search(const string &target);

// empty constructor
Pokedex::Pokedex() {}

// return current length of array
int Pokedex::size() const { return msize; }

// Return maximum size/capacity of pokedex
int Pokedex::max_size() { return MAX; }

// return true if pokedex is empty
bool Pokedex::empty() const { return msize == 0; }

// return pokemon at the given index
const string &Pokedex::at(int n) const {
  if (n < 0 || n > msize) {
    cerr << "Index out of bounds" << endl;
    return pokemons[0];
  }

  return pokemons[n];
}

// return pokemon at the front index 0
const string &Pokedex::front() const { return pokemons[0]; }

// return pokemon at the back
const string &Pokedex::back() const { return pokemons[msize - 1]; }

// add pokemon to pokedex while keeping pokedex sorted
// pokemon not inserted if pokedex is full
void Pokedex::insert(const string &pokemon) {
  if (msize == 0) {
    pokemons[0] = pokemon;
    msize++;
    return;
  }

  if (msize == MAX) {
    cerr << "Pokedex is full" << endl;
    return;
  }

  int index = search(pokemon);

  for (int i = msize; i > index; i--) {
    pokemons[i] = pokemons[i - 1];
  }
  msize++;
  pokemons[index] = pokemon;
}

// binary search find index of smallest lexographical pokemon greater than
// target returns index of smallest pokemon greater than target
//  also returns if the target is the same as a pokemon
int Pokedex::search(string target) {
  int low = 0;
  int high = msize;
  int result = msize;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (pokemons[mid] == target) {
      return mid;
    }

    if (pokemons[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
      result = mid;
    }
  }

  return result;
}

// Delete the last element
void Pokedex::pop_back() {
  if (msize > 0) {
    msize--;
  } else {
    cerr << "No Pokemon Remaining" << endl;
  }
}

// Erase element at given index and move other elements over
void Pokedex::erase(int n) {
  if (n >= msize || n < 0) {
    cerr << "Index out of bounds" << endl;
    return;
  }

  // moves elements down to fill gap
  for (int i = n; i < msize - 1; i++) {
    pokemons[i] = pokemons[i + 1];
  }

  msize--;
}

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  if (pdx.empty()) {
    out << "[]";
  } else {
    out << "[";

    out << pdx.at(0);

    for (int i = 1; i < pdx.size(); i++) {
      out << ", " << pdx.at(i);
    }

    out << "]";
  }
  return out;
}
