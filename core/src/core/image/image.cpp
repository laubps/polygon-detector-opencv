#include "image.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <stdexcept>
#include <filesystem>

using namespace std;

Image::Image(const string &filepath){
    cv::Mat imagePixels = cv::imread(filepath);

    isImageValid(imagePixels);

    this->pixels = imagePixels;
    this->filePath = filepath;
    this->fileName = calculateFileName();
    this->height = this->pixels.rows;
    this->width = this->pixels.cols;
}

Image::~Image(){}

//TODO: Manejar los erroes con excepciones.
void Image::isImageValid(cv::Mat &pixels){
    if(pixels.empty()){
        throw runtime_error("La imagen está vacía.");
        return;
    }
    if(pixels.dims != 2){
        throw runtime_error("La imagen tiene más de dos dimensiones.");
        return;
    }
    if(pixels.rows < 10 ||pixels.cols < 10)
        throw runtime_error("La imagen es muy pequeña.");

    return;
}

string Image::calculateFileName(){
    return std::filesystem::path(filePath).filename().string();
}

//Implementacion de getters
std::string Image::getFileName() const {
    return fileName;
}

std::string Image::getFilePath() const {
    return filePath;
}

const cv::Mat Image::getPixels() const {
    return pixels;
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}
