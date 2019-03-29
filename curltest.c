#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char **argv)
{
  CURL *c;
  CURLcode res;
  char id[20], email[40], poststr[100];
  if(argc < 3){
		printf("Usage: %s [ID] [email]\n", argv[0]);
		return 1; // Stopped because user havent gave enough information
	}
  sprintf(poststr, "ID=%s&email=%s", argv[1], argv[2]);
  curl_global_init(CURL_GLOBAL_ALL);
  c = curl_easy_init();
	if(c) {
    		curl_easy_setopt(c, CURLOPT_URL, "http://www.cc.puv.fi/~e1800928/curl.php");
    		curl_easy_setopt(c, CURLOPT_POSTFIELDS, poststr);
    		res = curl_easy_perform(c);

	if(res != CURLE_OK)
      		printf("curl_easy_perform() failed");
    	else
		printf("Data is  posted\n");
	curl_easy_cleanup(c);
  }
  curl_global_cleanup();
  return 0;
}
