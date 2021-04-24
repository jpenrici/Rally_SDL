#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::string;
using std::vector;
using std::stringstream;

class Counter {
public:
    Counter(int num, int min, int max, int value)
    {
        if (value < min) value = min;
        if (value > max) value = max;
        counter.resize(num, value);
        this->min.resize(num, min);
        this->max.resize(num, max);
        vSize = counter.size() - 1;
    };
    ~Counter() {};

    void add() { calc( counter, vSize,  1); }
    void sub() { calc( counter, vSize, -1); }
    bool calc(vector<int>& v, int pos, int value);
    bool setMax(int pos, int newMax);
    bool setMin(int pos, int newMin);
    vector<int> numbers();
    string view();

private:
    int vSize;
    vector<int> counter;
    vector<int> min;
    vector<int> max;
    string int2str(int value);
};

string Counter::int2str(int value)
{
    stringstream strInt;
    strInt << value;
    return strInt.str();
}

bool Counter::setMax(int pos, int newMax)
{
    if (max.empty()) return false;
    if (pos < 0 && pos > vSize) return false;
    if (newMax < min[pos]) return false;
    max[pos] = newMax;
    return true;
}

bool Counter::setMin(int pos, int newMin)
{
    if (min.empty()) return false;
    if (pos < 0 && pos > vSize) return false;
    if (newMin > max[pos]) return false;
    min[pos] = newMin;
    return true;
}

bool Counter::calc(vector<int>& v, int pos, int value)
{
    if (value == 0) return false;
    if (pos < 0 && pos > vSize) return false;
    if (v.empty()) return false;

    v[pos] = v[pos] + value;

    if (v[pos] > max[pos])
    {
        v[pos] = min[pos];
        if (pos > 0) calc(v, pos -1, value);
    }
    else
    {
        if (v[pos] < min[pos])
        {
            v[pos] = max[pos];
            if (pos > 0) calc(v, pos -1, value);
        }
    }
    return true;
}

vector<int> Counter::numbers()
{
    return counter;
}

string Counter::view()
{
    string s = "[ ";
    for (int i = 0; i < vSize; ++i)
        s = s + int2str(counter[i]) + ", ";
    s = s + int2str(counter[vSize]) + " ]";
    return s;
}
