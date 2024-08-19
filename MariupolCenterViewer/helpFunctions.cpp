#include "helpFunctions.h"

QList<QString> split(const std::string& str, char delimiter) {
    QList<QString> result;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        result.push_back(QString::fromStdString(token));
    }

    return result;
}
