//
// Created by kaiser on 18-11-29.
//

#pragma once

class Debug {
 public:
  constexpr explicit Debug(bool b = true) : hw_{b}, io_{b}, other_{b} {}
  constexpr Debug(bool hw, bool io, bool other)
      : hw_{hw}, io_{io}, other_{other} {}

  constexpr bool any() const { return hw_ || io_ || other_; }
  void set_hw(bool hw) { hw_ = hw; }
  void set_io(bool io) { io_ = io; }
  void set_other(bool other) { other_ = other; }

 private:
  bool hw_;
  bool io_;
  bool other_;
};
