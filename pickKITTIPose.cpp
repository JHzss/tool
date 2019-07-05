#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 把KITTI数据集的groundtruth中的按照input_index的索引提取出来，以便进行KITTI数据集上轨迹的评估
 * @param input_file
 * @param input_index
 * @param output_file
 */
void getPose(const string& input_file,const string& input_index,const string& output_file)
{

    ifstream ifinput_file,ifinput_index;
    ofstream ofoutput_file;
    ifinput_file.open(input_file.c_str());
    ifinput_index.open(input_index.c_str());
    ofoutput_file.open(output_file);

    vector<string> poses;
    while(!ifinput_file.eof())
    {
        string s;
        getline(ifinput_file,s);
        if(!s.empty())
        {
            stringstream ss;
            ss << s;
            poses.push_back(ss.str());
        }
    }
    while(!ifinput_index.eof())
    {
        string s;
        getline(ifinput_index,s);
        if(!s.empty())
        {
            ofoutput_file << poses[stoi(s)]<<endl;
        }
    }

    ifinput_file.close();
    ifinput_index.close();
    ofoutput_file.close();
}

int main(int argc ,char** argv)
{

    getPose(argv[1],argv[2],argv[3]);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}