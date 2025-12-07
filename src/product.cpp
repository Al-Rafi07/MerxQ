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
                           "cyan")
       << endl;
  cout << Utils::colorText("│", "cyan") << " "
       << Utils::colorText("📦 " + name, "white", "", "bold") << endl;
  cout << Utils::colorText("├──────────────────────────────────────────┤",
                           "cyan")
       << endl;
  cout << Utils::colorText("│", "cyan")
       << " ID:       " << Utils::colorText(id, "yellow") << endl;
  cout << Utils::colorText("│", "cyan")
       << " Category: " << Utils::colorText(category, "magenta") << endl;
  cout << Utils::colorText("│", "cyan") << " Price:    "
       << Utils::colorText("$" + to_string(price), "green", "", "bold") << endl;
  cout << Utils::colorText("│", "cyan") << " Stock:    ";

  if (quantity > 10) {
    cout << Utils::colorText(to_string(quantity) + " units", "green") << endl;
  } else if (quantity > 0) {
    cout << Utils::colorText(to_string(quantity) + " units (Low!)", "yellow")
         << endl;
  } else {
    cout << Utils::colorText("Out of Stock!", "red", "", "bold") << endl;
  }

  cout << Utils::colorText("│", "cyan") << " " << description << endl;
  cout << Utils::colorText("└──────────────────────────────────────────┘",
                           "cyan")
       << endl;
}

