#ifndef OPENCVPLUGININTERFACE_H
#define OPENCVPLUGININTERFACE_H

#include <QObject>
#include <QString>
#include "opencv2/opencv.hpp"

class OpenCVPluginInterface{
public:
    virtual ~OpenCVPluginInterface();
    virtual QString description() = 0;
    virtual void processImage(const cv::Mat &inputImage, cv::Mat &outputImage) = 0;
};

#define OPENCVCVPLUGININTERFACE_IID "com.mostefa.opencvplugininterface"
Q_DECLARE_INTERFACE(OpenCVPluginInterface, OpenCVPluginInterfaceIID)


#endif // OPENCVPLUGININTERFACE_H
