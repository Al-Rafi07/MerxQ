#include "../include/product.h"
#include "../include/exceptions.h"
#include <iomanip>
#include <sstream>

// ============================================
// CONSTRUCTORS
// ============================================

Product::Product()
    : id(""), name(""), category(""), description(""), price(0.0), quantity(0) {
}

Product::Product(const string &id, const string &name, const string &category,
                 const string &description, double price, int quantity)
    : id(id), name(name), category(category), description(description),
      price(price), quantity(quantity) {}

// ============================================
// DISPLAY METHODS
// ============================================

void Product::displayInfo() const {
  cout << Utils::colorText("┌──────────────────────────────────────────┐",
                           "yellow")
       << endl;
  cout << Utils::colorText("│", "yellow") << " "
       << Utils::colorText("📦 " + name, "white", "", "bold") << endl;
  cout << Utils::colorText("├──────────────────────────────────────────┤",
                           "yellow")
       << endl;
  cout << Utils::colorText("│", "yellow")
       << " ID:       " << Utils::colorText(id, "yellow") << endl;
  cout << Utils::colorText("│", "yellow")
       << " Category: " << Utils::colorText(category, "yellow") << endl;
  cout << Utils::colorText("│", "yellow") << " Price:    "
       << Utils::colorText("$" + to_string(price), "green", "", "bold") << endl;
  cout << Utils::colorText("│", "yellow") << " Stock:    ";

  if (quantity > 10) {
    cout << Utils::colorText(to_string(quantity) + " units", "green") << endl;
  } else if (quantity > 0) {
    cout << Utils::colorText(to_string(quantity) + " units (Low!)", "yellow")
         << endl;
  } else {
    cout << Utils::colorText("Out of Stock!", "red", "", "bold") << endl;
  }

  cout << Utils::colorText("│", "yellow") << " " << description << endl;
  cout << Utils::colorText("└──────────────────────────────────────────┘",
                           "yellow")
       << endl;
}

void Product::displayShort() const {
  stringstream priceStr;
  priceStr << fixed << setprecision(2) << price;

  string stockStatus =
      quantity > 0
          ? Utils::colorText("[" + to_string(quantity) + " in stock]", "green")
          : Utils::colorText("[Out of Stock]", "red");

  cout << Utils::colorText(id, "yellow") << " | "
       << Utils::colorText(name, "white", "", "bold") << " | "
       << Utils::colorText("$" + priceStr.str(), "green") << " | "
       << Utils::colorText(category, "yellow") << " " << stockStatus << endl;
}

// ============================================
// STOCK MANAGEMENT
// ============================================

void Product::reduceStock(int amount) {
  if (amount <= 0) {
    throw InvalidInputException("Amount must be positive");
  }
  if (quantity < amount) {
    throw InsufficientStockException("Not enough stock for " + name);
  }
  quantity -= amount;
}

void Product::addStock(int amount) {
  if (amount <= 0) {
    throw InvalidInputException("Amount must be positive");
  }
  quantity += amount;
}
// ============================================
// SETTERS (with validation)
// ============================================

void Product::setName(const string &newName) {
  if (newName.empty()) {
    throw InvalidInputException("Product name cannot be empty");
  }
  name = newName;
}

void Product::setCategory(const string &newCategory) {
  if (newCategory.empty()) {
    throw InvalidInputException("Category cannot be empty");
  }
  category = newCategory;
}

void Product::setDescription(const string &newDescription) {
  description = newDescription;
}

void Product::setPrice(double newPrice) {
  if (newPrice < 0) {
    throw InvalidInputException("Price cannot be negative");
  }
  price = newPrice;
}

void Product::setQuantity(int newQuantity) {
  if (newQuantity < 0) {
    throw InvalidInputException("Quantity cannot be negative");
  }
  quantity = newQuantity;
}
