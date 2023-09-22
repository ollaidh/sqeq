#include <iostream>

class Eq {
public:
    Eq() = default;
    virtual ~Eq() = default;
    virtual void solve() = 0;
};


class LinEq : public Eq {
public:
    void solve();
};

class QuadEq : public Eq {
public:
    void solve();
};

class CubEq : public Eq {
public:
    void solve();
};

