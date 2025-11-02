#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath>     // For std::floor and std::ceil

/**
 * @brief Calculates a specific percentile from a pre-sorted vector.
 * * This function uses linear interpolation, which is the standard method
 * used by libraries like NumPy and pandas (default).
 *
 * @param sortedData A const reference to a vector<double> that is already sorted.
 * @param p The percentile to find (e.g., 0.25 for Q1, 0.75 for Q3).
 * @return The calculated percentile value as a double.
 **/
double getPercentile(const std::vector<double>& sortedData, double p) {
    int n = sortedData.size();
    if (n == 0) return 0.0;

    double index = p * (n - 1);
    int lower = static_cast<int>(std::floor(index));
    int upper = static_cast<int>(std::ceil(index));
    double fraction = index - lower;

    if (lower == upper) {
        return sortedData[lower];
    }

    // Linear interpolation
    return sortedData[lower] * (1.0 - fraction) + sortedData[upper] * fraction;
}

/**
 * @brief Finds outliers in a vector of doubles using the 1.5 * IQR rule.
 *
 * @param data A const reference to the input vector<double>. The original
 * vector is not modified.
 * @return A std::vector<double> containing only the outlier values.
 */
std::vector<double> findOutliers(const std::vector<double>& data) {
    std::vector<double> outliers;
    if (data.empty()) {
        return outliers; // Return empty vector if input is empty
    }

    // 1. Make a copy and sort it to find quartiles
    std::vector<double> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());

    // 2. Find Q1 (25th percentile) and Q3 (75th percentile)
    double q1 = getPercentile(sortedData, 0.25);
    double q3 = getPercentile(sortedData, 0.75);

    // 3. Calculate IQR
    double iqr = q3 - q1;

    // 4. Calculate the outlier bounds
    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;

    std::cout << "--- Debug Info ---" << std::endl;
    std::cout << "Q1: " << q1 << std::endl;
    std::cout << "Q3: " << q3 << std::endl;
    std::cout << "IQR: " << iqr << std::endl;
    std::cout << "Lower Bound: " << lowerBound << std::endl;
    std::cout << "Upper Bound: " << upperBound << std::endl;
    std::cout << "------------------" << std::endl;


    // 5. Iterate through the *original* data to find values outside the bounds
    for (double val : data) {
        if (val < lowerBound || val > upperBound) {
            outliers.push_back(val);
        }
    }

    return outliers;
}

int main() {
    // Example dataset with some clear outliers
    std::vector<double> myData = {10, 20, 21, 23, 24, 25, 26, 28, 30, 100, -50};

    std::vector<double> outliers = findOutliers(myData);

    std::cout << "Original Data: ";
    for (double val : myData) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "\nOutliers Found: ";
    
    if (outliers.empty()) {
        std::cout << "None";
    } else {
        for (double out : outliers) {
            std::cout << out << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}