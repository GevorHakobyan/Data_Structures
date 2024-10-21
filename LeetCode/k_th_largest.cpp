class KthLargest {
public:
    using Data = std::vector<int>;

    KthLargest(int k, Data& nums) : m_index{k} {
        for (const auto elem : nums) {
            m_data.push_back(elem);
        }

        std::sort(m_data.begin(), m_data.end());
    }

    int add(int val) {
        auto it = std::lower_bound(m_data.begin(), m_data.end(), val);
        m_data.insert(it, val);
        int newIndex = m_data.size() - m_index;
        return m_data[newIndex];
    }

private:
    Data m_data{};
    int m_index;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */