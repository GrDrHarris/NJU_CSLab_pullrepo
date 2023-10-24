#include<cstdio>
#include<string>
using std::string;
//remember to modify your name and year!
const string UserName = "GrDrHarris";
const string Year = "2023autumn";

const string __ = "-" + Year + "-"+ UserName;
const string path_prefix = "lab";
const string path_suffix = __ + "/sponge/";
const string git_prefix = "git clone git@github.com:NJU-CN-course-427lab/lab";
const string git_suffix = __ + ".git";
const string files[] = {
    "apps/webget.cc", "$lab1",
    "libsponge/byte_stream.cc", "libsponge/byte_stream.hh", "libsponge/stream_reassembler.cc", 
    "libsponge/stream_reassembler.hh", "$lab2",
    "libsponge/wrapping_integers.cc", "libsponge/wrapping_integers.hh", 
    "libsponge/tcp_receiver.cc", "libsponge/tcp_receiver.hh", "$lab3",
    "libsponge/tcp_sender.cc", "libsponge/tcp_sender.hh", "$lab4"
};
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: pullrepo number\n");
        return -1;
    }
    int lab_now;
    sscanf(*(argv + 1), "%d", &lab_now);
    printf("going to pull lab%d\nPress any key to continue.\n", lab_now);
    system("read var");
    string git_cmd = git_prefix + std::to_string(lab_now) + git_suffix;
    system(git_cmd.c_str()); 
    if(lab_now == 0)
        return 0;
    string now_path = path_prefix + std::to_string(lab_now) + path_suffix;
    string last_path = path_prefix + std::to_string(lab_now-1) + path_suffix;
    int i = 0, cnt = 0;
    while(1)
    {
        if(files[i][0] == '$')
        {
            cnt++;
            if(cnt == lab_now)
                break;
        }else{
            string cp_cmd = "cp " + last_path + files[i] + " " + now_path + files[i];
            printf("%s copied\n", files[i].c_str());
            system(cp_cmd.c_str());
        }
        i++;
    } 
    return 0;
}