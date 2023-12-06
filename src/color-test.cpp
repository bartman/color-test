#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <cstring>
#include <cassert>

struct Color {
    static const constexpr char *g_reset = "\x1b[0m";
    static const constexpr char *g_rgb_bg = "\x1b[48;2;%hhu;%hhu;%hhum";
    static const constexpr size_t g_rgb_size = 20;
    char m_str[g_rgb_size];

    Color()
    {
        std::strcpy(m_str, g_reset);
    }
    Color(int8_t r, int8_t g, int8_t b)
    {
        int rc = std::snprintf(m_str, g_rgb_size, g_rgb_bg, r, g, b);
        assert(rc>0 && rc<g_rgb_size);
    }
    ~Color() = default;

    const std::string str() const { return m_str; }
    const char * c_str() const { return m_str; }
};


int main(int argc, char *argv[])
{
    Color rst;

    for (int y=0; y<64; y++) {
        std::stringstream ss;

        int yg = y/16;
        int yi = y%16;

        for (int x=0; x<64; x++) {

            int xg = x/16;
            int xi = x%16;

            int r = xi*16;
            int g = yi*16;
            int b = (yg*16) + (xg*16)<<3;

            Color col(r,g,b);
            ss << col.c_str() << "  ";
        }
        std::cout << ss.str() << rst.c_str() << std::endl;
    }
}


