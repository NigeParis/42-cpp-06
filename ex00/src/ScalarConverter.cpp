/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:20:18 by nrobinso          #+#    #+#             */
/*   Updated: 2025/03/14 10:56:32 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ScalarConverter.hpp"

static std::string removeFirstChar(const std::string &str);
static void allImpossiblePrintOut(void);
static bool isSingleDigit(const std::string &str);
static bool isNumber(const char c);
static bool isForFloat(const std::string &str);
static bool isFloat(const std::string &str);
static bool isChar(const std::string &str);
static bool isInt(const std::string &str);
static bool isRangeAscii(const int nbr);
static bool isPrintable(const char c);
static bool chkPseudoLiterals(const std::string& str);
static bool chkIsInt(const std::string& str);
static bool chkIsChar(const std::string& str);
static bool chkIsFloat(const std::string &str);
static bool chkIsDouble(const std::string& str);
static bool checkStrFormat(const std::string &str);
static double strtol(const std::string& str);
static void strToFloat(const std::string& str);
static void strToDouble(const std::string& str);
static void charToFloat(const std::string& str);
static void charToDouble(const std::string& str);

static std::string removeFirstChar(const std::string &str) {

    if(str.empty())
        return("");
    return(str.substr(1));
};

static bool checkForZeros(const std::string &str) {
    
    int flagDash = 0;
    for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    
        if(*it == '-') {
            flagDash++;
            continue;
        }
        if(*it == '.')
            break;
        if(*it != '0')
            return(false);
    }
    if(flagDash > 1)
        return(false);
    return (true);
}

static bool isSingleDigit(const std::string &str) {
    if((str.size() == 1) && (str[0] < '0' || str[0] > '9'))
        return(false);
    return(true);
}

static bool isNumber(const char c) {
    if(c >= '0' && c <= '9')
        return(true);
    return(false);
}

static bool isForFloat(const std::string &str) {

    int flagDot = 0;
    int end = str.size() - 1;
    
    for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if(str[end] != 'f')  
            return(false);
        if(*it == '.') {
            flagDot++;
            continue;
        }
        if((*it == 'f') && (it != str.end() - 1)) {
            return(false);
        }
    }
    if(flagDot > 1)
        return(false);
    return(true);
};

static bool chkPseudoLiterals(const std::string& str) {

    if ((str.compare("+inff") == 0) || (str.compare("-inff") == 0) || (str.compare("nanf") == 0)
        ||(str.compare("+inf") == 0) || (str.compare("-inf") == 0) || (str.compare("nan") == 0) ) {
        return (true);
    }
    return(false);
};

static bool chkIsInt(const std::string& str) {

    int flagDash = 0;
    for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {

        if(*it == '-') {
            flagDash++;
            continue;
        }
        if(!isNumber(*it))
            return(false);
        }
    if(flagDash > 1)
        return(false);
    if((flagDash == 1) && (str[0] != '-'))
        return (false);
    return (true);
};

static bool chkIsChar(const std::string& str) {

    if (str.size() != 1)
        return (false);
    return (true);
};

static bool chkIsFloat(const std::string &str) {

    int flagDash = 0;

    if(str.size() > 1) {
        if (!isForFloat(str))
            return(false);
        for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {

            if(*it == '-') {
                flagDash++;
                continue;
            }
            if(*it == '.') {
                continue;
            }
            if(!isNumber(*it) && it != str.end() - 1)
                return(false);
        }
        if(flagDash > 1)
            return(false);
        return(true);
    }
    return(false);
};

static bool chkIsDouble(const std::string& str) {

    int flagDash = 0;
    int flagDot = 0;
    
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {

        if (*it == '-') {
            flagDash++;
            continue;
        }
        if (*it == '.') {
            flagDot++;
            continue;
        }
        if(!isNumber(*it))
            return(false);
        }
    if (flagDash > 1 || flagDot != 1)
        return(false);
    if ((flagDash == 1) && (str[0] != '-'))
        return (false);
    if (str[0] == '.')
        return (false);
    return (true);
};


static bool isPrintable(const char c) {
    
    if (c >= 32 && c < 127)
        return(true);
    return(false);
}

static bool isRangeAscii(const int nbr) {

    if (nbr < 127 || nbr < 0)
        return(true);
    return(false);
}
 

static bool checkStrFormat(const std::string &str) {

    int flagDot = 0;
    int flagF = 0;
    int size = str.size();

    for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {

        if(*it == '.') {
            flagDot++;
            continue;
        }
        if(*it == 'f') {
            flagF++;
            continue;
        }
        if(*it < '0' || *it > '9')
            return(false); 
    }
    
    if(flagF > 1 || flagDot > 1)
        return(false);
    if(flagF && str[size - 1] != 'f')
        return(false);
    return(true);
};


static double strtol(const std::string& str) {

    std::string temp;
    double result = 0;
    int negflag = 1;
    
    if(str.size() == 1) {
        if(isSingleDigit(str))
            return (str[0] - '0');
        else
            return (str[0]);
    }
    if(str[0] == '-') {
        negflag = -1; 
        temp = removeFirstChar(str);
    }
    else
        temp = str;

    if(checkStrFormat(temp)) {
    
        if (temp.size() - 1 == 'f')
            temp.erase(temp.size() - 1);
            
        for(std::string::iterator it = temp.begin(); it != temp.end(); ++it) {

            if (*it == '.' || *it == 'f')
                break;
            result += *it - '0';
            result *= 10;
        };
        result /= 10;
    }
    return((result * negflag));
};

ScalarConverter::ScalarConverter(void) {std::cout << "convert default called" << std::endl;};
ScalarConverter &ScalarConverter::operator=(const std::string) {
    std::cout << "ScalarConverter assignement operator called" << std::endl;
    return *this;
};
ScalarConverter::ScalarConverter(ScalarConverter const &) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
};

ScalarConverter::ScalarConverter(const std::string str) {
    // std::cout << "ScalarConverter constructor called" << std::endl;   
    convert(str);
};

ScalarConverter::~ScalarConverter(void) {
    // std::cout << "ScalarConverter destructor called" << std::endl;
};


static void strToFloat(const std::string& str) {

    if(str.size() > 1) {
    float value;
    char *endptr;
    const char* strptr = str.c_str();
    if (str.compare("+inff") == 0)
        value = std::numeric_limits<float>::infinity();
    else if (str.compare("-inff") == 0)
        value = -std::numeric_limits<float>::infinity();
    else if (str.compare("nanf") == 0)
        value = std::sqrt(-1.0f); // NaN using invalid operation
    else
        value = strtof(strptr, &endptr);
    std::cout << std::fixed << std::setprecision(DECIMALS) << "float: " << value << "f" << std::endl;
    }
}


static void strToDouble(const std::string& str) {

    if(str.size() > 1) {
    char *endptr;
    double value;
    const char* strptr = str.c_str();
    if (str.compare("+inf") == 0)
        value = std::numeric_limits<double>::infinity();
    else if (str.compare("-inf") == 0)
        value = -std::numeric_limits<double>::infinity();
    else if (str.compare("nan") == 0)
        value = 0.0 / 0.0; // NaN using invalid operation
    else
        value = strtod(strptr, &endptr);
    std::cout << std::fixed << std::setprecision(FDECIMALS) << "double: " << value << std::endl;
    }
}


static void charToFloat(const std::string& str) {

    if(str.size() == 1) {

    float charValue = static_cast<float>(strtol(str));
    std::cout << std::fixed << std::setprecision(DECIMALS) << "float: " << charValue << "f" << std::endl;
    }
}


static void charToDouble(const std::string& str) {

    if(str.size() == 1) {

    double charValue = static_cast<double>(strtol(str));
    std::cout << std::fixed << std::setprecision(FDECIMALS) << "Double: " << charValue << std::endl;
    }
}

static void allImpossiblePrintOut(void) {
    
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
};

void ScalarConverter::convert(const std::string &str) {
    
    // std::cout << "function convert called : " << str << std::endl;
    if(str.empty()) {
        allImpossiblePrintOut();
        return ;
    }
    
    if(!chkIsFloat(str) && (!chkIsInt(str)) && (!chkIsChar(str)) && (!chkIsDouble(str)) && !chkPseudoLiterals(str)) { 
        allImpossiblePrintOut();
        return ;
    }

    if (isChar(str)) {
        if(isRangeAscii(strtol(str)))
            std::cout << "char: " << "'" << static_cast<char>(strtol(str)) << "'" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }
    
    if (isInt(str)) {

        if(strtol(str) != static_cast<int>(strtol(str)))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(strtol(str)) << std::endl;
        if (!isFloat(str) && chkIsInt(str))
            strToFloat(str);
        if (!isFloat(str) && chkIsChar(str))
            charToFloat(str);
        if (!chkIsDouble(str) && chkIsInt(str))
            strToDouble(str);
        if (!chkIsDouble(str) && chkIsChar(str))
            charToDouble(str);
    }
       
    if (isFloat(str)) { 
        strToFloat(str);
        strToDouble(str);
    }
    
    if (chkIsDouble(str)) { 
        strToFloat(str);
        strToDouble(str);        
    } 
};

static bool isFloat(const std::string &str) {

    int flagDash = 0;

    if(str.size() > 1) {

        if (chkPseudoLiterals(str)) {
            return (true);
        }
        
        if (!isForFloat(str))
            return(false);
        for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {

            if(*it == '-') {
                flagDash++;
                continue;
            }
            if(*it == '.') {
                continue;
            }
            if(!isNumber(*it) && it != str.end() - 1)
                return(false);
        }
        if(flagDash > 1)
            return(false);
        return(true);
    }
    return(false);
};

static bool isChar(const std::string &str) {

    if(isSingleDigit(str)) {
        char c = static_cast<char>(strtol(str));
        if (isPrintable(c) && (strtol(str) > 31)) {
            return (true);
        } else {
            if (((str.size() != 1 ) && static_cast<char>(strtol(str)) == 0) || (strtol(str) < 0)) {
                if(checkForZeros(str)) {
                    std::cout << "char: non displayable" << std::endl;
                } else
                    std::cout << "char: impossible" << std::endl;
            } else
                std::cout << "char: non displayable" << std::endl;
            return(false);
        }
    }
    if(isInt(str)) {
        char c = static_cast<char>(strtol(str));
        if(isSingleDigit(str))
            c = c - '0';
        
        if (isPrintable(c)) {
            std::cout << "char: " << "'" << c << "'" << std::endl;
        } else 
            std::cout << "char: non displayable" << std::endl;

    } else {

        if (str.size() != 1)
            std::cout << "isInt_char: impossible" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;

    }
    return(false);
};


static bool isInt(const std::string &str) {

    std::string temp;

    temp = str;
    if(str.size() == 1) {
       return (true);
    }
    if(str[0] == '-') {
        temp = removeFirstChar(str);
    }
    if(checkStrFormat(temp)) {
        return(true);
    }
    std::cout << "int: impossible" << std::endl;
    return(false);
};
