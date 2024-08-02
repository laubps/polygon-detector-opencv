#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/core.hpp>

using namespace std;

class Image
{
public:
    Image(const string &filePath);
    ~Image();

    //Getters
    std::string getFileName() const;
    std::string getFilePath() const;
    const cv::Mat getPixels() const;
    int getWidth() const;
    int getHeight() const;


private:
    string fileName;
    string filePath;
    cv::Mat pixels;
    int width;
    int height;

    void isImageValid(cv::Mat &pixels);
    string calculateFileName ();
};

#endif // IMAGE_H
