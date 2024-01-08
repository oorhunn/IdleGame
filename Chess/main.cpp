#include <iostream>

void drawChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                std::cout << "██";  // Unicode block character for a filled square
            } else {
                std::cout << "  ";  // Empty square
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Unicode chess pieces: ♔ ♕ ♖ ♗ ♘ ♙ ♚ ♛ ♜ ♝ ♞ ♟
    std::cout << "Unicode chess pieces: \u2654 \u2655 \u2656 \u2657 \u2658 \u2659 \u265A \u265B \u265C \u265D \u265E \u265F" << std::endl;

	drawChessBoard();

    return 0;
}
