/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "curl_methods.h"

// Kalip Method Curl WriteFunction Secenegi İcin.
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

string send_curl(char *url,char *post_data)
{
    CURL *c;
    
    string response_str;
    
    c = curl_easy_init();
    
    curl_easy_setopt(c,CURLOPT_URL,url);

    curl_easy_setopt(c, CURLOPT_USE_SSL, 0);
    curl_easy_setopt(c,CURLOPT_WRITEFUNCTION,writeFunction);
    curl_easy_setopt(c,CURLOPT_WRITEDATA,&response_str);
    
    curl_easy_setopt(c, CURLOPT_USERAGENT, "curl/7.37.0");
    
    curl_easy_setopt(c, CURLOPT_NOBODY, 0);
    curl_easy_setopt(c, CURLOPT_HEADER, 0);
    curl_easy_setopt(c, CURLOPT_VERBOSE, 0);
	
    if(post_data != "")
    {
        curl_easy_setopt(c,CURLOPT_POST,1);
    
        curl_easy_setopt(c,CURLOPT_POSTFIELDS,post_data);
    }
    else
    {
        curl_easy_setopt(c,CURLOPT_POST,0);
    }
    
    curl_easy_perform(c);
    
    curl_easy_cleanup(c);
    
    return response_str;
}
