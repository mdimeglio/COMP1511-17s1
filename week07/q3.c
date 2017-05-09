

int is_monochrome(int height, int width, int pixels[height][width]) {
    // return 1 iff image array contains only 1s and 0s, 0 otherwise
    int row = 0;
    while(row < height) {
    	int col = 0;
    	while(col < width) {
    		if (pixels[row][col] != 0 && pixels[row][col] != 1) {
    			return 0;
    		}
    		col++;
    	}

    	row++;
    }
    return 1;
}