#ifndef PRODUCT_H
#define PRODUCT_H

#include "utils.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================
// PRODUCT CLASS
// ============================================
// Represents a product in the inventory system

class Product {
private:
  string id;          // Product ID (e.g., "P001")
  string name;        // Product name
  string category;    // Product category
  string description; // Product description
  double price;       // Product price
  int quantity;       // Stock quantity

public:
  // ============================================
  // CONSTRUCTORS
  // ============================================
  Product();
  Product(const string &id, const string &name, const string &category,
          const string &description, double price, int quantity);

  // ============================================
  // DISPLAY METHODS
  // ============================================
  void displayInfo() const;
  void displayShort() const; // One-line display for listings

  // ============================================
  // STOCK MANAGEMENT
  // ============================================
  bool isInStock() const { return quantity > 0; }
  bool hasStock(int amount) const { return quantity >= amount; }
  void reduceStock(int amount);
  void addStock(int amount);

  // ============================================
  // GETTERS
  // ============================================
  string getId() const { return id; }
  string getName() const { return name; }
  string getCategory() const { return category; }
  string getDescription() const { return description; }
  double getPrice() const { return price; }
  int getQuantity() const { return quantity; }

  // ============================================
  // SETTERS (with validation)
  // ============================================
  void setName(const string &newName);
  void setCategory(const string &newCategory);
  void setDescription(const string &newDescription);
  void setPrice(double newPrice);
  void setQuantity(int newQuantity);

  // ============================================
  // COMPARISON OPERATORS
  // ============================================
  bool operator==(const Product &other) const { return id == other.id; }
  bool operator!=(const Product &other) const { return id != other.id; }
};

#endif
