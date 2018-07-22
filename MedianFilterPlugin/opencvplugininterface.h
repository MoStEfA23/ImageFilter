#ifndef OPENCVPLUGININTERFACE_H
#define OPENCVPLUGININTERFACE_H

#include <QObject>
#include <QString>
#include "opencv2/opencv.hpp"

class OpenCVPluginInterface{
public:
    OpenCVPluginInterface();
    ~OpenCVPluginInterface();
    QString description();
    virtual void processImage(const cv::Mat &inputImage, cv::Mat &outputImage) = 0;
};

#define OPENCVPLUGININTERFACE_IID "com.mostefa.opencvplugininterface"
Q_DECLARE_INTERFACE(OpenCVPluginInterface, OPENCVPLUGININTERFACE_IID)


#endif // OPENCVPLUGININTERFACE_H
