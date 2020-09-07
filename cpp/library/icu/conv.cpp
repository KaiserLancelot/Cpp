#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

#include <unicode/ucnv.h>
#include <unicode/unistr.h>
#include <unicode/utypes.h>

void check_and_throw_icu_error(UErrorCode err)
{
    if (U_FAILURE(err)) {
        throw std::runtime_error{u_errorName(err)};
    }
}

class Conv {
public:
    explicit Conv(const std::string& charset)
    {
        UErrorCode err{U_ZERO_ERROR};
        cvt_ = ucnv_open(charset.c_str(), &err);
        if (!cvt_ || U_FAILURE(err)) {
            if (cvt_) {
                ucnv_close(cvt_);
            }
            throw std::runtime_error{"Invalid or unsupported charset:" + charset};
        }

        try {
            ucnv_setFromUCallBack(cvt_, UCNV_FROM_U_CALLBACK_STOP, nullptr, nullptr,
                                  nullptr, &err);
            check_and_throw_icu_error(err);

            err = U_ZERO_ERROR;
            ucnv_setToUCallBack(cvt_, UCNV_TO_U_CALLBACK_STOP, nullptr, nullptr,
                                nullptr, &err);
            check_and_throw_icu_error(err);
        }
        catch (...) {
            ucnv_close(cvt_);
            throw;
        }
    }

    ~Conv() { ucnv_close(cvt_); }

    UConverter* cvt() { return cvt_; }

    std::string go(const UChar* buf, std::size_t length, std::size_t max_size)
    {
        std::string res;
        res.resize(UCNV_GET_MAX_BYTES_FOR_STRING(length, max_size));

        auto ptr{reinterpret_cast<char*>(res.data())};
        UErrorCode err{U_ZERO_ERROR};
        auto n{ucnv_fromUChars(cvt_, ptr, std::size(res), buf, length, &err)};
        check_and_throw_icu_error(err);
        res.resize(n);

        return res;
    }

    std::size_t max_char_size() const { return ucnv_getMaxCharSize(cvt_); }

private:
    UConverter* cvt_;
};

std::string between(const std::string& str, const std::string& from_encoding,
                    const std::string& to_encoding)
{
    UErrorCode err{U_ZERO_ERROR};
    Conv from_conv{from_encoding};
    icu::UnicodeString temp(str.c_str(), std::size(str), from_conv.cvt(), err);
    check_and_throw_icu_error(err);

    Conv to_conv{to_encoding};
    return to_conv.go(temp.getBuffer(), temp.length(), to_conv.max_char_size());
}

int main()
{
    std::string utf8{"你好世界"};
    auto utf16{between(utf8, "UTF-8", "UTF-16LE")};

    std::cout << std::size(utf16) << '\n';
}
