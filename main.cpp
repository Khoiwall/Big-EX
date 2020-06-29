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

	for (int i = 0; i < (int)data.length(); i++){
        if ('A' <= data[i] && data[i] <= 'Z'){
            data[i] = (char)((int)data[i] + 32);
        }
    }

    return data;
}

vector<string> EnumerateFolders (const char* nameFile)
{
    vector<string> file;

    WIN32_FIND_DATA fd;
    char folder[MAX_PATH];
    sprintf(folder, "%s\\*.*", nameFile);

    HANDLE hFind = FindFirstFile (folder, &fd);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (strcmp(fd.cFileName, ".") && strcmp(fd.cFileName, ".."))
                {
                    printf ("%s\\%s\n", nameFile, fd.cFileName);
                    char child[MAX_PATH];

                    sprintf(child, "%s\\%s", nameFile, fd.cFileName);
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
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer1(fileName[i], fileName[j], a, b, c);
        }
    }
}

void compareGramer2(vector<int> &a, vector<string> &b, int &c){
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer2(fileName[i], fileName[j], a, b, c);
        }
    }
}

void compareGramer3(vector<int> &a, vector<string> &b, int &c){
    vector<string> fileName = EnumerateFolders("C:/baitap/sm_doc_set");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer3(fileName[i], fileName[j], a, b, c);
        }
    }
}

void CompareVector(string a, int b){
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
    else if (a == "1-2"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        compareGramer1(_tmpCount, _tmpFile, _countss);
        compareGramer2(_tmpCounts, _tmpFiles, _countsss);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] += _tmpCounts[i];
        }
    }
    else if (a == "2-3"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        compareGramer2(_tmpCount, _tmpFile, _countss);
        compareGramer3(_tmpCounts, _tmpFiles, _countsss);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] += _tmpCounts[i];
        }
    }
    else if (a == "1-3"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        vector<int> _tmpCountss;
        vector<string> _tmpFiless;
        int _countssss = 0;

        compareGramer1(_tmpCount, _tmpFile, _countss);
        compareGramer2(_tmpCounts, _tmpFiles, _countsss);
        compareGramer3(_tmpCountss, _tmpFiless, _countssss);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] = _tmpCount[i] + _tmpCounts[i] + _tmpCountss[i];
        }
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

// map

