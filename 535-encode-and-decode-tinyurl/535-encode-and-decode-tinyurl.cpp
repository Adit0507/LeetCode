class Solution {
public:
    unordered_map <string, string> m;
    int length = 6;
    
    string hashing(string longUrl){
        string hashCode="";
        
        for(int i= 0; i < length; i++){
            int random= rand() % 3;
            
            if(random ==1)
                hashCode += ('0' + rand()%10);
            else if(random == 2)
                hashCode += ('a' + rand()%26);
            else
                hashCode += ('A' + rand()% 26);
        }
        
        if(m.find(hashCode) !=m.end())
            return hashing(longUrl);
        else{
            m[hashCode] = longUrl;
            return hashCode;
        }
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tinyUrl = "http://tinyurl.com/";
        string hashCode = hashing(longUrl);
        return tinyUrl + hashCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string hashCode = shortUrl.substr(shortUrl.size() - length, length);
        return m[hashCode];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));