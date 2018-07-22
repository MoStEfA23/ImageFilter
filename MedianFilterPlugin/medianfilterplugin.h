#ifndef MEDIANFILTERPLUGIN_H
#define MEDIANFILTERPLUGIN_H

#include "medianfilterplugin_global.h"
#include "opencv2/opencv.hpp"

#include <QObject>

class MEDIANFILTERPLUGINSHARED_EXPORT MedianFilterPlugin :
    public QObject
{
    Q_OBJECT
public:
    MedianFilterPlugin();
    ~MedianFilterPlugin();
    QString description();
    void processImage(const cv::Mat & imageInput, cv::Mat &imageOuput);
};

#endif // MEDIANFILTERPLUGIN_H
