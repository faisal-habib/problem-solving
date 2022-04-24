class Solution {
private:
	unordered_map<string, string> mainUrlFromEncodedUrl;
    unordered_map<string, string> encodedUrlFromMainUrl;
	const string charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const string protocolAndHost = "http://tinyurl.com/";
    const int protocolAndHostSize = 19;
    const int pathSize = 6; // we'll make a 6 size url path during encoding longurl
    random_device randomDevice;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
		string codeString = "";

        if (!encodedUrlFromMainUrl.count(longUrl)) {
			char randomChar;
			for(int i = 0; i < pathSize; i++) {
				randomChar = charSet[randomDevice() % charSet.size()];
				codeString += randomChar;
			}

			encodedUrlFromMainUrl[longUrl] = codeString;
			mainUrlFromEncodedUrl[codeString] = longUrl;
		}
		else {
			codeString = encodedUrlFromMainUrl[longUrl];
		}

		return protocolAndHost + codeString;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string codeString = "";
		if (shortUrl.size() != protocolAndHostSize + pathSize) {
			return "";
		}

        codeString = shortUrl.substr(protocolAndHostSize, pathSize);
		if (!mainUrlFromEncodedUrl.count(codeString)) {
			return "";
		}

		return mainUrlFromEncodedUrl[codeString];
    }
};
