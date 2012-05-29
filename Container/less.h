#ifndef LESS_H
#define LESS_H

template <typename T> class Less {
public:
    bool operator()(const T& lhs, const T& rhs) {
        return lhs < rhs;
    }
};


#endif // LESS_H
