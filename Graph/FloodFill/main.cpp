#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// -----------------------------------------------------------------------------
// This function changes the color of the current cell and all the adjacent cells
void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
    // If we are out of bounds or if the current cell is not the same color as the old color we return
    if (i < 0 || j < 0 || i >= image.size() || j >= image[i].size() || image[i][j] != oldColor) return;
    // Change the color of the current cell
    image[i][j] = newColor;
    // Call the dfs function on all the adjacent cells (up, down, left, right)
    dfs(image, i + 1, j, oldColor, newColor);
    dfs(image, i - 1, j, oldColor, newColor);
    dfs(image, i, j + 1, oldColor, newColor);
    dfs(image, i, j - 1, oldColor, newColor);
}

// -----------------------------------------------------------------------------
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // If the current cell is the same color as the new color we return
    if (image[sr][sc] == color) return image;
    // Call the dfs function to change the color of the current cell and all the adjacent cells
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}

// -----------------------------------------------------------------------------
int main () {
    // Read the number of rows and columns
    int rows, cols;
    cin >> rows >> cols;
    // Read the image
    vector<vector<int>> image(rows, vector<int>(cols));
    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) cin >> image[i][j];
    }
    // Read the starting row and column
    int sr, sc;
    cin >> sr >> sc;
    // Read the new color
    int color;
    cin >> color;
    // Call the floodFill function
    image = floodFill(image, sr, sc, color);
    // Print the image
    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) cout << image[i][j] << " ";
        cout << endl;
    }
    return 0;
}
