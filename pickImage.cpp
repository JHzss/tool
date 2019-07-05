#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace std;

void LoadImages(const string &strPathLeft,vector<string> &vstrImageLeft,const string &strPathTimes)
{
    ifstream fTimes;
    fTimes.open(strPathTimes.c_str());
    while(!fTimes.eof())
    {
        string s;
        getline(fTimes,s);
        if(!s.empty())
        {
            stringstream ss;
            ss << s;
            vstrImageLeft.push_back(ss.str());
        }
    }
}

void filterImage(const vector<string >& images_name,vector<string >& images_name_after,const string& filter_file)
{
    ifstream fTimes;
    fTimes.open(filter_file.c_str());
    while(!fTimes.eof())
    {
        string s;
        getline(fTimes,s);
        if(!s.empty())
        {
            int k = stoi(s);
            images_name_after.push_back(images_name[k]);
        }
    }
}

int main(int argc ,char** argv)
{
    vector<string > images_name;
    LoadImages(argv[1],images_name,argv[2]);

    vector<string > images_name_after;

    filterImage(images_name,images_name_after,argv[3]);

    for (int i = 0; i < images_name_after.size(); ++i) {
        string name = images_name_after[i];
        cv::Mat image = cv::imread(string(argv[1]) + "/" + images_name_after[i],CV_LOAD_IMAGE_UNCHANGED);

        cv::imwrite(argv[4]+ name,image);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}