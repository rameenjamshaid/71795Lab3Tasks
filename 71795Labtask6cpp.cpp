#include <iostream>
#include <cmath>
using namespace std;
class MRIGrid {
    int bme_grid[10][10];
    int bme_rows, bme_cols;
public:
    MRIGrid(int bme_r, int bme_c) {
        bme_rows = bme_r;
        bme_cols = bme_c;
    }
    void fillGrid() {
        for (int bme_i = 0; bme_i < bme_rows; bme_i++) {
            for (int bme_j = 0; bme_j < bme_cols; bme_j++) {
                cout << "Enter value [" << bme_i << "][" << bme_j << "]: ";
                cin >> bme_grid[bme_i][bme_j];
            }
        }
    }
    void classifyPixels() {
        int bme_dark = 0, bme_grey = 0, bme_bright = 0;
        for (int bme_i = 0; bme_i < bme_rows; bme_i++) {
            for (int bme_j = 0; bme_j < bme_cols; bme_j++) {
                int bme_val = bme_grid[bme_i][bme_j];
                if (bme_val <= 85)
                    bme_dark++;
                else if (bme_val <= 170)
                    bme_grey++;
                else
                    bme_bright++;
                // Skip first column
                if (bme_j > 0) {
                    if (abs(bme_val - bme_grid[bme_i][bme_j - 1]) > 80)
                        cout << "Edge Point: (" << bme_i << "," << bme_j << ")" << endl;
                }
            }
        }
        cout << "\nDark Tissue = " << bme_dark << endl;
        cout << "Grey Tissue = " << bme_grey << endl;
        cout << "Bright Tissue = " << bme_bright << endl;
    }
};
int main() {
    MRIGrid bme_scan(2, 3);
    bme_scan.fillGrid();
    bme_scan.classifyPixels();
    return 0;
}