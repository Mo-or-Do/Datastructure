#include <iostream>
using namespace std;

int InterpolationSearch(int* arr, int first, int last, int target);

// The key stored in the Binary tree is unique.
// The key of root node is bigger than any key of left sub tree.
// The key of root node is smaller than any key of right sub tree.
// Both left sub tree and right sub trees are Binary search trees.