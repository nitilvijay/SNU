#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum number of blocks in tower 1
long long solve(int n, vector<long long>& blocks) {
    // Initially, blocks[0] represents the number of blocks in tower 1
    long long max_blocks_in_tower1 = blocks[0];
    
    // Create a vector of pairs (tower_index, number_of_blocks)
    vector<pair<int, long long>> tower_blocks;
    for (int i = 0; i < n; i++) {
        tower_blocks.push_back({i + 1, blocks[i]});
    }
    
    // Sort towers by number of blocks in descending order
    sort(tower_blocks.begin(), tower_blocks.end(), 
         [](const pair<int, long long>& a, const pair<int, long long>& b) {
             return a.second > b.second;
         });
    
    // For each tower with more blocks than tower 1, we can move blocks to tower 1
    for (int i = 0; i < n; i++) {
        // Skip if this is tower 1
        if (tower_blocks[i].first == 1) {
            continue;
        }
        
        // Find tower 1's current position in our sorted array
        int tower1_index = -1;
        for (int j = 0; j < n; j++) {
            if (tower_blocks[j].first == 1) {
                tower1_index = j;
                break;
            }
        }
        
        // If we can't find tower 1 or tower 1 has more blocks than current tower, skip
        if (tower1_index == -1 || tower_blocks[tower1_index].second >= tower_blocks[i].second) {
            continue;
        }
        
        // We can move a block from this tower to tower 1
        // Each move increases tower 1's blocks by 1 and decreases the other tower by 1
        // We can keep doing this until they have the same number of blocks
        // After that, they'll keep swapping positions and we can't increase tower 1 further
        
        long long diff = tower_blocks[i].second - tower_blocks[tower1_index].second;
        // Integer division by 2 gives us how many blocks tower 1 gains
        long long blocks_to_move = diff / 2;
        
        // Update tower 1's blocks
        tower_blocks[tower1_index].second += blocks_to_move;
        
        // Update max if necessary
        max_blocks_in_tower1 = max(max_blocks_in_tower1, tower_blocks[tower1_index].second);
    }
    
    return max_blocks_in_tower1;
}

// Optimized solution
long long solveOptimized(int n, vector<long long>& blocks) {
    long long tower1_blocks = blocks[0];
    
    // For each tower, find how many blocks we can add to tower 1
    for (int i = 1; i < n; i++) {
        // If current tower has more blocks than tower 1
        if (blocks[i] > tower1_blocks) {
            // Calculate how many blocks we can move
            long long diff = blocks[i] - tower1_blocks;
            // We can add diff/2 blocks to tower 1
            tower1_blocks += diff / 2;
        }
    }
    
    return tower1_blocks;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Number of towers
        
        vector<long long> blocks(n);
        for (int i = 0; i < n; i++) {
            cin >> blocks[i];  // Number of blocks in each tower
        }
        
        // Calculate and output the result
        cout << solveOptimized(n, blocks) << endl;
    }
    
    return 0;
}