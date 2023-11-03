/**
 * Pokedex class
 * Pokemon are represented as string objects
 * Can add and remove pokemon, print pokedex
 * Internally pokedex is an array and all pokemon are kept sorted
 *
 * Calling a function with invalid parameters causes undefined behavior.
 * For our purposes, if a function has been called with invalid parameters
 * and needs to return a value, the first element in the pokedex is returned.
 **/

#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <string>

using namespace std;

class Pokedex {
public:
  // Constructor creates empty Pokedex
  Pokedex();

  // Returns size of Pokedex
  int size() const;

  // Returns maximum size, capacity of Pokedex
  static int max_size();

  // Returns true if the Pokedex is empty
  bool empty() const;

  // Returns pokemon at given index
  // If given index is n < 0 or n >= size, returns first index
  const string &at(int n) const;

  // Return pokemon at the front, alphabetically first one
  const string &front() const;

  // Return pokemon at the front, alphabetically last one
  const string &back() const;

  // Allows pokemon to be added to Pokedex, sorted alphabetically
  // Does not allow pokemon to be inserted if Pokedex is full
  void insert(const string &pokemon);

  // Deletes the last element
  void pop_back();

  // Erases element at location, moves other elements as needed
  // Index is invalid if there is no element at location
  void erase(int n);

private:
  // maximum capacity of Pokedex
  static const int MAX = 10;

  // sorted list of pokemon in Pokedex
  string pokemons[MAX];

  // current internal size
  int msize = 0;
};

// Insertion operator allows Pokedex to be output using "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx);

#endif // POKEDEX_H