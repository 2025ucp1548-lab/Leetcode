class Solution {
private:
    void mergeAndCount(std::vector<std::pair<int, int>>& itemIndices, int left, int mid, int right, std::vector<int>& count) {
        std::vector<std::pair<int, int>> temp(right - left + 1);
        int i = left;      
        int j = mid + 1;  
        int k = 0;        
        int rightCount = 0; 

        while (i <= mid && j <= right) {
            if (itemIndices[j].first < itemIndices[i].first) {
                rightCount++;
                temp[k++] = itemIndices[j++];
            } else {
                count[itemIndices[i].second] += rightCount;
                temp[k++] = itemIndices[i++];
            }
        }

        while (i <= mid) {
            count[itemIndices[i].second] += rightCount;
            temp[k++] = itemIndices[i++];
        }

        while (j <= right) {
            temp[k++] = itemIndices[j++];
        }

        for (int p = 0; p < temp.size(); ++p) {
            itemIndices[left + p] = temp[p];
        }
    }

    void mergeSort(std::vector<std::pair<int, int>>& itemIndices, int left, int right, std::vector<int>& count) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(itemIndices, left, mid, count);
        mergeSort(itemIndices, mid + 1, right, count);
        mergeAndCount(itemIndices, left, mid, right, count);
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> count(n, 0);
        
        std::vector<std::pair<int, int>> itemIndices(n);
        for (int i = 0; i < n; ++i) {
            itemIndices[i] = {nums[i], i};
        }

        mergeSort(itemIndices, 0, n - 1, count);
        return count;
    }
};