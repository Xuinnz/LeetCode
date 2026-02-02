class Codec:
    def __init__(self):
        self.url_map = {}
        self.base_url = "http:/tinyurl.com/"
        self.counter = 0

    def encode(self, longUrl: str) -> str:
        for key, val in self.url_map.items():
            if val == longUrl:
                return self.base_url + key
        self.counter += 1
        shortKey = str(self.counter)
        self.url_map[shortKey] = longUrl
        return self.base_url + shortKey

    def decode(self, shortUrl: str) -> str:
        shortKey = shortUrl.replace(self.base_url, "")
        return self.url_map.get(shortKey)
        

if __name__ == "__main__":
    # 1. Instantiate the Codec
    obj = Codec()
    
    test_urls = [
        "https://leetcode.com/problems/design-tinyurl",
        "https://www.google.com/search?q=python+classes",
        "https://en.wikipedia.org/wiki/URL_shortening"
    ]

    print(f"{'Original URL':<50} | {'TinyURL'}")
    print("-" * 80)

    for long_url in test_urls:
        # 2. Encode
        tiny = obj.encode(long_url)
        
        # 3. Decode
        original = obj.decode(tiny)
        
        # 4. Verify
        status = "✅" if original == long_url else "❌"
        print(f"{long_url[:47] + '...':<50} | {tiny:<20} {status}")