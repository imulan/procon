vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss,buffer,sep ) ) v.pb(buffer);
    return v;
}
