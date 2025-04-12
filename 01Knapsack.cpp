/**
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>
using namespace std;

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

void printTable(const vector<vector<int>>& dp, const vector<int>& weights, const vector<int>& values, int highlight_i = -1, int highlight_w = -1) {
    int n = weights.size();
    int capacity = dp[0].size() - 1;

    // Print column headers
    cout << "       |";
    for (int w = 0; w <= capacity; ++w)
        cout << setw(4) << w << " ";
    cout << "\n" << string(9 + (capacity + 1) * 5, '-') << "\n";

    for (int i = 0; i <= n; ++i) {
        // Print row label
        if (i == 0)
            cout << "Item 0 |";
        else
            cout << "Item " << i << " |";

        // Print cells
        for (int w = 0; w <= capacity; ++w) {
            if (i == highlight_i && w == highlight_w)
                cout << "[" << setw(2) << dp[i][w] << "] ";
            else
                cout << setw(4) << dp[i][w] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    clearScreen();
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter weight for item " << i+1 << ": ";
        cin >> weights[i];
        cout << "Enter value for item " << i+1 << ": ";
        cin >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int delay = 800;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; ++w) {
            clearScreen();
            string decision;

            if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);

                if (include > exclude) {
                    decision = "Include Item " + to_string(i) + ": dp[" + to_string(i) + "][" + to_string(w) +
                              "] = " + to_string(values[i - 1]) + " + dp[" + to_string(i - 1) + "][" +
                              to_string(w - weights[i - 1]) + "] = " + to_string(dp[i][w]);
                } else {
                    decision = "Exclude Item " + to_string(i) + ": dp[" + to_string(i) + "][" + to_string(w) +
                              "] = dp[" + to_string(i - 1) + "][" + to_string(w) + "] = " + to_string(dp[i][w]);
                }
            } else {
                dp[i][w] = dp[i - 1][w];
                decision = "Cannot include Item " + to_string(i) + " (too heavy), carry dp[" +
                           to_string(i - 1) + "][" + to_string(w) + "] = " + to_string(dp[i][w]);
            }

            cout << "Computing dp[" << i << "][" << w << "]\n\n";
            printTable(dp, weights, values, i, w);
            cout << decision << "\n";

            this_thread::sleep_for(chrono::milliseconds(delay));
        }
    }

    // Backtrack to find selected items
    int w = capacity;
    vector<int> selected;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i);
            w -= weights[i - 1];
        }
    }

    // Final output
    clearScreen();
    cout << "Final DP Table:\n\n";
    printTable(dp, weights, values);
    cout << "Maximum value: " << dp[n][capacity] << "\n";
    cout << "Items included (1-indexed): ";

    if( selected.empty() ) {
        cout << "None";
    }
    else {
    for (int i = selected.size() - 1; i >= 0; --i)
        cout << selected[i] << " ";
    }
    cout << "\n";

    return 0;
}
*/










#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>
using namespace std;

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

void printTable(const vector<vector<int>>& dp, const vector<int>& weights, const vector<int>& values, int highlight_i = -1, int highlight_w = -1) {
    int n = weights.size();
    int capacity = dp[0].size() - 1;

    // Print column headers
    cout << "       |";
    for (int w = 0; w <= capacity; ++w)
        cout << setw(4) << w << " ";
    cout << "\n" << string(9 + (capacity + 1) * 5, '-') << "\n";

    for (int i = 0; i <= n; ++i) {
        // Print row label
        if (i == 0)
            cout << "Item 0 |";
        else
            cout << "Item " << i << " |";

        // Print cells
        for (int w = 0; w <= capacity; ++w) {
            if (i == highlight_i && w == highlight_w)
                cout << "[" << setw(2) << dp[i][w] << "] ";
            else
                cout << setw(4) << dp[i][w] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    clearScreen();
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << endl;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {

        cout << "Enter weight for item " << i+1 << ": ";
        cin >> weights[i];

        cout << "Enter value for item " << i+1 << ": ";
        cin >> values[i];

        cout << endl;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int delay = 2000;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; ++w) {
            clearScreen();
            string decision;

            if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);

                if (include > exclude) {
                    decision = "Include Item " + to_string(i) + ": dp[" + to_string(i) + "][" + to_string(w) +
                              "] = " + to_string(values[i - 1]) + " + dp[" + to_string(i - 1) + "][" +
                              to_string(w - weights[i - 1]) + "] = " + to_string(dp[i][w]);
                } else {
                    decision = "Exclude Item " + to_string(i) + ": dp[" + to_string(i) + "][" + to_string(w) +
                              "] = dp[" + to_string(i - 1) + "][" + to_string(w) + "] = " + to_string(dp[i][w]);
                }
            } else {
                dp[i][w] = dp[i - 1][w];
                decision = "Cannot include Item " + to_string(i) + " (too heavy), carry dp[" +
                           to_string(i - 1) + "][" + to_string(w) + "] = " + to_string(dp[i][w]);
            }

            cout << "Computing dp[" << i << "][" << w << "]\n\n";
            printTable(dp, weights, values, i, w);
            cout << decision << "\n";

            this_thread::sleep_for(chrono::milliseconds(delay));
        }
    }

    // Backtrack to find selected items
    int w = capacity;
    vector<int> selected;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i);
            w -= weights[i - 1];
        }
    }

    // Final output
    clearScreen();
    cout << "Final DP Table:\n\n";
    printTable(dp, weights, values);
    cout << "Maximum value: " << dp[n][capacity] << "\n";

    cout << "Items included (1-indexed): ";

    if( selected.empty() ) {
        cout << "None";
    }
    else {
    for (int i = selected.size() - 1; i >= 0; --i)
        cout << selected[i] << " ";
    }
    cout << "\n";

    return 0;
}


