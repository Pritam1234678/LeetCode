class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {  // Edge case: If only one row, return the original string
            return s;
        }

        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();  // Initialize the StringBuilders for each row
        }

        int currentRow = 0;  // Current row in the zigzag
        boolean goingDown = false;  // Direction: false (going up), true (going down)

        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);  // Append the character to the current row

            if (currentRow == 0 || currentRow == numRows - 1) { // Change direction at top/bottom
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;  // Move to the next row based on direction
        }

        // Concatenate all rows to form the final string
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}
