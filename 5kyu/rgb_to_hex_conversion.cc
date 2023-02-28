// https://www.codewars.com/kata/513e08acc600c94f01000001

// The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

// Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

// The following are examples of expected output values:

// rgb(255, 255, 255) # returns FFFFFF
// rgb(255, 255, 300) # returns FFFFFF
// rgb(0,0,0) # returns 000000
// rgb(148, 0, 211) # returns 9400D3

class RGBToHex {
public:
    static std::string rgb(int red, int green, int blue);
private:
    std::string intToHex(int dec);
    int clipHexRange(int num) {
        return (num < 0) ? 0 : ((num > 255) ? 255 : num);
    }
    char digitToHex(int num) {
        if (num < 0 || num > 15) {
            return ' ';
        }
        if (num < 10) {
            return '0' + num;
        }
        return 'A' + (num - 10);
    }
};

std::string RGBToHex::rgb(int red, int green, int blue) {
    RGBToHex converter;
    std::string r = converter.intToHex(converter.clipHexRange(red));
    std::string g = converter.intToHex(converter.clipHexRange(green));
    std::string b = converter.intToHex(converter.clipHexRange(blue));
  
    if (r.size() == 1) {
        r = "0" + r;
    }
    if (g.size() == 1) {
        g = "0" + g;
    }
    if (b.size() == 1) {
        b = "0" + b;
    }
  
    return r + g + b;
}

std::string RGBToHex::intToHex(int dec) {
    std::string output = "";
    do {
        int digit = dec % 16;
        output = digitToHex(digit) + output;
        dec /= 16;
    } while (dec > 0);

    if (output.empty()) {
        output = "0";
    }
    return output;
}