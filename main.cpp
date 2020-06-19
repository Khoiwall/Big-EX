#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

vector<string> cutWord(string data, int &counts){

    vector<string> arr;
    char *s = const_cast<char *> (data.c_str());
    char * pch;
    pch = strtok (s,".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    while (pch != NULL)
    {
        arr.push_back(pch);
        counts++;
        pch = strtok(NULL, ".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    }

    return arr;
}

vector<string> cutWordGramer2(string data, int &c){
    int tmpInt = 0;
    vector<string> tmp = cutWord(data, tmpInt);

    vector<string> arr;

    string _tmp;
    for(int i = 1; i < tmpInt; i++){
        _tmp += tmp[i-1] + " " + tmp[i];
        arr.push_back(_tmp);
        _tmp = "";
        c++;
    }

    return arr;
}

vector<string> cutWordGramer3(string data, int &c){
    int tmpInt = 0;
    vector<string> tmp = cutWord(data, tmpInt);

    vector<string> arr;

    string _tmp;
    for(int i = 2; i < tmpInt; i++){
        _tmp += tmp[i-2] + " " + tmp[i-1] + " " + tmp[i] ;
        arr.push_back(_tmp);
        _tmp = "";
        c++;
    }

    return arr;
}

string _readk(string name){
    fstream f;
    string str = "C:/baitap/sm_doc_set/";
	f.open(str+name, ios::in);

	string data;

	string line;
	while (!f.eof())
	{
		getline(f, line);
		data += line;
	}

	f.close();

	for (int i = 0; i < data.length(); i++){
        if ('A' <= data[i] && data[i] <= 'Z'){
            data[i] = (char)((int)data[i] + 32);
        }
    }

    return data;
}

vector<string> EnumerateFolders (const char* parent)
{
    vector<string> file;

    WIN32_FIND_DATA fd;
    char folder[MAX_PATH];
    sprintf(folder, "%s\\*.*", parent);

    HANDLE hFind = FindFirstFile (folder, &fd);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (strcmp(fd.cFileName, ".") && strcmp(fd.cFileName, ".."))
                {
                    printf ("%s\\%s\n", parent, fd.cFileName);
                    char child[MAX_PATH];

                    sprintf(child, "%s\\%s", parent, fd.cFileName);
                    EnumerateFolders (child);
                }
            }
            else
            {
                //printf("%s\n", fd.cFileName);
                file.push_back(fd.cFileName);
            }
        } while (FindNextFile (hFind, &fd));
        FindClose (hFind);
    }

    return file;
}

vector<bool> Denomination(int b){
    vector<bool> arr;
    for(int i = 0; i < b; i++){
        arr.push_back(true);
    }

    return arr;
}
void _CompareGamer1(string a, string b, vector<int> &c, vector<string> &d, int &v){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWord(_readk(a), _counts);
    vector<string> Brr = cutWord(_readk(b), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void _CompareGamer2(string a, string b, vector<int> &c, vector<string> &d, int &v){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWordGramer2(_readk(a), _counts);
    vector<string> Brr = cutWordGramer2(_readk(b), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void _CompareGamer3(string a, string b, vector<int> &c, vector<string> &d, int &v){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWordGramer3(_readk(a), _counts);
    vector<string> Brr = cutWordGramer3(_readk(b), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void compareGramer1(vector<int> &a, vector<string> &b, int &c){
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer1(fileName[i], fileName[j], a, b, c);
        }
    }
}

void compareGramer2(vector<int> &a, vector<string> &b, int &c){
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer2(fileName[i], fileName[j], a, b, c);
        }
    }
}

void compareGramer3(vector<int> &a, vector<string> &b, int &c){
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer3(fileName[i], fileName[j], a, b, c);
        }
    }
}

void swapGramer(string a, int b){
    vector<int> _tmpCount;
    vector<string> _tmpFile;

    int _countss = 0;
    if (a == "1"){
        compareGramer1(_tmpCount, _tmpFile, _countss);
    }
    else if(a == "2"){
        compareGramer2(_tmpCount, _tmpFile, _countss);
    }
    else if(a == "3"){
        compareGramer3(_tmpCount, _tmpFile, _countss);
    }

    string tmpString;
    int tmpInt;

    for (int i = 0; i < _countss; i++){
        for (int j = i; j < _countss; j++){
            if (_tmpCount[i] < _tmpCount[j]){
                tmpInt = _tmpCount[i];
                _tmpCount[i] = _tmpCount[j];
                _tmpCount[j] = tmpInt;

                tmpString = _tmpFile[i];
                _tmpFile[i] = _tmpFile[j];
                _tmpFile[j] = tmpString;
            }
        }
    }

    if (b == -1){
        for (int i = 0; i < _countss; i++){
            cout << _tmpFile[i] << " " << _tmpCount[i] << endl;
        }
    }
    else{
        for (int i = 0; i < b; i++){
            cout << _tmpFile[i] << " " << _tmpCount[i] << endl;
        }
    }
}


int main()
{
    string a;
    cin >> a;
    int b;
    cin >> b;
    //EnumerateFolders("C:/baitap/sm_doc_set/");
    swapGramer(a, b);
    return 0;
}
