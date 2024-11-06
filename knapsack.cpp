#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// Define a structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Comparison function to sort items based on their value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Descending order of ratio
}

// Function to calculate the maximum value for the fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Step 1: Sort items by their value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0; // Variable to store the maximum value

    // Step 2: Iterate through the sorted items to fill the knapsack
    for (int i = 0; i < items.size(); i++) {
        // If the entire item can fit in the remaining capacity, take it all
        if (W >= items[i].weight) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            // If the entire item can't fit, take the fraction that fits
            maxValue += items[i].value * ((double)W / items[i].weight);
            break; // Knapsack is full, exit loop
        }
    }

    return maxValue; // Return the maximum value that fits in the knapsack
}

int main() {
    int W = 50; // Total capacity of knapsack
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // Define items

    // Calculate and display the maximum value possible
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;

    return 0;
}
