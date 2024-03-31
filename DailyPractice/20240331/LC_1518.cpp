/*https://www.geeksforgeeks.org/program-chocolate-wrapper-puzzle/*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};