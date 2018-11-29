//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_53_H
#define CPP_PRIMER_EX_7_53_H

class Debug {
public:
    constexpr explicit Debug(bool b = true) : hw_{b}, io_{b}, other_{b} {}
    constexpr Debug(bool hw, bool io, bool other) : hw_{hw}, io_{io}, other_{other} {}
    constexpr bool any() const { return hw_ || io_ || other_; }
    void SetHw(bool hw) {
        hw_ = hw;
    }
    void SetIo(bool io) {
        io_ = io;
    }
    void SetOther(bool other) {
        other_ = other;
    }
private:
    bool hw_;
    bool io_;
    bool other_;
};

#endif //CPP_PRIMER_EX_7_53_H
