#ifndef UTILS_H
#define UTILS_H

#include <QString>

/**
 * @brief The Utils class
 */
class Utils
{
public:
    /**
     * @brief This function adjust path on multiplatform settings
     * @param path
     * @return adjusted path
     */
    static QString adjustPath(const QString & path);
    
private:
    Utils();
};

#endif // UTILS_H