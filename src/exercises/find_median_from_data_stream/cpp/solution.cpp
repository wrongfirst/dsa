#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> small; // Max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        if (!large.empty() && num > large.top()) {
            large.push(num);
        } else {
            small.push(num);
        }

        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        } else if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return static_cast<double>(small.top());
        } else if (large.size() > small.size()) {
            return static_cast<double>(large.top());
        }
        return (static_cast<double>(small.top()) + static_cast<double>(large.top())) / 2.0;
    }
};
