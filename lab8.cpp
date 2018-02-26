#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
using namespace std;

void dfs()
{
	DIR* dp = opendir(".");
	struct dirent *res;

	while ((res = readdir(dp)) != NULL) {
        if(strcmp(res->d_name,"."==0) || strcmp(res->d_name,"..")==0) continue ;
        struct stat info;
    	stat(res->d_name, &info);
    	if (S_ISDIR(info.st_mode)){
            cout << "DIR";
            fcount++;
    	}else{
    	size +=info.st.size;
    	count++;
    	}
	}
    closedir(dp);

}

int main()
{
    dfs();
    cout <<count << "files, "<< fcount << "dirs, " << size << "bytes.\n";
    return 0;
}
