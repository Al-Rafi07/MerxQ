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

