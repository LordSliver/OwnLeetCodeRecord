class Solution {
public:
    vector<string> urls;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.push_back(longUrl);
        return "http://tinyurl.com/" + (char)(urls.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string tmp = "http://tinyurl.com/";
        int index;
        stringstream ss;
        ss << (string)(shortUrl.substr(tmp.size() - 1));
        ss >> index;
        return urls[index];
    }
};