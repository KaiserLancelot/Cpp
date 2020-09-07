//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t a_count{}, e_count{}, i_count{}, o_count{}, u_count{},
            sp_count{}, tab_count{}, new_line_count{}, ff_count{}, fl_count{},
            fi_count{};
    char ch;
    char pre{'\0'};

    while (std::cin >> ch) {
        switch (ch) {
        case 'A':
        case 'a':
            ++a_count;
            break;
        case 'E':
        case 'e':
            ++e_count;
            break;
        case 'i':
            if (pre == 'f') {
                ++fi_count;
            }
            ++i_count;
            break;
        case 'I':
            ++i_count;
            break;
        case 'O':
        case 'o':
            ++o_count;
            break;
        case 'U':
        case 'u':
            ++u_count;
            break;
        case ' ':
            ++sp_count;
            break;
        case '\t':
            ++tab_count;
            break;
        case '\n':
            ++new_line_count;
            break;
        case 'f':
            if (pre == 'f') {
                ++ff_count;
            }
            break;
        case 'l':
            if (pre == 'f') {
                ++fl_count;
            }
            break;
        default: {
        }
        }
        pre = ch;
    }

    std::cout << a_count << ' ' << e_count << ' ' << i_count << ' ' << o_count
              << ' ' << u_count << ' ' << sp_count << ' ' << tab_count << ' '
              << new_line_count << '\n';
}