map<string,int> cutWordMap(string data, int &counts){
    map<string,int> mapa;
    map<string,int>::iterator it;
    vector<string> _tmp;

    char *s = const_cast<char *> (data.c_str());
    char * pch;
    pch = strtok(s,".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");

    while (pch != NULL)
    {
        mapa.insert(pair<string,int> (pch,0));
        _tmp.push_back(pch);
        counts++;
        pch = strtok(NULL, ".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    }

    for (int i = 0; i < counts; i++){
        mapa[_tmp[i]]++;
    }

    return mapa;
}

void _CompareGamerMap1(string a, string b, vector<int> &c, vector<string> &d){
    int _counts = 0;
    int __counts = 0;

    map<string,int> Arr = cutWordMap(_readk(a),_counts);
    vector<string> Brr = cutWord(_readk(b),__counts);

    int ___counts = 0;

    for (int i = 0; i < __counts; i++){
        if (Arr[Brr[i]] != 0){
            Arr[Brr[i]]--;
            ___counts++;
        }
    }
    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void _CompareGamerMap2(string a, string b, vector<int> &c, vector<string> &d){

    int _counts = 0;
    int __counts = 0;
    vector<string> Brr = cutWord(_readk(b), __counts);
    vector<string> brr;
    vector<string> arr = cutWord(_readk(a),_counts);
    map<string,int> Arr;

    vector<string> tmp;
    string _tmp;
    for (int i = 1; i < _counts; i++){
        tmp.push_back(arr[i-1] + " " + arr[i]);
        _tmp = tmp[i-1];
        Arr[_tmp]++;
    }

    for (int i = 1; i < __counts; i++){
        brr.push_back(Brr[i-1] + " " + Brr[i]);
    }

    int ___counts = 0;

    for (int i = 0; i < (int)brr.size(); i++){
        if (Arr[brr[i]] != 0){
            Arr[brr[i]]--;
            ___counts++;
        }
    }

    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void _CompareGamerMap3(string a, string b, vector<int> &c, vector<string> &d){

    int _counts = 0;
    int __counts = 0;
    vector<string> Brr = cutWord(_readk(b), __counts);
    vector<string> brr;
    vector<string> arr = cutWord(_readk(a),_counts);
    map<string,int> Arr;

    vector<string> tmp;
    string _tmp;
    for (int i = 2; i < (int)arr.size(); i++){
        tmp.push_back(arr[i-2] + " " + arr[i-1] + " " + arr[i]);
        _tmp = tmp[i-2];
        Arr[_tmp]++;
    }

    for (int i = 2; i < __counts; i++){
        brr.push_back(Brr[i-2] + " " + Brr[i-1] + " " + Brr[i]);
    }

    int ___counts = 0;

    for (int i = 0; i < (int)brr.size(); i++){
        if (Arr[brr[i]] != 0){
            Arr[brr[i]]--;
            ___counts++;
        }
    }

    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void compareGramerMap1(vector<int> &Arr, vector<string> &Brr){
    vector<string> fileName = EnumerateFolders("C:/baitap1/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap1(fileName[i], fileName[j], Arr, Brr);
        }
    }
}

void compareGramerMap2(vector<int> &Arr, vector<string> &Brr){
    vector<string> fileName = EnumerateFolders("C:/baitap1/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap2(fileName[i], fileName[j], Arr, Brr);
        }
    }
}

void compareGramerMap3(vector<int> &Arr, vector<string> &Brr){
    vector<string> fileName = EnumerateFolders("C:/baitap1/sm_doc_set/");

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap3(fileName[i], fileName[j], Arr, Brr);
        }
    }
}

void CompareMap(string a, int b){
    vector<int> Arr;
    vector<string> Brr;

    int tmp;
    string _tmp;

    if (a == "1"){
        compareGramerMap1(Arr, Brr);
    }
    else if (a == "2"){
        compareGramerMap2(Arr, Brr);
    }
    else if (a == "3"){
        compareGramerMap3(Arr, Brr);
    }
    else if (a == "1-2"){
        vector<int> _Arr;
        vector<string> _Brr;
        compareGramerMap1(Arr, Brr);
        compareGramerMap2(_Arr, _Brr);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i];
        }
    }
    else if( a == "2-3"){
        vector<int> _Arr;
        vector<string> _Brr;
        compareGramerMap2(Arr, Brr);
        compareGramerMap3(_Arr, _Brr);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i];
        }
    }
    else{
        vector<int> _Arr;
        vector<string> _Brr;
        vector<int> __Arr;
        vector<string> __Brr;
        compareGramerMap2(Arr, Brr);
        compareGramerMap2(_Arr, _Brr);
        compareGramerMap3(__Arr, __Brr);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i] + __Arr[i];
        }
    }
    for (int i = 0; i < 300; i++){
        for (int j = i; j < 300; j++){
            if(Arr[i] < Arr[j]){
                tmp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = tmp;

                _tmp = Brr[i];
                Brr[i] = Brr[j];
                Brr[j] = _tmp;
            }
        }
    }

    if (b == -1){
        for (int i = 0; i < 300; i++){
            cout << Brr[i] << " " << Arr[i] << endl;
        }
    }
    else{
        for (int i = 0; i < b; i++){
            cout << Brr[i] << " " << Arr[i] << endl;
        }
    }
}

void swapCompare(string nameCompare, string grams, int numberPrint){
    if (nameCompare == "vector"){
        CompareVector(grams, numberPrint);
    }
    else if (nameCompare == "map"){
        CompareMap(grams, numberPrint);
    }
}

int main()
{
    string nameCompare;
    cin >> nameCompare;

    string grams;
    cin >> grams;

    int numberPrint;
    cin >> numberPrint;
    //EnumerateFolders("C:/baitap/sm_doc_set/");
    swapCompare(nameCompare, grams, numberPrint);
    return 0;
}
