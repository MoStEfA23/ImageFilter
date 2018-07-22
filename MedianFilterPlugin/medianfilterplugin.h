#ifndef MEDIANFILTERPLUGIN_H
#define MEDIANFILTERPLUGIN_H

#include "medianfilterplugin_global.h"
#include "opencvplugininterface.h"

class MEDIANFILTERPLUGINSHARED_EXPORT MedianFilterPlugin :
    public QObject, public OpenCVPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.mostefa.opencvplugininterface")
    Q_INTERFACES(OpenCVPluginInterface)
public:
    MedianFilterPlugin();
    ~MedianFilterPlugin();
    QString description();
    void processImage(const cv::Mat & imageInput, cv::Mat &imageOuput);
};

#endif // MEDIANFILTERPLUGIN_H
