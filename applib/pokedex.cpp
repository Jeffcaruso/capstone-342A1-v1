/*
 * Implementation of Pokedex
 * Bruce Duong
 * Pisan 342
 */

#include "pokedex.h"
#include <iostream>

using namespace std;

Pokedex::Pokedex() {
  // initialize empty pokedex
  msize = 0;
}

/**
 * Returns number of pokemon currently in pokedex
 */
int Pokedex::size() const { return msize; }

/**
 * Returns the maximum capacity of the pokedex
 */
int Pokedex::max_size() { return MAX; }

/**
 * Checks if Pokedex is empty
 * Returns true if empty
 */
bool Pokedex::empty() const { return msize == 0; }

/**
 * Returns pokemon at a given index
 * Needs to check for invalid input
 */
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot access element at " << n << endl;
    return pokemons[0];
  }
  return pokemons[n];
}

/**
 * Return pokemon at the front, alphabetically first one
 */
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front for empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[0];
}

/**
 * Return pokemon at the front, alphabetically last one
 */
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back for empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[msize - 1];
}

/**
 * Add Pokemon to Pokedex, keep the Pokedex list sorted
 * Multiple pokemon can have the same name
 * If pokedex is already full, do not insert
 */
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
    cerr << "Error: Pokedex is already full" << endl;
    return;
  }
  /*
   * When inserting a pokemon, you need to find the correct location
   * alphabetically and then shift all the pokemon that come after it.
   */
  int insertionIndex = 0;
  while (insertionIndex < msize && pokemons[insertionIndex] < pokemon) {
    insertionIndex++;
  }
  for (int i = msize; i > insertionIndex; i--) {
    // shift elements from the end down
    pokemons[i] = pokemons[i - 1];
  }
  pokemons[insertionIndex] = pokemon;
  msize++;
}

/**
 * Delete the last element
 */
void Pokedex::pop_back() {
  if (empty()) {
    cerr << "Error: Cannot pop_back for empty Pokedex" << endl;
    return;
  }
  // when removing, ok to leave old value in place
  msize--;
}

/**
 * Erase an element at a specific location, move elements as needed
 * undefined behavior if given index is not valid
 */
void Pokedex::erase(int n) {
  if (n < 0 || n > msize) {
    cerr << "Error: Cannot erase element at " << n << endl;
    return;
  }
  for (int i = n; i < msize; i++) {
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
    for (int i = 0; i < pdx.size(); i++) {
      out << pdx.at(i);
      if (i < pdx.size() - 1) {
        out << ", ";
      }
    }
    out << "]";
  }
  return out;
}
