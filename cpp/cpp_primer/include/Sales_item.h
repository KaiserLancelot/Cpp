/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 *     Pearson Education, Inc.
 *     Rights and Permissions Department
 *     One Lake Street
 *     Upper Saddle River, NJ  07458
 *     Fax: (201) 236-3290
 */

/* This file defines the SalesItem class used in chapter 1.
 * The code used in this file will be explained in
 * Chapter 7 (Classes) and Chapter 14 (Overloaded Operators)
 * Readers shouldn't try to understand the code in this file
 * until they have read those chapters.
 */

#ifndef SALESITEM_H
// we're here only if SALESITEM_H has not yet been defined
#define SALESITEM_H

// Definition of SalesItem class and related functions goes here
#include <iostream>
#include <string>

class SalesItem {
    // these declarations are explained section 7.2.1, p. 270
    // and in chapter 14, pages 557, 558, 561
    friend std::istream& operator>>(std::istream&, SalesItem&);
    friend std::ostream& operator<<(std::ostream&, const SalesItem&);
    friend bool operator<(const SalesItem&, const SalesItem&);
    friend bool operator==(const SalesItem&, const SalesItem&);

public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type
    SalesItem() = default;
    SalesItem(const std::string& book) : book_no_(book) {}
    SalesItem(std::istream& is) { is >> *this; }

public:
    // operations on SalesItem objects
    // member binary operator: left-hand operand bound to implicit this pointer
    SalesItem& operator+=(const SalesItem&);

    // operations on SalesItem objects
    std::string isbn() const { return book_no_; }
    double avg_price() const;
    // private members as before
private:
    std::string book_no_;     // implicitly initialized to the empty string
    unsigned units_sold_ = 0; // explicitly initialized
    double revenue_ = 0.0;
};

// used in chapter 10
inline bool compare_isbn(const SalesItem& lhs, const SalesItem& rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// nonmember binary operator: must declare a parameter for each operand
SalesItem operator+(const SalesItem&, const SalesItem&);

inline bool operator==(const SalesItem& lhs, const SalesItem& rhs)
{
    // must be made a friend of SalesItem
    return lhs.units_sold_ == rhs.units_sold_ && lhs.revenue_ == rhs.revenue_ && lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const SalesItem& lhs, const SalesItem& rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
SalesItem& SalesItem::operator+=(const SalesItem& rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
}

// assumes that both objects refer to the same ISBN
SalesItem operator+(const SalesItem& lhs, const SalesItem& rhs)
{
    SalesItem ret(lhs); // copy (|lhs|) into a local object that we'll return
    ret += rhs;         // add in the contents of (|rhs|)
    return ret;         // return (|ret|) by value
}

std::istream& operator>>(std::istream& in, SalesItem& s)
{
    double price;
    in >> s.book_no_ >> s.units_sold_ >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue_ = s.units_sold_ * price;
    else
        s = SalesItem(); // input failed: reset object to default state
    return in;
}

std::ostream& operator<<(std::ostream& out, const SalesItem& s)
{
    out << s.isbn() << " " << s.units_sold_ << " " << s.revenue_ << " "
        << s.avg_price();
    return out;
}

double SalesItem::avg_price() const
{
    if (units_sold_)
        return revenue_ / units_sold_;
    else
        return 0;
}
#endif
